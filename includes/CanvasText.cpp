//
//  CanvasText.cpp
//  2dpaint
//
//  Created by Rohan Raja on 24/03/15.
//
//

#include "CanvasText.h"

CanvasText::CanvasText(string ptxt, QRect pRect):txt(ptxt), rect(pRect)
{
    
}

CanvasText::CanvasText(){
    
}

CanvasText::CanvasText(const CanvasText &c2)
{
    rect = c2.rect ;
    txt = c2.txt ;
}