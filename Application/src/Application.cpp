#include "stdafx.h"

#include "Application.h"

#include "Clipper.h"
#include "PathGenerator.h"
#include "Reader.h"
#include "Triangle.h"


Application::Application(QWidget *parent) : QMainWindow(parent), mMesh(std::vector<Triangle>{}), mClippedMesh(std::vector<Triangle>{})
{
    setupUi();

    connect(mImportSTLButton, &QPushButton::clicked, this, &Application::importSTL);
    connect(mClearDataButton, &QPushButton::clicked, this, &Application::clearData);

    connect(mPushButtonClipMesh, &QPushButton::clicked, this, &Application::clipMeshWithCustomPlane);
    connect(mPushButtonGeneratePath, &QPushButton::clicked, this, &Application::generatePath);

    connect(mPushButtonAddPlane, &QPushButton::clicked, this, &Application::addClippingPlane);

    connect(mPushButtonMoveUp, &QPushButton::clicked, this, &Application::movePlaneUp);
    connect(mPushButtonMoveDown, &QPushButton::clicked, this, &Application::movePlaneDown);

    connect(mPushButtonTiltBack, &QPushButton::clicked, this, &Application::tiltPlaneBack);
    connect(mPushButtonTiltFront, &QPushButton::clicked, this, &Application::tiltPlaneFront);
    connect(mPushButtonTiltLeft, &QPushButton::clicked, this, &Application::tiltPlaneLeft);
    connect(mPushButtonTiltRight, &QPushButton::clicked, this, &Application::tiltPlaneRight);
    
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
}

Application::~Application()
{

}

void Application :: setupUi()
{
    resize(1280, 720);

    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(10, 10, 911, 681));
    setWindowTitle(QCoreApplication::translate("Mesh Clipper", nullptr));


    QFont fontSmall;
    fontSmall.setPointSize(11);

    QFont fontBig;
    fontBig.setPointSize(16);


    mImportSTLButton = new QPushButton("Import STL", this);
    mImportSTLButton->setGeometry(QRect(950, 10, 151, 31));
    mImportSTLButton->setFont(fontSmall);
    mImportSTLButton->setLayoutDirection(Qt::LeftToRight);


    mClearDataButton = new QPushButton("Clear Data", this);
    mClearDataButton->setGeometry(QRect(1110, 10, 151, 31));
    mClearDataButton->setFont(fontSmall);
    mClearDataButton->setLayoutDirection(Qt::LeftToRight);


    mLabelMovePlaneToPoint = new QLabel("Move Plane to Point", this);
    mLabelMovePlaneToPoint->setGeometry(QRect(1010, 110, 187, 41));
    mLabelMovePlaneToPoint->setFont(fontBig);
    mLabelMovePlaneToPoint->setLayoutDirection(Qt::LeftToRight);


    mLabelPointX = new QLabel("X", this);
    mLabelPointX->setGeometry(QRect(945, 150, 51, 31));
    mLabelPointX->setFont(fontSmall);
    mLabelPointX->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointX = new QDoubleSpinBox(this);
    mDoubleSpinBoxPointX->setGeometry(QRect(960, 150, 71, 31));
    mDoubleSpinBoxPointX->setMinimum(-99);
    mDoubleSpinBoxPointX->setLayoutDirection(Qt::LeftToRight);


    mLabelPointY = new QLabel("Y", this);
    mLabelPointY->setGeometry(QRect(1055, 150, 51, 31));
    mLabelPointY->setFont(fontSmall);
    mLabelPointY->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointY = new QDoubleSpinBox(this);
    mDoubleSpinBoxPointY->setGeometry(QRect(1070, 150, 71, 31));
    mDoubleSpinBoxPointY->setMinimum(-99);
    mDoubleSpinBoxPointY->setLayoutDirection(Qt::LeftToRight);


    mLabelPointZ = new QLabel("Z", this);
    mLabelPointZ->setGeometry(QRect(1165, 150, 51, 31));
    mLabelPointZ->setFont(fontSmall);
    mLabelPointZ->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointZ = new QDoubleSpinBox(this);
    mDoubleSpinBoxPointZ->setGeometry(QRect(1180, 150, 71, 31));
    mDoubleSpinBoxPointZ->setMinimum(-99);
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
    mDoubleSpinBoxNormalX->setMinimum(-99);
    mDoubleSpinBoxNormalX->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalY = new QLabel("Y", this);
    mLabelNormalY->setGeometry(QRect(1055, 232, 51, 31));
    mLabelNormalY->setFont(fontSmall);
    mLabelNormalY->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalY = new QDoubleSpinBox(this);
    mDoubleSpinBoxNormalY->setGeometry(QRect(1070, 232, 71, 31));
    mDoubleSpinBoxNormalY->setMinimum(-99);
    mDoubleSpinBoxNormalY->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalZ = new QLabel("Z", this);
    mLabelNormalZ->setGeometry(QRect(1165, 232, 51, 31));
    mLabelNormalZ->setFont(fontSmall);
    mLabelNormalZ->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalZ = new QDoubleSpinBox(this);
    mDoubleSpinBoxNormalZ->setGeometry(QRect(1180, 232, 71, 31));
    mDoubleSpinBoxNormalZ->setMinimum(-99);
    mDoubleSpinBoxNormalZ->setLayoutDirection(Qt::LeftToRight);


    mPushButtonAddPlane = new QPushButton("Add Cliping Plane", this);
    mPushButtonAddPlane->setGeometry(QRect(1030, 290, 151, 31));
    mPushButtonAddPlane->setFont(fontSmall);
    mPushButtonAddPlane->setLayoutDirection(Qt::LeftToRight);

    
    mPushButtonMoveUp = new QPushButton("^", this);
    mPushButtonMoveUp->setGeometry(QRect(1030, 350, 31, 31));
    mPushButtonMoveUp->setFont(fontSmall);
    mPushButtonMoveUp->setLayoutDirection(Qt::LeftToRight);

    mPushButtonMoveDown = new QPushButton("v", this);
    mPushButtonMoveDown->setGeometry(QRect(1030, 390, 31, 31));
    mPushButtonMoveDown->setFont(fontSmall);
    mPushButtonMoveDown->setLayoutDirection(Qt::LeftToRight);


    mPushButtonTiltBack = new QPushButton("^", this);
    mPushButtonTiltBack->setGeometry(QRect(1120, 340, 31, 31));
    mPushButtonTiltBack->setFont(fontSmall);
    mPushButtonTiltBack->setLayoutDirection(Qt::LeftToRight);
               
    mPushButtonTiltFront = new QPushButton("v", this);
    mPushButtonTiltFront->setGeometry(QRect(1120, 400, 31, 31));
    mPushButtonTiltFront->setFont(fontSmall);
    mPushButtonTiltFront->setLayoutDirection(Qt::LeftToRight);
               
    mPushButtonTiltLeft = new QPushButton("<", this);
    mPushButtonTiltLeft->setGeometry(QRect(1090, 370, 31, 31));
    mPushButtonTiltLeft->setFont(fontSmall);
    mPushButtonTiltLeft->setLayoutDirection(Qt::LeftToRight);
               
    mPushButtonTiltRight = new QPushButton(">", this);
    mPushButtonTiltRight->setGeometry(QRect(1150, 370, 31, 31));
    mPushButtonTiltRight->setFont(fontSmall);
    mPushButtonTiltRight->setLayoutDirection(Qt::LeftToRight);


    mLabelPathInterval = new QLabel("Path Interval/Size", this);
    mLabelPathInterval->setGeometry(QRect(1020, 510, 171, 41));
    mLabelPathInterval->setFont(fontBig);
    mLabelPathInterval->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPathInterval = new QDoubleSpinBox(this);
    mDoubleSpinBoxPathInterval->setGeometry(QRect(1020, 550, 161, 31));
    mDoubleSpinBoxPathInterval->setMinimum(1);
    mDoubleSpinBoxPathInterval->setLayoutDirection(Qt::LeftToRight);


    mPushButtonClipMesh = new QPushButton("Clip Mesh", this);
    mPushButtonClipMesh->setGeometry(QRect(950, 640, 151, 31));
    mPushButtonClipMesh->setFont(fontSmall);
    mPushButtonClipMesh->setLayoutDirection(Qt::LeftToRight);


    mPushButtonGeneratePath = new QPushButton("Generate Path", this);
    mPushButtonGeneratePath->setGeometry(QRect(1110, 640, 151, 31));
    mPushButtonGeneratePath->setFont(fontSmall);
    mPushButtonGeneratePath->setLayoutDirection(Qt::LeftToRight);
}

void Application::renderMesh(const Mesh& inMesh) const
{
    QVector<GLfloat> points;
    QVector<GLfloat> colors;

    for (Triangle triangle : inMesh.triangles())
    {
        points.push_back(triangle.p1().x());
        points.push_back(triangle.p1().y());
        points.push_back(triangle.p1().z());

        colors.push_back(1.0);
        colors.push_back(1.0);
        colors.push_back(0.0);


        points.push_back(triangle.p2().x());
        points.push_back(triangle.p2().y());
        points.push_back(triangle.p2().z());

        colors.push_back(1.0);
        colors.push_back(1.0);
        colors.push_back(0.0);


        points.push_back(triangle.p3().x());
        points.push_back(triangle.p3().y());
        points.push_back(triangle.p3().z());

        colors.push_back(1.0);
        colors.push_back(1.0);
        colors.push_back(0.0);
    }

    mRenderer->setVertices(points);
    mRenderer->setColors(colors);
    mRenderer->updateData(points, colors);
}

void Application::importSTL()
{
    QString QfilePath = QFileDialog::getOpenFileName(this, tr("Open STL File"), "", tr("STL Files (*.stl); ; All Files (*)"));

    if (!QfilePath.isEmpty()) {
        std::string filePath = QfilePath.toStdString();

        std::vector<Triangle> triangles;

        Reader reader;
        reader.readSTL(filePath, triangles);

        mMesh = Mesh(triangles);

        renderMesh(mMesh);
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
    mClippedMesh = mClipper.clipMeshWithPlane(mMesh, mPlane);
}

void Application::addClippingPlane()
{
    double planeX = mMesh.BBoxCenterPoint().x();
    double planeY = mMesh.BBoxMinPoint().y();
    double planeZ = mMesh.BBoxCenterPoint().z();

    mPlane.setPlaneNormal(Point3D(0, 1, 0));
    mPlane.movePlaneToPoint(Point3D(planeX, planeY, planeZ));

    clipMesh();
}

void Application::movePlaneUp()
{
    mPlane.moveUp(1.0);
    clipMesh();
    renderMesh(mClippedMesh);
}

void Application::movePlaneDown()
{
    mPlane.moveDown(1.0);
    clipMesh();
    renderMesh(mClippedMesh);
}

void Application::tiltPlaneBack()
{
    mPlane.tiltBack(1.0);
    clipMesh();
    renderMesh(mClippedMesh);
}

void Application::tiltPlaneFront()
{
    mPlane.tiltFront(1.0);
    clipMesh();
    renderMesh(mClippedMesh);
}


void Application::tiltPlaneLeft()
{
    mPlane.tiltLeft(1.0);
    clipMesh();
    renderMesh(mClippedMesh);
}

void Application::tiltPlaneRight()
{
    mPlane.tiltRight(1.0);
    clipMesh();
    renderMesh(mClippedMesh);
}

void Application::clipMeshWithCustomPlane()
{
    double planePointX = mDoubleSpinBoxPointX->value();
    double planePointY = mDoubleSpinBoxPointY->value();
    double planePointZ = mDoubleSpinBoxPointZ->value();

    double planeNormalX = mDoubleSpinBoxNormalX->value();
    double planeNormalY = mDoubleSpinBoxNormalY->value();
    double planeNormalZ = mDoubleSpinBoxNormalZ->value();

    mPlane.movePlaneToPoint(Point3D(planePointX, planePointX, planePointZ));
    mPlane.setPlaneNormal(Point3D(planeNormalX, planeNormalY, planeNormalZ));

    clipMesh();
    renderMesh(mClippedMesh);
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

    mPlane.movePlaneToPoint(Point3D(planePointX, planePointX, planePointZ));
    mPlane.setPlaneNormal(Point3D(planeNormalX, planeNormalY, planeNormalZ));

    Boundary path = mPathGenerator.generatePath(mMesh, mPlane, pathInterval);

    QVector<GLfloat> points;
    QVector<GLfloat> colors;

    for (Point3D point : path.points())
    {
        points.push_back(point.x());
        points.push_back(point.y());
        points.push_back(point.z());

        colors.push_back(1.0);
        colors.push_back(1.0);
        colors.push_back(0.0);
    }

    mRenderer->setVertices(points);
    mRenderer->setColors(colors);
    mRenderer->updateData(points, colors);
}
