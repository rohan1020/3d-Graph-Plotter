//
//  GridPlaneGenerator.h
//  graphics
//
//  Created by Rohan Raja on 27/03/15.
//
//

#ifndef __graphics__GridPlaneGenerator__
#define __graphics__GridPlaneGenerator__

#include <stdio.h>
#include "RCube.h"
#include <vector>
#include "Range.h"
#include "SceneStateData.h"

class GridPlaneGenerator {
    
    Range range;
    
public:
    
    GridPlaneGenerator();
    
    GridPlaneGenerator(Range r);
    
    SceneStateData getXYPlane();
    
    
};
#endif /* defined(__graphics__GridPlaneGenerator__) */
