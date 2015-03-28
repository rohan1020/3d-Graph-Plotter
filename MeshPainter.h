//
//  MeshPainter.h
//  graphics
//
//  Created by Rohan Raja on 28/03/15.
//
//

#ifndef __graphics__MeshPainter__
#define __graphics__MeshPainter__

#include <stdio.h>

#include <QtGui/QApplication>

#include "qglview.h"
#include "qglteapot.h"
#include "qglbuilder.h"
#include "qglcube.h"
#include<vector>
#include "RCube.h"

class QGLSceneNode;

using namespace std;

class MeshPainter : public QGLView
{
    Q_OBJECT
    
public:
    MeshPainter(vector<RCube> pCubes = * new vector<RCube>(), QWidget *parent = 0);
    ~MeshPainter();
    
    void setSceneData(vector<RCube> pCubes);
    
    
    vector<RCube> cubes;
    
protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);
    
    
private:
    QGLSceneNode *m_rootNode;
    
};



#endif /* defined(__graphics__MeshPainter__) */
