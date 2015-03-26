//
//  CanvasDataGenerator.h
//  2dpaint
//
//  Created by Rohan Raja on 23/03/15.
//
//

#ifndef ___dpaint__CanvasDataGenerator__
#define ___dpaint__CanvasDataGenerator__

#include <iostream>
#include <vector>
#include "MathFunction.h"
#include "Range.h"
#include "Point.h"
#include "CanvasStateData.h"
#include "Line.h"

using namespace std;


class CanvasDataGenerator
{
    Range range ;
    vector<Point> listOfPoints ;
    MathFunction mathFunc ;
    
    
public:
    
    CanvasDataGenerator();
    
    CanvasDataGenerator(const CanvasDataGenerator const &c2);
    
    CanvasStateData getCanvasStateData();
    
    CanvasDataGenerator(Range prange, MathFunction pmathFunc);
    
    CanvasStateData changeRange(Range prange);
    
    vector<Line> getPlotLines();
    
    
   
};


#endif /* defined(___dpaint__CanvasDataGenerator__) */
