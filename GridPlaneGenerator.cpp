//
//  GridPlaneGenerator.cpp
//  graphics
//
//  Created by Rohan Raja on 27/03/15.
//
//

#include "GridPlaneGenerator.h"
#include "CanvasDataGenerator.h"
#include "MathFunction.h"

GridPlaneGenerator::GridPlaneGenerator()
{
    
}
GridPlaneGenerator::GridPlaneGenerator(Range r):range(r)
{
    
}
SceneStateData GridPlaneGenerator::getXYPlane()
{
    
    CanvasDataGenerator cdg(range, * new MathFunction("0")) ;
    
    vector<RCube> cubes;
    
    cubes = cdg.getPlotCubes();
    
        //cubes.push_back(* new RCube(*new QGLCube(0.2),*new QVector3D(0,0,0)));
        //cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(2,0,0)));
        //cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(-2,0,0)));
        //cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,2,0)));
        //cubes.push_back(* new RCube(*new QGLCube(1),*new QVector3D(0,-2,0)));
    
    QColor color2 ;//= getColorVal(curZ);
    color2.setRgbF(0, 1, 0);
    QGLMaterial *material2 = new QGLMaterial;
    material2->setColor(color2);
    material2->setShininess(30);
    
    for(int i=0; i<cubes.size(); i++)
    {
        cubes[i].material = material2;
    }
    
    SceneStateData toRet;
    toRet.cubes = cubes;
    
    return toRet;
    
    
}