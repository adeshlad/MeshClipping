#pragma once

#include "Point3D.h"
#include "Plane.h"
#include "Mesh.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <vector>


class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

signals:
    void shapeUpdate();


public:
//    OpenGLWindow(const QColor& background, QMainWindow* parent);
//    ~OpenGLWindow();
//    void mouseMoveEvent(QMouseEvent* event);
//
//
//public:
//    void clipMesh(Mesh inMesh, Plane inPlane);
//    void generatePath(Mesh inMesh, Plane inPlane, double inSize);
//
//
//protected:
//    void paintGL() override;
//    void initializeGL() override;


private:
    //void reset();

private:
    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
    QVector<QVector2D> mPixelVertices;
    QVector<GLfloat> curveVertices;
    QVector<GLfloat> curveColors;
    QQuaternion rotationAngle;
    QPoint lastPos;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
};