#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QObject>
#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
     ~MyGLWidget();

protected:
    void initializeGL();
    void resizeGL(int w,int h);
    void paintGL();

    void keyPressEvent(QKeyEvent *event);

    void loadGLTextures();
private:
    bool fullScreen;
    GLfloat rTri;
    GLfloat rQuad;
    GLuint texture[1];
    GLfloat xRot,yRot,zRot;
};

#endif // MYGLWIDGET_H
