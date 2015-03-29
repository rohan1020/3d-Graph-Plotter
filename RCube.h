//
//  RCube.h
//  graph3d
//
//  Created by Rohan Raja on 26/03/15.
//
//

#ifndef __graph3d__RCube__
#define __graph3d__RCube__

#include <stdio.h>
#include "qglcube.h"
#include "qglview.h"


class RCube {
    

public:
    
    RCube();
    RCube(QGLCube pcube, QVector3D pposition);
    RCube(QGLCube pcube, QVector3D pposition, QGLMaterial *pmaterial);
    RCube(const RCube &p2);

    QGLCube cube ;
    QVector3D position;
    QGLMaterial *material;
    QColor color;
    

};

#endif /* defined(__graph3d__RCube__) */
