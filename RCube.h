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
    RCube(const RCube &p2);

    QGLCube cube ;
    QVector3D position;
    

};

#endif /* defined(__graph3d__RCube__) */
