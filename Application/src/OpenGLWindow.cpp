#include "stdafx.h"

#include "OpenGLWindow.h"

#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include <iostream>


OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) : mBackground(background)
{
    setParent(parent);
    setMinimumSize(550, 450);

    mVertice = QVector<GLfloat>{0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
    mColor = QVector<GLfloat>{ 1, 1 ,1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1 };
}


OpenGLWindow::~OpenGLWindow()
{
    reset();
}


void OpenGLWindow::reset()
{
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();
    QObject::disconnect(mContextWatchConnection);
}


void OpenGLWindow::setVertices(QVector<GLfloat>& vertices)
{
    mVertice = vertices;
    update();
}

void OpenGLWindow::setColors(QVector<GLfloat>& colors)
{
    mColor = colors;
    update();
}


void OpenGLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();
    QMatrix4x4 matrix;
    matrix.ortho(-100.0f * scaleFactor, 100.0f * scaleFactor, -100.0f * scaleFactor, 100.0f * scaleFactor, 0.00000000001f, 1000000.0f);
    matrix.translate(0, 0, -15);
    matrix.rotate(rotationAngle);
    //matrix.scale(scaleFactor);

    mProgram->setUniformValue(m_matrixUniform, matrix);

    GLfloat* verticesData = mVertice.data();
    GLfloat* colorsData = mColor.data();

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);

    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

    glEnableVertexAttribArray(m_posAttr);

    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_LINES, 0, mVertice.size() / 3);
    //glDrawArrays(GL_TRIANGLES, 0, mVertice.size() / 3);
    //glDrawArrays(GL_QUADS, 0, mVertice.size() / 3);
}

void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors)
{
    mVertice = vertices;
    mColor = colors;
    update();
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent* event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if (event->buttons() & Qt::LeftButton)
    {
        QQuaternion rotX = QQuaternion::fromAxisAndAngle(0.0f, 1.0f, 0.0f, 0.5f * dx);
        QQuaternion rotY = QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, 0.5f * dy);

        rotationAngle = rotX * rotY * rotationAngle;
        update();
    }
    lastPos = event->pos();
}

void OpenGLWindow::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() > 0)
    {
        zoomOut();
    }
    else
    {
        zoomIn();
    }
}

void OpenGLWindow::zoomIn()
{
    scaleFactor *= 1.1f;
    update();
}

void OpenGLWindow::zoomOut()
{
    scaleFactor /= 1.1f;
    update();
}

void OpenGLWindow::initializeGL()
{
    static const char* vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";
    
    static const char* fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

    rotationAngle = QQuaternion::fromAxisAndAngle(0.0f, 0.0f, 1.0f, 0.0f);

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();

    m_posAttr = mProgram->attributeLocation("posAttr");
    m_colAttr = mProgram->attributeLocation("colAttr");

    m_matrixUniform = mProgram->uniformLocation("matrix");

    if (m_posAttr == -1 || m_colAttr == -1 || m_matrixUniform == -1) {
        qDebug() << "Shader attribute or uniform location error.";
    }
}
