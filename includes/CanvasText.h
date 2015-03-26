//
//  CanvasText.h
//  2dpaint
//
//  Created by Rohan Raja on 24/03/15.
//
//

#ifndef ___dpaint__CanvasText__
#define ___dpaint__CanvasText__

#include <stdio.h>
#include<string>
#include <QtGui>

using namespace std;

class CanvasText
{
    
public:
    
    CanvasText();
    CanvasText(string ptxt, QRect pRect);
    CanvasText(const CanvasText &c2);
    
    string txt;
    QRect rect ;
    
};

#endif /* defined(___dpaint__CanvasText__) */
