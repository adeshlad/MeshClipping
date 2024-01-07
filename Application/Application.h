#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Application.h"

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();


public slots:
    void clipMesh();
    void generatePath();
    void openFileDialogBox();


private:
    void setupUi();


private:
    QWidget* mCentralWidget;

    QOpenGLWidget* mOpenGLWidget;

    QPushButton* mSelectFileButton;

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

    QLabel* mLabelPathInterval;

    QDoubleSpinBox* mDoubleSpinBoxPathInterval;

    QPushButton* mPushButtonClipMesh;

    QPushButton* mPushButtonGeneratePath;

    QStatusBar* mStatusBar;
};
