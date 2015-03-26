
#include <QtGui/QApplication>
//#include "../qmlres.h"

#include "GLView.h"
#include "RCube.h"
#include <vector>;

#include "includes/CanvasDataGenerator.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    CanvasDataGenerator cdg;
    
    SceneStateData ssd = cdg.getSceneStateData();
    

    GLView view(ssd.cubes);
    //view.setSceneData(cubes);
    //view.setWindowTitle(QObject::tr("Tetrahedron"));
    //view.resize(300, 300);
    view.show();


    return app.exec();
}
