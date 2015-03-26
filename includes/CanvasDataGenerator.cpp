//
//  CanvasDataGenerator.cpp
//  2dpaint
//
//  Created by Rohan Raja on 23/03/15.
//
//

#include "CanvasDataGenerator.h"
#include "CanvasStateData.h"
#include "Line.h"
#include "CoordinateSystem.h"
#include "CanvasText.h"
#include <QtGui>

CanvasDataGenerator::CanvasDataGenerator()
{
}

CanvasDataGenerator::CanvasDataGenerator(Range prange, MathFunction pmathFunc):range(prange), mathFunc(pmathFunc)
{
}

CanvasDataGenerator::CanvasDataGenerator(const CanvasDataGenerator const &c2)
{
    mathFunc = c2.mathFunc;
    range = c2.range;
}

CanvasStateData CanvasDataGenerator::changeRange(Range prange)
{
    range = prange;
    return getCanvasStateData();
}

CanvasStateData CanvasDataGenerator::getCanvasStateData()
{
    listOfPoints = range.getAllPoints(mathFunc);
    vector<Line> lines = getPlotLines();
    vector<QRect> rects;    
    
    CanvasStateData csd = *new CanvasStateData(rects, lines);
    csd.width = range.width ;
    csd.height = range.height;
    
    return csd ;
}

vector<Line> CanvasDataGenerator::getPlotLines()
{
    
    vector<Line> lines ;
    
    for (int i=0; i<listOfPoints.size()-1; i++) {
        
        Point p1 = listOfPoints[i];
        Point p2 = listOfPoints[i+1];
        QPoint q1 = range.findQPoint(p1);
        QPoint q2 = range.findQPoint(p2);
        Line l = * new Line(q1,q2,mathFunc.qpen);
        lines.push_back(l);
        
    }
    
    return lines;
    
}

vector<RCube> CanvasDataGenerator::getPlotCubes()
{
    
    vector<RCube> cubes ;
    
    vector<Point> points ;
    
    float curX = range.x_min , curY = range.y_min, curZ;
    float stepSize = range.getStepSize();
    
    while (curX <= range.x_max) {
        
        curY = range.y_min ;
        
        while (curY <= range.y_max) {
            
            curZ = mathFunc.getYVal(curX, curY);
            
            cubes.push_back(* new RCube(*new QGLCube(0.1),*new QVector3D(curX,curY,curZ)));
            
            curY = curY + stepSize ;
            
        }
        
        curX = curX + stepSize ;
        
    }
    
    //
//    
//    // Todo - REmove DUMMY DATA
//    
//    //cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,0,0)));
//    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(2,0,0)));
//    //cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(-2,0,0)));
//    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,2,0)));
//    cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,-2,0)));
    
    return cubes;
    
}

SceneStateData CanvasDataGenerator::getSceneStateData()
{
    SceneStateData ssdata ;
    
    ssdata.cubes = getPlotCubes();
    
    return ssdata;
}



