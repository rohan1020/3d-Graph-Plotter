//
//  MathFunction.cpp
//  OpenSoftpt
//
//  Created by Rohan Raja on 18/03/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "MathFunction.h"
#include <QtGui>
#include <iostream>
#include<cmath>
#include"expparser/parser.h"

using namespace std;

MathFunction::MathFunction()
{
    
}


MathFunction::MathFunction(string pfuncTxt, QPen pPen): funcTxt(pfuncTxt), qpen(pPen)
{
}


float MathFunction::getYVal(float x)
{
    Parser prs;
    
    string temp = "x=" + to_string(x); //
    prs.parse(temp.c_str());
    
    prs.parse(funcTxt.c_str());
    
    return prs.ans;
    
//    if(isSin == 1)
//        return cos(x) ;
//    else
//        return x*x*x;
}