//
//  Point.cpp
//  OpenSoftpt
//
//  Created by Rohan Raja on 19/03/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "Point.h"
#include <iostream>

Point::Point()
{
    
}

Point::Point(float px, float py)
{
    x = px;
    y = py;
}


std::ostream& operator<< (std::ostream& os, const Point& p)
{
    os << "(" << p.x <<"," << p.y << ")";
    return os;
}
