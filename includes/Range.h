//
//  Range.h
//  OpenSoftpt
//
//  Created by Rohan Raja on 18/03/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#ifndef __OpenSoftpt__Range__
#define __OpenSoftpt__Range__

#include <stdio.h>
#include <vector>
#include "Point.h"
#include "Line.h"
#include "MathFunction.h"
#include "CanvasStateData.h"

using namespace std;

class Range
{
    
    
    
public:
    /* X-Y Range Params */
    
    float x_min, x_max ;
    float y_min, y_max ;
    
    /* Scaling Params */
    
    int pixelsPerPoint_X = 5; // Pixels - Constant Parameter
    int pixelsPerPoint_Y = 10; // Pixels - Constant Parameter
    
    int height = 600 ; // Pixels
    int width = 900 ; // Pixels
    
    /* Coordinate System Params - AUTOCALCULATED */
    QPoint center;
    float pixelsPerUnit_X , pixelsPerUnit_Y ;  // 1 unit = x pixels
    Line x_axis, y_axis ;
    
    /* Methods */
    
    Range();
    
    void setParams(float px_min,float px_max,float py_min,float py_max, int pwidth, int pheight );
    
    int getNumPoints_Y();
    
    int getNumPoints_X();
    
    float getStepSize();
    
    vector<Point> getAllPoints(MathFunction &mathFunc);
    
    QPoint findQPoint(Point p);
    
    void calculateCoordinateSystem();
    
    
    vector<float> getXTicksList();
    vector<float> getYTicksList();
    
    CanvasStateData getGridCanvasData();
    
    void moveCoordinate(float val, int type);
    
    void zoom(float val, int type);
    
};



#endif /* defined(__OpenSoftpt__Range__) */
