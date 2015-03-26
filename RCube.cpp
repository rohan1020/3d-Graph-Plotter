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
    
}

RCube::RCube(const RCube &p2)
{
    position = p2.position;
    cube = p2.cube;
}