#include "GLView.h"
 #include "qglview.h"
 #include "qglteapot.h"

#include <QtGui/QApplication>
#include "qglbuilder.h"
#include "qglcube.h"
#include <iostream>

void GLView::setSceneData(vector<RCube> pCubes)
{
    cubes = pCubes;
    repaint();
}

GLView::GLView(vector<RCube> pCubes, QWidget *parent)
    : QGLView(parent)
    , m_rootNode(0), cubes(pCubes)
{
    
    
    
    // Create the cube
    QGLBuilder builder;
    
    builder << QGL::Faceted ; //<< QGLCube(1) ;
    
    // Drawing the cubes
    
    QColor color2 = * new QColor(1,1,1);
    QColor color3 = * new QColor(1,1,1);
    QGLMaterial *material2 = new QGLMaterial;
    QGLMaterial *material3 = new QGLMaterial;
    color2.setRgbF(0, 1, 0);
    material2->setColor(color2);
    material2->setShininess(0);
    color3.setRgbF(1, 0, 0);
    material3->setColor(color3);
    material3->setShininess(0);
    
    QGLMaterial *materialmain ;
    
    for(int i=0; i<cubes.size(); i++)
    {
        builder.newNode()->setObjectName(QLatin1String("pixel3d"));
        builder<< cubes[i].cube;
        builder.currentNode()->setPosition(cubes[i].position);
        builder.currentNode()->setMaterial(cubes[i].material);
    }

    
    m_rootNode = builder.finalizedSceneNode();
    
    // Setup the camera
    camera()->setEye(* new QVector3D(5,5,30));
    camera()->setFieldOfView(45);
    camera()->setNearPlane(1);
    camera()->setFarPlane(500);
}
 
GLView::~GLView()
{
    delete m_rootNode;
}
 
void GLView::initializeGL(QGLPainter *painter)
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
 
void GLView::paintGL(QGLPainter *painter)
{
    
    
    // Perform some transformations
    painter->modelViewMatrix().translate(0.0, 0.0, 0);
//    painter->modelViewMatrix().rotate(15.0, 1.0, 0.0, 0.0);
//    painter->modelViewMatrix().rotate(30.0, 0.0, 1.0, 0.0);
//    painter->modelViewMatrix().rotate(15.0, 0.0, 0.0, 1.0);
 
    // Draw the cube
    m_rootNode->draw(painter);
}