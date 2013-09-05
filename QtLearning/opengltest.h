#ifndef OPENGLTEST_H
#define OPENGLTEST_H
#include <QGLWidget>
#include <QWheelEvent>
#include "math.h"
#include <iostream>

class OpenGLTest: public QGLWidget
{
    Q_OBJECT
private:
    int glW;
    int glH;


protected:
    virtual void initializeGL(){
        qglClearColor(Qt::black);
    }

    virtual void resizeGL(int w, int h){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, w, h);
        glOrtho(0, glW, glH, 0, -5, 1);// !
    }

    virtual void paintGL(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
        //glVertex2i(0, glH);
        glVertex3i(0, glH, -2);  // !
        glColor3f(0, 1, 0);
        glVertex2i(glW, glH);
        glColor3f(0, 0, 1);
        glVertex2i(glW, 0);
        glColor3f(1, 1, 1);
        glVertex2i(0, 0);
        glEnd();

        glColor3f(.0, .0, .0);

        draw(100, 100, GL_POINTS);
        draw(100, 250, GL_LINES);
        draw(100, 400, GL_LINE_STRIP);
        draw(300, 100, GL_LINE_LOOP);
        draw(300, 250, GL_TRIANGLES);
        draw(300, 400, GL_QUADS);
    }

    virtual void wheelEvent(QWheelEvent *e){
        glMatrixMode(GL_MODELVIEW);
        std::cout<<"wheel "<<e->delta()<<std::endl;
        if(e->delta() > 0)
            glTranslated(1, 0, 0);
        else
            glTranslated(-1, 0, 0);
        updateGL();
    }

private:
    void draw(int offX, int offY, GLenum type){
        int pointCount = 8;
        int R = 50;
        glBegin(type);
        for(int i = 0; i < pointCount; ++i){
            double angle = 2.0 * M_PI * i / pointCount;
            double x = offX + cos(angle) * R;
            double y = offY + sin(angle) * R;
            glVertex2d(x, y);
        }


        glEnd();
    }


public:
    OpenGLTest(){
        glW = 500;
        glH = 500;

    }
};

#endif // OPENGLTEST_H
