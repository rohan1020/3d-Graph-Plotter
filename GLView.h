#ifndef Q_GLView
#define Q_GLView


#include <QtGui/QApplication>

 #include "qglview.h"
 #include "qglteapot.h"
#include "qglbuilder.h"
#include "qglcube.h"
#include<vector>

class QGLSceneNode;

 
class GLView : public QGLView
{
    Q_OBJECT
 
public:
    GLView(QWidget *parent = 0);
    ~GLView();
 
protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);
 
private:
    QGLSceneNode *m_rootNode;
    
};


#endif // Q_GLView