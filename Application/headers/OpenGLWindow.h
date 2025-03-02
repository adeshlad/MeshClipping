#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>


class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OpenGLWindow(const QColor& background, QMainWindow* parent);
    ~OpenGLWindow();

    void setVertices(QVector<GLfloat>& vertices);
    void setColors(QVector<GLfloat>& colors);
    void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors);

protected:
    void initializeGL() override;
    void paintGL() override;

private:
    void mouseMoveEvent(QMouseEvent* event);
    void reset();
    void wheelEvent(QWheelEvent* event);
    void zoomIn();
    void zoomOut();

private:
    bool mAnimating = false;
    int mFlag = 0;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    QList<QVector3D> mVertices;
    QList<QVector3D> mNormals;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    QVector<GLfloat> mVertice;
    QVector<GLfloat> mColor;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_posAttr1 = 0;
    GLint m_colAttr1 = 0;
    GLint m_matrixUniform = 0;

    QQuaternion rotationAngle;
    QPoint lastPos;
    float scaleFactor = 5;
};
