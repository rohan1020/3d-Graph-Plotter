//
//  Line.h
//  2dpaint
//
//  Created by Rohan Raja on 23/03/15.
//
//

#ifndef ___dpaint__Line__
#define ___dpaint__Line__

#include <stdio.h>
#include <QtGui>
#include "Point.h"

class Line {
    
    
public:
    
    Line(int x1, int y1, int x2, int y2, QPen pPen = *new QPen(Qt::black));
    
    Line(QPoint p1,QPoint p2, QPen pPen = *new QPen(Qt::black));
    
    Line(const Line &p2);
    
    Line();
    
    QPen qPen ;
    QLine qLine ;
    QPoint point1, point2;
};

#endif /* defined(___dpaint__Line__) */
