#include "stdafx.h"
#include "Application.h"
#include "Triangle.h"
#include "Reader.h"
#include "Clipper.h"
#include "PathGenerator.h"


Application::Application(QWidget *parent) : QMainWindow(parent), mMesh(std::vector<Triangle>{})
{
    setupUi();

    connect(mSelectFileButton, &QPushButton::clicked, this, &Application::openFileDialogBox);
    connect(mClearDataButton, &QPushButton::clicked, this, &Application::clearData);

    connect(mPushButtonClipMesh, &QPushButton::clicked, this, &Application::clipMesh);
    connect(mPushButtonGeneratePath, &QPushButton::clicked, this, &Application::generatePath);
    
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));

}

Application::~Application()
{

}

void Application :: setupUi()
{
    resize(1280, 720);

    //mRenderer = new OpenGLWindow(this);

    //mOpenGLWidget = new QOpenGLWidget(mCentralWidget);
    //mOpenGLWidget->setGeometry(QRect(10, 10, 911, 681));

    //mCentralWidget = new QWidget(ApplicationClass);
    //mCentralWidget->setObjectName("CentralWidget");

    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(10, 10, 911, 681));
    setWindowTitle(QCoreApplication::translate("Mesh Clipper", nullptr));


    QFont fontSmall;
    fontSmall.setPointSize(11);

    QFont fontBig;
    fontBig.setPointSize(16);


    mSelectFileButton = new QPushButton("Import STL", this);
    mSelectFileButton->setGeometry(QRect(950, 10, 151, 31));
    mSelectFileButton->setFont(fontSmall);
    mSelectFileButton->setLayoutDirection(Qt::LeftToRight);


    mClearDataButton = new QPushButton("Clear Data", this);
    mClearDataButton->setGeometry(QRect(1110, 10, 151, 31));
    mClearDataButton->setFont(fontSmall);
    mClearDataButton->setLayoutDirection(Qt::LeftToRight);


    mLabelMovePlaneToPoint = new QLabel("Move Plane to Point", this);
    mLabelMovePlaneToPoint->setGeometry(QRect(1010, 81, 187, 41));
    mLabelMovePlaneToPoint->setFont(fontBig);
    mLabelMovePlaneToPoint->setLayoutDirection(Qt::LeftToRight);


    mLabelPointX = new QLabel("X", this);
    mLabelPointX->setGeometry(QRect(945, 121, 51, 31));
    mLabelPointX->setFont(fontSmall);
    mLabelPointX->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointX = new QDoubleSpinBox(this);
    mDoubleSpinBoxPointX->setGeometry(QRect(960, 121, 71, 31));
    mDoubleSpinBoxPointX->setMinimum(-999);
    mDoubleSpinBoxPointX->setLayoutDirection(Qt::LeftToRight);


    mLabelPointY = new QLabel("Y", this);
    mLabelPointY->setGeometry(QRect(1055, 121, 51, 31));
    mLabelPointY->setFont(fontSmall);
    mLabelPointY->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointY = new QDoubleSpinBox(this);
    mDoubleSpinBoxPointY->setGeometry(QRect(1070, 121, 71, 31));
    mDoubleSpinBoxPointY->setMinimum(-999);
    mDoubleSpinBoxPointY->setLayoutDirection(Qt::LeftToRight);


    mLabelPointZ = new QLabel("Z", this);
    mLabelPointZ->setGeometry(QRect(1165, 121, 51, 31));
    mLabelPointZ->setFont(fontSmall);
    mLabelPointZ->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointZ = new QDoubleSpinBox(this);
    mDoubleSpinBoxPointZ->setGeometry(QRect(1180, 121, 71, 31));
    mDoubleSpinBoxPointZ->setMinimum(-999);
    mDoubleSpinBoxPointZ->setLayoutDirection(Qt::LeftToRight);


    mLabelSetPlaneNormal = new QLabel("Set Plane Normal", this);
    mLabelSetPlaneNormal->setGeometry(QRect(1020, 192, 171, 41));
    mLabelSetPlaneNormal->setFont(fontBig);
    mLabelSetPlaneNormal->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalX = new QLabel("X", this);
    mLabelNormalX->setGeometry(QRect(945, 232, 51, 31));
    mLabelNormalX->setFont(fontSmall);
    mLabelNormalX->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalX = new QDoubleSpinBox(this);
    mDoubleSpinBoxNormalX->setGeometry(QRect(960, 232, 71, 31));
    mDoubleSpinBoxNormalX->setMinimum(-999);
    mDoubleSpinBoxNormalX->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalY = new QLabel("Y", this);
    mLabelNormalY->setGeometry(QRect(1055, 232, 51, 31));
    mLabelNormalY->setFont(fontSmall);
    mLabelNormalY->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalY = new QDoubleSpinBox(this);
    mDoubleSpinBoxNormalY->setGeometry(QRect(1070, 232, 71, 31));
    mDoubleSpinBoxNormalY->setMinimum(-999);
    mDoubleSpinBoxNormalY->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalZ = new QLabel("Z", this);
    mLabelNormalZ->setGeometry(QRect(1165, 232, 51, 31));
    mLabelNormalZ->setFont(fontSmall);
    mLabelNormalZ->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalZ = new QDoubleSpinBox(this);
    mDoubleSpinBoxNormalZ->setGeometry(QRect(1180, 232, 71, 31));
    mDoubleSpinBoxNormalZ->setMinimum(-999);
    mDoubleSpinBoxNormalZ->setLayoutDirection(Qt::LeftToRight);


    mLabelPathInterval = new QLabel("Path Interval/Size", this);
    mLabelPathInterval->setGeometry(QRect(1020, 301, 171, 41));
    mLabelPathInterval->setFont(fontBig);
    mLabelPathInterval->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPathInterval = new QDoubleSpinBox(this);
    mDoubleSpinBoxPathInterval->setGeometry(QRect(1020, 341, 161, 31));
    mDoubleSpinBoxPathInterval->setMinimum(1);
    mDoubleSpinBoxPathInterval->setLayoutDirection(Qt::LeftToRight);


    mPushButtonClipMesh = new QPushButton("Clip Mesh", this);
    mPushButtonClipMesh->setGeometry(QRect(950, 431, 151, 31));
    mPushButtonClipMesh->setFont(fontSmall);
    mPushButtonClipMesh->setLayoutDirection(Qt::LeftToRight);


    mPushButtonGeneratePath = new QPushButton("Generate Path", this);
    mPushButtonGeneratePath->setGeometry(QRect(1110, 431, 151, 31));
    mPushButtonGeneratePath->setFont(fontSmall);
    mPushButtonGeneratePath->setLayoutDirection(Qt::LeftToRight);

    //this->setCentralWidget(this);
}

void Application::openFileDialogBox()
{
    QString QfilePath = QFileDialog::getOpenFileName(this, tr("Open STL File"), "", tr("STL Files (*.stl); ; All Files (*)"));

    if (!QfilePath.isEmpty()) {
        std::string filePath = QfilePath.toStdString();

        std::vector<Triangle> triangles;

        Reader reader;
        reader.readSTL(filePath, triangles);

        mMesh = Mesh(triangles);

        QVector<GLfloat> points;
        QVector<GLfloat> colors;

        for (Point3D point : mMesh.points())
        {
            points.push_back(point.x());
            points.push_back(point.y());
            points.push_back(point.z());

            colors.push_back(1.0);
            colors.push_back(1.0);
            colors.push_back(1.0);
        }
        
        mRenderer->setVertices(points);
        mRenderer->setColors(colors);
        mRenderer->updateData(points, colors);
    }
}

void Application::clearData()
{
    QVector<GLfloat> points;
    QVector<GLfloat> colors;

    mRenderer->setVertices(points);
    mRenderer->setColors(colors);
    mRenderer->updateData(points, colors);
}

void Application::clipMesh()
{
    double planePointX = mDoubleSpinBoxPointX->value();
    double planePointY = mDoubleSpinBoxPointY->value();
    double planePointZ = mDoubleSpinBoxPointZ->value();

    double planeNormalX = mDoubleSpinBoxNormalX->value();
    double planeNormalY = mDoubleSpinBoxNormalY->value();
    double planeNormalZ = mDoubleSpinBoxNormalZ->value();

    Plane plane;
    plane.movePlaneToPoint(Point3D(planePointX, planePointX, planePointZ));
    plane.setPlaneNormal(Point3D(planeNormalX, planeNormalY, planeNormalZ));

    Clipper clipper;

    Mesh clippedMesh = clipper.clipMeshWithPlane(mMesh, plane);

    QVector<GLfloat> points;
    QVector<GLfloat> colors;

    for (Point3D point : clippedMesh.points())
    {
        points.push_back(point.x());
        points.push_back(point.y());
        points.push_back(point.z());

        colors.push_back(1.0);
        colors.push_back(1.0);
        colors.push_back(1.0);
    }

    mRenderer->setVertices(points);
    mRenderer->setColors(colors);
    mRenderer->updateData(points, colors);
}

void Application::generatePath()
{
    double planePointX = mDoubleSpinBoxPointX->value();
    double planePointY = mDoubleSpinBoxPointY->value();
    double planePointZ = mDoubleSpinBoxPointZ->value();

    double planeNormalX = mDoubleSpinBoxNormalX->value();
    double planeNormalY = mDoubleSpinBoxNormalY->value();
    double planeNormalZ = mDoubleSpinBoxNormalZ->value();

    double pathInterval = mDoubleSpinBoxPathInterval->value();

    Plane plane;
    plane.movePlaneToPoint(Point3D(planePointX, planePointX, planePointZ));
    plane.setPlaneNormal(Point3D(planeNormalX, planeNormalY, planeNormalZ));

    PathGenerator pathGenerator;

    Boundary path = pathGenerator.generatePath(mMesh, plane, pathInterval);

    QVector<GLfloat> points;
    QVector<GLfloat> colors;

    for (Point3D point : path.points())
    {
        points.push_back(point.x());
        points.push_back(point.y());
        points.push_back(point.z());

        colors.push_back(1.0);
        colors.push_back(1.0);
        colors.push_back(1.0);
    }

    mRenderer->setVertices(points);
    mRenderer->setColors(colors);
    mRenderer->updateData(points, colors);
}

