//
//  MeshPainter.cpp
//  graphics
//
//  Created by Rohan Raja on 28/03/15.
//
//

#include "MeshPainter.h"
#include "qglview.h"
#include "qglteapot.h"

#include <QtGui/QApplication>
#include "qglbuilder.h"
#include "qglcube.h"
#include <iostream>

void MeshPainter::setSceneData(vector<RCube> pCubes)
{
    cubes = pCubes;
    repaint();
}

MeshPainter::MeshPainter(vector<RCube> pCubes, QWidget *parent)
: QGLView(parent)
, m_rootNode(0), cubes(pCubes)
{
    
    QGLBuilder builder;
    
    builder << QGL::Faceted ; //<< QGLCube(1) ;
    
    builder<< * new QGLCube(0.1);
    builder.currentNode()->setPosition(*new QVector3D(0,0,0));
    
    m_rootNode = builder.finalizedSceneNode();
    
    // Setup the camera
    //camera()->setEye(* new QVector3D(5,5,30));
    camera()->setFieldOfView(45);
    camera()->setNearPlane(1);
    camera()->setFarPlane(500);

}

MeshPainter::~MeshPainter()
{
    delete m_rootNode;
}

void MeshPainter::initializeGL(QGLPainter *painter)
{
    QGLLightParameters *lightParameters = new QGLLightParameters(this);
    QGLMaterial *material = new QGLMaterial(this);
    QColor color;
    
    // Setup the lighting for the scene
    painter->setStandardEffect(QGL::LitMaterial);
    color.setRgbF(0.2, 0.2, 0.2, 1.0);
    lightParameters->setAmbientColor(color);
    color.setRgbF(1.0, 1.0, 1.0, 1.0);
    lightParameters->setSpecularColor(color);
    lightParameters->setDirection(QVector3D(0.0, 50.0, 50.0));
    painter->setMainLight(lightParameters);
    
    // Apply a material
    color.setRgbF(1.0, 1.0, 1.0, 1.0);
    material->setSpecularColor(color);
    material->setShininess(60);
    color.setRgbF(0.0, 0.0, 1.0, 1.0);
    material->setAmbientColor(color);
    material->setDiffuseColor(color);
    painter->setFaceMaterial(QGL::AllFaces, material);
}



void MeshPainter::paintGL(QGLPainter *painter)
{
    painter->setStandardEffect(QGL::LitMaterial);
    
    QVector2DArray vertices;
    
    QVector3DArray normals, vertices2;
    
    //QVector<QColor> colors;
   
    QArray<QColor4ub> colors;
    //QArray<QColor> colors ;
    
    QRect rect(0,0,8,8);
    
    int step = qMin(rect.width() / 8, rect.height() / 8);
    int midx = rect.x() + rect.width() / 2;
    int midy = rect.y() + rect.height() / 2;
    
    vertices.append(midx - step, midy + step);
    vertices.append(midx + step * 2, midy + step * 2);
    vertices.append(midx + step * 2, midy);
    vertices.append(midx + step, midy - step);
    vertices.append(midx - step, midy - step * 2);
    
//    vertices2.append(0,0,0);
//    vertices2.append(0,1,0);
//    vertices2.append(2,2,5);
//    vertices2.append(1,0,0);
//    vertices2.append(0,0,0);
    
    for(int i=0; i<cubes.size(); i++)
    {
        vertices2.append(cubes[i].position.x(), cubes[i].position.y(), cubes[i].position.z());
        normals.append(0, 0, 1);
        
        
        
        colors.push_back(* new QColor4ub(cubes[i].color));
        //colors[i].
        
    }
//    
//    normals.append(0.0f, 0.0f, 1.0f);
//    normals.append(0.0f, 0.0f, 1.0f);
//    normals.append(0.0f, 0.0f, 1.0f);
//    normals.append(0.0f, 0.0f, 1.0f);
//    normals.append(0.0f, 0.0f, 1.0f);
//    //normals.append(0.0f, 0.0f, 1.0f);
    
    painter->clearAttributes();
    painter->setVertexAttribute(QGL::Position, vertices2);
    painter->setVertexAttribute(QGL::Normal, normals);
    painter->setVertexAttribute(QGL::Color, colors);

    
    //painter->draw(QGL::TriangleFan, cubes.size());
    
    m_rootNode->draw(painter);
    
    // Overpaint some lines to show the triangle boundaries.
    painter->clearAttributes();
    painter->setStandardEffect(QGL::FlatPerVertexColor);
    //painter->setColor(QColor(202, 170, 0));
//    static ushort const indices[] = {0, 2, 0, 3};
    painter->setVertexAttribute(QGL::Position, vertices2);
    painter->setVertexAttribute(QGL::Color, colors);
    
    painter->draw(QGL::Points, cubes.size());
    
    painter->modelViewMatrix().translate(0.0, 0.0, 0);
    
}