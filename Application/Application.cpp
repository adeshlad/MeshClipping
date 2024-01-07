#include "stdafx.h"
#include "Application.h"
#include "Triangle.h"
#include "Reader.h"


Application::Application(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();

    // to do - add connects
}

Application::~Application()
{

}

void Application :: setupUi()
{
    resize(1280, 720);

    mCentralWidget = new QWidget(this);

    mOpenGLWidget = new QOpenGLWidget(mCentralWidget);
    mOpenGLWidget->setGeometry(QRect(10, 10, 911, 681));


    QFont fontSmall;
    fontSmall.setPointSize(11);

    QFont fontBig;
    fontBig.setPointSize(16);


    mSelectFileButton = new QPushButton("Import STL", mCentralWidget);
    mSelectFileButton->setGeometry(QRect(950, 10, 151, 31));
    mSelectFileButton->setFont(fontSmall);
    mSelectFileButton->setLayoutDirection(Qt::LeftToRight);


    mLabelMovePlaneToPoint = new QLabel("Move Plane to Point", mCentralWidget);
    mLabelMovePlaneToPoint->setGeometry(QRect(1020, 81, 171, 41));
    mLabelMovePlaneToPoint->setFont(fontBig);
    mLabelMovePlaneToPoint->setLayoutDirection(Qt::LeftToRight);


    mLabelPointX = new QLabel("X", mCentralWidget);
    mLabelPointX->setGeometry(QRect(945, 121, 51, 31));
    mLabelPointX->setFont(fontSmall);
    mLabelPointX->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointX = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBoxPointX->setGeometry(QRect(960, 121, 71, 31));
    mDoubleSpinBoxPointX->setLayoutDirection(Qt::LeftToRight);


    mLabelPointY = new QLabel("Y", mCentralWidget);
    mLabelPointY->setGeometry(QRect(1055, 121, 51, 31));
    mLabelPointY->setFont(fontSmall);
    mLabelPointY->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointY = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBoxPointY->setGeometry(QRect(1070, 121, 71, 31));
    mDoubleSpinBoxPointY->setLayoutDirection(Qt::LeftToRight);


    mLabelPointZ = new QLabel("Z", mCentralWidget);
    mLabelPointZ->setGeometry(QRect(1165, 121, 51, 31));
    mLabelPointZ->setFont(fontSmall);
    mLabelPointZ->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPointZ = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBoxPointZ->setGeometry(QRect(1180, 121, 71, 31));
    mDoubleSpinBoxPointZ->setLayoutDirection(Qt::LeftToRight);


    mLabelSetPlaneNormal = new QLabel("Set Plane Normal", mCentralWidget);
    mLabelSetPlaneNormal->setGeometry(QRect(1020, 192, 171, 41));
    mLabelSetPlaneNormal->setFont(fontBig);
    mLabelSetPlaneNormal->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalX = new QLabel("X", mCentralWidget);
    mLabelNormalX->setGeometry(QRect(945, 232, 51, 31));
    mLabelNormalX->setFont(fontSmall);
    mLabelNormalX->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalX = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBoxNormalX->setGeometry(QRect(960, 232, 71, 31));
    mDoubleSpinBoxNormalX->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalY = new QLabel("Y", mCentralWidget);
    mLabelNormalY->setGeometry(QRect(1055, 232, 51, 31));
    mLabelNormalY->setFont(fontSmall);
    mLabelNormalY->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalY = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBoxNormalY->setGeometry(QRect(1070, 232, 71, 31));
    mDoubleSpinBoxNormalY->setLayoutDirection(Qt::LeftToRight);


    mLabelNormalZ = new QLabel("Z", mCentralWidget);
    mLabelNormalZ->setGeometry(QRect(1165, 232, 51, 31));
    mLabelNormalZ->setFont(fontSmall);
    mLabelNormalZ->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxNormalZ = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBoxNormalZ->setGeometry(QRect(1180, 232, 71, 31));
    mDoubleSpinBoxNormalZ->setLayoutDirection(Qt::LeftToRight);


    mLabelPathInterval = new QLabel("Path Interval/Size", mCentralWidget);
    mLabelPathInterval->setGeometry(QRect(1020, 301, 171, 41));
    mLabelPathInterval->setFont(fontBig);
    mLabelPathInterval->setLayoutDirection(Qt::LeftToRight);

    mDoubleSpinBoxPathInterval = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBoxPathInterval->setGeometry(QRect(1020, 341, 161, 31));
    mDoubleSpinBoxPathInterval->setLayoutDirection(Qt::LeftToRight);


    mPushButtonClipMesh = new QPushButton("Clip Mesh", mCentralWidget);
    mPushButtonClipMesh->setGeometry(QRect(950, 431, 151, 31));
    mPushButtonClipMesh->setFont(fontSmall);
    mPushButtonClipMesh->setLayoutDirection(Qt::LeftToRight);


    mPushButtonGeneratePath = new QPushButton("Generate Path", mCentralWidget);
    mPushButtonGeneratePath->setGeometry(QRect(1110, 431, 151, 31));
    mPushButtonGeneratePath->setFont(fontSmall);
    mPushButtonGeneratePath->setLayoutDirection(Qt::LeftToRight);

    this->setCentralWidget(mCentralWidget);
}

void Application::clipMesh()
{
    double planePointX = mDoubleSpinBoxPointX->value();
    double planePointY = mDoubleSpinBoxPointY->value();
    double planePointZ = mDoubleSpinBoxPointZ->value();

    double planeNormalX = mDoubleSpinBoxNormalX->value();
    double planeNormalY = mDoubleSpinBoxNormalY->value();
    double planeNormalZ = mDoubleSpinBoxNormalZ->value();

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

}

void Application::openFileDialogBox()
{
    QString QfilePath = QFileDialog::getOpenFileName(this, tr("Open STL File"), "", tr("STL Files (*.stl); ; All Files (*)"));

    if (!QfilePath.isEmpty()) {
        std::string filePath = QfilePath.toStdString();

        std::vector<Triangle> triangles;

        Reader reader;
        reader.readSTL(filePath, triangles);

        //mRenderer->processTriangles(triangles);
        //trianglesData = triangles;

        //emit mRenderer->shapeUpdate();
    }
}