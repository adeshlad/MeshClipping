#include "stdafx.h"
//#include "Triangle.h"
//#include "Clipper.h"
//#include "OpenGLWindow.h"
//
//
//OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) : mBackground(background)
//{
//    setParent(parent);
//    setMinimumSize(720, 550);
//}
//
//OpenGLWindow::~OpenGLWindow()
//{
//    reset();
//}
//
//void OpenGLWindow::reset()
//{
//    makeCurrent();
//    delete mProgram;
//    mProgram = nullptr;
//    delete mVshader;
//    mVshader = nullptr;
//    delete mFshader;
//    mFshader = nullptr;
//    mVbo.destroy();
//    doneCurrent();
//
//    QObject::disconnect(mContextWatchConnection);
//}
//
//void OpenGLWindow::initializeGL()
//{
//    //initializeOpenGLFunctions();
//
//    //static const char* vertexShaderSource =
//    //    "attribute highp vec4 posAttr;\n"
//    //    "attribute lowp vec4 colAttr;\n"
//    //    "varying lowp vec4 col;\n"
//    //    "uniform highp mat4 matrix;\n"
//    //    "void main() {\n"
//    //    "   col = colAttr;\n"
//    //    "   gl_Position = matrix * posAttr;\n"
//    //    "}\n";
//
//    //static const char* fragmentShaderSource =
//    //    "varying lowp vec4 col;\n"
//    //    "void main() {\n"
//    //    "   gl_FragColor = col;\n"
//    //    "}\n";
//
//    //initializeOpenGLFunctions();
//
//    //mProgram = new QOpenGLShaderProgram(this);
//    //mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
//    //mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
//    //mProgram->link();
//    //m_posAttr = mProgram->attributeLocation("posAttr");
//    //Q_ASSERT(m_posAttr != -1);
//    //m_colAttr = mProgram->attributeLocation("colAttr");
//    //Q_ASSERT(m_colAttr != -1);
//    //m_matrixUniform = mProgram->uniformLocation("matrix");
//    //Q_ASSERT(m_matrixUniform != -1);
//}
//
//
//void OpenGLWindow::mouseMoveEvent(QMouseEvent* event) {
//    int dx = event->x() - lastPos.x();
//    int dy = event->y() - lastPos.y();
//
//    if (event->buttons() & Qt::LeftButton) {
//        QQuaternion rotX = QQuaternion::fromAxisAndAngle(0.0f, 1.0f, 0.0f, 0.5f * dx);
//        QQuaternion rotY = QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, 0.5f * dy);
//
//        rotationAngle = rotX * rotY * rotationAngle;
//        update();
//    }
//    lastPos = event->pos();
//}
//
//void OpenGLWindow::clipMesh(Mesh inMesh, Plane inPlane)
//{
//    Clipper clipper;
//
//    Mesh clippedMesh = clipper.clipMeshWithPlane(inMesh, inPlane);
//
//    for (Triangle triangle : clippedMesh.triangles())
//    {
//        mVertices.push_back(triangle.p1().x());
//        mVertices.push_back(triangle.p1().y());
//        mVertices.push_back(triangle.p1().z());
//
//        mColors << 1 << 1 << 1;
//
//        mVertices.push_back(triangle.p2().x());
//        mVertices.push_back(triangle.p2().y());
//        mVertices.push_back(triangle.p2().z());
//
//        mColors << 1 << 1 << 1;
//
//        mVertices.push_back(triangle.p3().x());
//        mVertices.push_back(triangle.p3().y());
//        mVertices.push_back(triangle.p3().z());
//
//        mColors << 1 << 1 << 1;
//    }
//
//    emit shapeUpdate;
//}
//
//void OpenGLWindow::generatePath(Mesh inMesh, Plane inPlane, double inSize)
//{
//
//}