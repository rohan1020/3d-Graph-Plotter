//
//  Point.h
//  OpenSoftpt
//
//  Created by Rohan Raja on 19/03/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#ifndef __OpenSoftpt__Point__
#define __OpenSoftpt__Point__

#include <stdio.h>
#include <iostream>

class Point{
    
public:
    
    float x = 0, y = 0, z;
    
    Point();
    
    Point(float px, float py);
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    
};

#endif
