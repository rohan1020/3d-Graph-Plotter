//
//  Line.cpp
//  2dpaint
//
//  Created by Rohan Raja on 23/03/15.
//
//

#include "Line.h"
#include <stdio.h>
#include <QtGui>

Line::Line(int x1, int y1, int x2, int y2, QPen pPen)
{
    qPen = pPen;
    qLine = * new QLine(x1, y1, x2, y2);
}

Line::Line(QPoint p1,QPoint p2, QPen pPen):point1(p1), point2(p2)
{
    qPen = pPen;
    qLine = * new QLine(p1.x(), p1.y(),p2.x(), p2.y());
    
}

Line::Line(const Line &p2)
{
    qPen = p2.qPen;
    qLine = p2.qLine;
}

Line::Line(){
    
}
