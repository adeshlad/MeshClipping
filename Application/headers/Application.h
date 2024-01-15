#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Application.h"

#include "Clipper.h"
#include "Mesh.h"
#include "PathGenerator.h"
#include "Plane.h"
#include "OpenGLWindow.h"

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();


public slots:
    void importSTL();
    void clearData();

    void addClippingPlane();
    void clipMesh();

    void movePlaneUp();
    void movePlaneDown();

    void tiltPlaneBack();
    void tiltPlaneFront();
    void tiltPlaneLeft();
    void tiltPlaneRight();

    void clipMeshWithCustomPlane();
    void generatePath();


private:
    void setupUi();
    void renderMesh(const Mesh& inMesh) const;

private:
    QWidget* mCentralWidget;

    OpenGLWindow* mRenderer;

    QPushButton* mImportSTLButton;
    QPushButton* mClearDataButton;

    QLabel* mLabelMovePlaneToPoint;

    QLabel* mLabelPointX;
    QLabel* mLabelPointY;
    QLabel* mLabelPointZ;

    QDoubleSpinBox* mDoubleSpinBoxPointX;
    QDoubleSpinBox* mDoubleSpinBoxPointY;
    QDoubleSpinBox* mDoubleSpinBoxPointZ;

    QLabel* mLabelSetPlaneNormal;

    QLabel* mLabelNormalX;
    QLabel* mLabelNormalY;
    QLabel* mLabelNormalZ;

    QDoubleSpinBox* mDoubleSpinBoxNormalX;
    QDoubleSpinBox* mDoubleSpinBoxNormalY;
    QDoubleSpinBox* mDoubleSpinBoxNormalZ;

    QPushButton* mPushButtonAddPlane;

    QPushButton* mPushButtonMoveUp;
    QPushButton* mPushButtonMoveDown;

    QPushButton* mPushButtonTiltBack;
    QPushButton* mPushButtonTiltFront;
    QPushButton* mPushButtonTiltLeft;
    QPushButton* mPushButtonTiltRight;

    QLabel* mLabelPathInterval;

    QDoubleSpinBox* mDoubleSpinBoxPathInterval;

    QPushButton* mPushButtonClipMesh;

    QPushButton* mPushButtonGeneratePath;

    QStatusBar* mStatusBar;

    Clipper mClipper;

    Mesh mMesh;

    Mesh mClippedMesh;

    PathGenerator mPathGenerator;

    Plane mPlane;
};
