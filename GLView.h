#ifndef Q_GLView
#define Q_GLView


#include <QtGui/QApplication>

 #include "qglview.h"
 #include "qglteapot.h"
#include "qglbuilder.h"
#include "qglcube.h"
#include<vector>
#include "RCube.h"

class QGLSceneNode;

using namespace std;
 
class GLView : public QGLView
{
    Q_OBJECT
 
public:
    GLView(vector<RCube> pCubes = * new vector<RCube>(), QWidget *parent = 0);
    ~GLView();
    
    void setSceneData(vector<RCube> pCubes);

    
    vector<RCube> cubes;
 
protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);
    
 
private:
    QGLSceneNode *m_rootNode;
    
};


#endif // Q_GLView