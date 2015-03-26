
#include <QtGui/QApplication>
//#include "../qmlres.h"

#include "GLView.h"
#include "RCube.h"
#include <vector>;

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    vector<RCube> cubes ;
    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,0,0)));
    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(2,0,0)));
    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(-2,0,0)));
    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,2,0)));
    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,-2,0)));
    

    GLView view(cubes);
    //view.setSceneData(cubes);
    //view.setWindowTitle(QObject::tr("Tetrahedron"));
    //view.resize(300, 300);
    view.show();


    return app.exec();
}
