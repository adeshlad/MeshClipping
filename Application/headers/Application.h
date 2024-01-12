#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Application.h"

#include "Mesh.h"
#include "OpenGLWindow.h"

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();


public slots:
    void openFileDialogBox();
    void clearData();

    //void moveUp();
    //void moveDown();

    //void tiltUp();
    //void tiltDown();
    //void tiltLeft();
    //void tiltRigth();

    void clipMesh();
    void generatePath();


private:
    void setupUi();


private:
    QWidget* mCentralWidget;

    OpenGLWindow* mRenderer;

    QPushButton* mSelectFileButton;
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

    QPushButton* mPushButtonTiltUp;
    QPushButton* mPushButtonTiltDown;
    QPushButton* mPushButtonTiltLeft;
    QPushButton* mPushButtonTiltRight;

    QLabel* mLabelPathInterval;

    QDoubleSpinBox* mDoubleSpinBoxPathInterval;

    QPushButton* mPushButtonClipMesh;

    QPushButton* mPushButtonGeneratePath;

    QStatusBar* mStatusBar;

    Mesh mMesh;
};
