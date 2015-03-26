//
//  Range.cpp
//  OpenSoftpt
//
//  Created by Rohan Raja on 18/03/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "Range.h"
#include <QtGui>


Range::Range()
{
    x_min = -3.14*2 ;
    x_max = 3.14*2 ;
    
    y_min = -5 ;
    y_max = 5 ;
    
    calculateCoordinateSystem();
    
}

void Range::setParams(float px_min,float px_max,float py_min,float py_max, int pwidth, int pheight )
{
    x_min = px_min;
    x_max = px_max;
    y_min = py_min;
    y_max = py_max;
    width = pwidth;
    height = pheight;
    
    calculateCoordinateSystem();

}

void Range::calculateCoordinateSystem()
{
    pixelsPerUnit_X = width / (x_max - x_min) ;
    pixelsPerUnit_Y = height / (y_max - y_min);
    
    center = * new QPoint(-1*x_min*pixelsPerUnit_X, y_max*pixelsPerUnit_Y);
    
    x_axis = * new Line(*new QPoint(0,center.y()), *new QPoint(width,center.y()));
    
    y_axis = * new Line(*new QPoint(center.x(),0), *new QPoint(center.x(),height));
}

int Range::getNumPoints_Y()
{
    return height/pixelsPerPoint_Y ;
}

int Range::getNumPoints_X()
{
    return width/pixelsPerPoint_X ;
}

float Range::getStepSize()
{
    int numX = getNumPoints_X();
    float rangeNum = x_max - x_min ;
    return rangeNum/numX ;
}

vector<Point> Range::getAllPoints(MathFunction &mathFunc)
{
    vector<Point> points ;
    
    float curX = x_min , curY;
    float stepSize = getStepSize();
    
    while (curX <= x_max) {
        curY = mathFunc.getYVal(curX);
        points.push_back(* new Point(curX, curY));
        
        curX = curX + stepSize ;
    }
    
    return points;
}

QPoint Range::findQPoint(Point p)
{
    int x , y ;
    x = center.x() + p.x*pixelsPerUnit_X;
    y = center.y() - p.y*pixelsPerUnit_Y;
    return * new QPoint(x,y);
}

void Range::moveCoordinate(float val, int type)
{
    switch (type) {
        case 0:
            x_min = x_min + val;
            x_max = x_max + val;
            break;
            
        case 1:
            x_min = x_min - val;
            x_max = x_max - val;
            break;
            
        case 2:
            y_min = y_min - val;
            y_max = y_max - val;
            break;
            
        case 3:
            y_min = y_min + val;
            y_max = y_max + val;
            break;
            
        default:
            break;
    }
    
    calculateCoordinateSystem();
}

void Range::zoom(float val, int type)
{
    
    // ToDo : Add check case if x_max < x_min, then do something
    
    switch (type) {
        case 0:
            x_min = x_min + val;
            x_max = x_max - val;
            break;
            
        case 1:
            x_min = x_min - val;
            x_max = x_max + val;
            break;
            
        case 2:
            y_min = y_min + val;
            y_max = y_max - val;
            break;
            
        case 3:
            y_min = y_min - val;
            y_max = y_max + val;
            break;
            
        default:
            break;
    }
    
    calculateCoordinateSystem();
}

CanvasStateData Range::getGridCanvasData()
{
    vector<Line> lines;
    vector<QRect> rects;
    vector<CanvasText> txts;
    
    lines.push_back(x_axis); // X-Axis
    lines.push_back(y_axis); // Y-Axis
    rects.push_back(* new QRect(0,0,width, height)); //Main Box
    
    int RECT_WIDTH = 40, RECT_HEIGHT = 40, LINE_WIDTH = 10;
    
    vector<float> xticks = getXTicksList();
    
    for(int i=0; i<xticks.size(); i++)
    {
        float num = xticks[i];
    
        int rect_x = findQPoint(* new Point(num,0)).x() - (RECT_WIDTH/2);
        
        int rect_y = center.y();
        
        QRect axisRect(rect_x,rect_y,RECT_WIDTH,RECT_WIDTH);
        
        char msg[10];
        
        sprintf(msg, "%.4g", num );
        CanvasText axisNum(msg, axisRect);
        
        QPoint axis_p1(findQPoint(* new Point(num,0)).x(), center.y() - LINE_WIDTH/2);
        
        QPoint axis_p2(findQPoint(* new Point(num,0)).x(), center.y() + LINE_WIDTH/2);
        
        Line axisLine(axis_p1,axis_p2);
        
        txts.push_back(axisNum);
        lines.push_back(axisLine);
    
    }
    
    vector<float> yticks = getYTicksList();
    
    for(int i=0; i<yticks.size(); i++)
    {
        float num = yticks[i];
        
        int rect_y = findQPoint(* new Point(0,num)).y() - (RECT_HEIGHT/2);
        
        int rect_x = center.x();
        
        QRect axisRect(rect_x,rect_y,RECT_WIDTH,RECT_WIDTH);
        
        char msg[10];
        
        sprintf(msg, "%.4g", num );
        CanvasText axisNum(msg, axisRect);
        
        QPoint axis_p1(center.x() - LINE_WIDTH/2,findQPoint(* new Point(0,num)).y());
        
        QPoint axis_p2(center.x() + LINE_WIDTH/2,findQPoint(* new Point(0,num)).y());
        
        Line axisLine(axis_p1,axis_p2);
        
        txts.push_back(axisNum);
        lines.push_back(axisLine);
        
    }
    
    //rects.push_back(axisRect);
    
    CanvasStateData csd = *new CanvasStateData(rects, lines,txts);
    csd.width = width ;
    csd.height = height;
    
    return csd ;
}


vector<float> Range::getXTicksList()
{
    vector<float> ans ;
    
    int curX = x_min, curY, stepSize = 1;
    
    while (curX <= x_max) {
        if(curX==0.0)
        {
            curX = curX + stepSize;
            continue;
        }
        ans.push_back(curX);
        curX = curX + stepSize ;
    }
    
    return ans ;
}

vector<float> Range::getYTicksList()
{
    vector<float> ans ;
    
    int curX = y_min, curY, stepSize = 1;
    
    while (curX <= y_max) {
        
        if(curX==0.0)
        {
            curX = curX + stepSize;
            continue;
        }
        
        ans.push_back(curX);
        curX = curX + stepSize ;
    }
    
    return ans ;
    
}

