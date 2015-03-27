//
//  RCube.cpp
//  graph3d
//
//  Created by Rohan Raja on 26/03/15.
//
//

#include "RCube.h"


RCube::RCube(QGLCube pcube, QVector3D pposition): cube(pcube), position(pposition)
{
    material = new QGLMaterial();
    QColor qc;
    qc.setRgbF(1, 1, 1);
    material->setColor(qc);
}


RCube::RCube(QGLCube pcube, QVector3D pposition, QGLMaterial *pmaterial): cube(pcube), position(pposition), material(pmaterial)
{
    
}

RCube::RCube(const RCube &p2)
{
    position = p2.position;
    cube = p2.cube;
    material = p2.material;
}