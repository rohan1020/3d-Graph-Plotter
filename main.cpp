
#include <QtGui/QApplication>
//#include "../qmlres.h"

#include "GLView.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GLView view;
    //view.setWindowTitle(QObject::tr("Tetrahedron"));
    //view.resize(300, 300);
    view.show();


    return app.exec();
}
