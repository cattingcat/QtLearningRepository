#ifndef OPENGL3DTEST_H
#define OPENGL3DTEST_H
#include <QGLWidget>
#include <QMouseEvent>

class OpenGL3DTest: public QGLWidget
{
    Q_OBJECT
private:
    int glW;
    int glH;
    GLuint _dPyramid;
    GLfloat _xRotate;
    GLfloat _yRotate;
    QPoint _point;
    GLfloat _r;


protected:
    virtual void initializeGL(){
        qglClearColor(Qt::black);
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_FLAT);
        _dPyramid = createPyramid(1.2f);
    }

    virtual void resizeGL(int w, int h){
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);

    }

    virtual void paintGL(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -4.0);
        glRotatef(_xRotate, 1.0, 0.0, 0.0);
        glRotatef(_yRotate, 0.0, 1.0, 0.0);

        glCallList(_dPyramid);
    }

    GLuint createPyramid(GLfloat sz = 1.0f){
        GLuint res = glGenLists(1);
        glNewList(res, GL_COMPILE);

        glBegin(GL_TRIANGLE_FAN);
        qglColor(Qt::green);
        glVertex3f(.0, sz, .0);
        glVertex3f(-sz, -sz, sz);
        glVertex3f(sz, -sz, sz);
        qglColor(Qt::yellow);
        glVertex3f(sz, -sz, -sz);
        qglColor(Qt::blue);
        glVertex3f(-sz, -sz, -sz);
        qglColor(Qt::white);
        glVertex3f(-sz, -sz, sz);
        glEnd();

        glBegin(GL_QUADS);
        qglColor(Qt::red);
        glVertex3f(-sz, -sz, sz);
        glVertex3f(sz, -sz, sz);
        glVertex3f(sz, -sz, -sz);
        glVertex3f(-sz, -sz, -sz);
        glEnd();

        glEndList();

        return res;
    }


    void mousePressEvent(QMouseEvent *e){
        _point = e->pos();
    }
    void mouseMoveEvent(QMouseEvent *e){
        _xRotate += 180*(GLfloat)(e->y() - _point.y())/height();
        _yRotate += 180*(GLfloat)(e->x() - _point.x())/width();
        updateGL();
        _point = e->pos();
    }

    virtual void wheelEvent(QWheelEvent *e){
        //glMatrixMode(GL_MODELVIEW);

        if(e->delta() > 0){
            _r += .1;
        }else{
            _r -= .1;
        }
        updateGL();
    }

public:
    OpenGL3DTest(){
        glW = 500;
        glH = 500;
    }
};

#endif // OPENGL3DTEST_H
