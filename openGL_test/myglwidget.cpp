#include "myglwidget.h"
#include <QtGui>
#include <QKeyEvent>
#include <QGLWidget>
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glu.h>
#include <GL/gl.h>

MyGLWidget::MyGLWidget(QWidget *parent):QGLWidget(parent)
{
    fullScreen =false;
    rTri = 0.0;
    rQuad = 0.0;
    setGeometry(50,50,640,480);
    setWindowTitle("Rotation");
    xRot = yRot =zRot =0;
    texture[0] = 0;
    if(fullScreen)
        showFullScreen();
}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::initializeGL()
{
    glClearColor(0.0,0.0,0.0,0.0); //Dark backgroung  R G B Alpha

//    loadGLTextures();
//    glEnable(GL_TEXTURE_2D);

    glShadeModel(GL_SMOOTH);       //阴影平滑

    glClearDepth(1.0);              //深度缓存
    glEnable(GL_DEPTH_TEST);        //启用深度测试
    glDepthFunc(GL_LEQUAL);         //所做深度测试的类型
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);//进行透视矫正
}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w,(GLint)h); //重置当前窗口
    glMatrixMode(GL_PROJECTION);       //选择投影矩阵
    glLoadIdentity();                   //重置投影矩阵

    //设置窗口大小
    gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);     //选择模型为观察矩阵
    glLoadIdentity();                //重置模型观察矩阵
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //清除屏幕和深度缓存
    glLoadIdentity();           // 重置当前的观察模型

    glTranslatef(-1.5f,0.0f,-6.0f);
    glRotatef(rTri,1.0,0.0,0.0);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,1.0,0.0 );
        glVertex3f(-1.0,-1.0,1.0);
        glColor3f( 0.0,0.0,1.0);
        glVertex3f(1.0,-1.0,1.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0,-1.0,-1.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0,-1.0,-1.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,1.0);

    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0f,-1.0f,1.0f);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(1.0f,-1.0f,1.0f);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(1.0f,-1.0f,-1.0f);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0f,-1.0f,-1.0f);
    glEnd();


    glLoadIdentity();

    glTranslatef(1.5,0.0,-7.0);
    glRotatef(rQuad,1.0,1.0,1.0);
    glColor3f(0.5,0.5,1.0);

    glBegin(GL_QUADS);
    //up
        glColor3f( 1.0, 0.0, 0.0 );
        glVertex3f(  1.0,  1.0, -1.0 );
        glColor3f( 0.0, 1.0, 0.0 );
        glVertex3f( -1.0,  1.0, -1.0 );
        glColor3f( 0.0, 0.0, 1.0 );
        glVertex3f( -1.0,  1.0,  1.0 );
        glColor3f( 1.0, 0.5, 0.0 );
        glVertex3f(  1.0,  1.0,  1.0 );
    //down
        glColor3f( 1.0, 0.5, 0.0 );
        glVertex3f(  1.0, -1.0,  1.0 );
        glVertex3f( -1.0, -1.0,  1.0 );
        glVertex3f( -1.0, -1.0, -1.0 );
        glVertex3f(  1.0, -1.0, -1.0 );
    //fore
        glColor3f( 1.0, 0.5, 0.0 );
        glVertex3f(  1.0,  1.0,  1.0 );
        glColor3f( 0.0, 0.0, 1.0 );
        glVertex3f( -1.0,  1.0,  1.0 );
        glVertex3f( -1.0, -1.0,  1.0 );
        glVertex3f(  1.0, -1.0,  1.0 );
    //back
        glColor3f( 0.0, 1.0, 0.0 );
        glVertex3f(  1.0, -1.0, -1.0 );
        glColor3f( 1.0, 0.0, 0.0 );
        glVertex3f( -1.0, -1.0, -1.0 );
        glVertex3f( -1.0,  1.0, -1.0 );
        glVertex3f(  1.0,  1.0, -1.0 );
    //left
        glColor3f( 0.0, 0.0, 1.0 );
        glVertex3f( -1.0,  1.0,  1.0 );
        glColor3f( 0.0, 1.0, 0.0 );
        glVertex3f( -1.0,  1.0, -1.0 );
        glVertex3f( -1.0, -1.0, -1.0 );
        glVertex3f( -1.0, -1.0,  1.0 );
    //right
        glColor3f( 1.0, 0.0, 0.0 );
        glVertex3f(  1.0,  1.0, -1.0 );
        glColor3f( 1.0, 0.5, 0.0 );
        glVertex3f(  1.0,  1.0,  1.0 );
        glVertex3f(  1.0, -1.0,  1.0 );
        glVertex3f(  1.0, -1.0, -1.0 );
    glEnd();

    rTri += 10;
    rQuad -= 15;
//    glTranslatef(0.0,0.0,-5.0);
//    glRotated(xRot,1.0,0.0,0.0);
//    glRotated(yRot,0.0,1.0,0.0);
//    glRotated(zRot,0.0,0.0,1.0);

//    glBindTexture(GL_TEXTURE_2D,texture[0]);

//    glBegin(GL_QUADS);
//        glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
//        glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
//        glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
//        glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );

//        glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
//        glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
//        glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
//        glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );

//        glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
//        glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0,  1.0,  1.0 );
//        glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0,  1.0,  1.0 );
//        glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );

//        glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0, -1.0, -1.0 );
//        glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0, -1.0, -1.0 );
//        glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
//        glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );

//        glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
//        glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
//        glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
//        glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );

//        glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
//        glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
//        glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
//        glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );


//        glEnd();

//        xRot += 0.3;
//        yRot += 0.2;
//        zRot += 0.4;
}

void MyGLWidget::loadGLTextures()
{
    QImage tex,buf;
    if(!buf.load(":/image/ToolSwitch.bmp"))
    {
        qWarning("Could net read image file , using single-color instead.");
        QImage dumy(28,28,QImage::Format_RGB32);
        dumy.fill(Qt::green);
        buf = dumy;
    }

    tex = QGLWidget::convertToGLFormat(buf);
    glGenTextures(1,&texture[0]);
    glBindTexture(GL_TEXTURE_2D,texture[0]);

    glTexImage2D(GL_TEXTURE_2D,0,3,tex.width(),tex.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,tex.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_F1:
        fullScreen = !fullScreen;
        if(fullScreen)
            showFullScreen();
        else
            showNormal();

        updateGL();

        break;

    case Qt::Key_Escape:
        close();
        break;

    case Qt::Key_F2:
        updateGL();
        break;
    default:
        break;
    }
}
