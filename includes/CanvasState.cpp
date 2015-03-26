#include <QtGui>
#include "CanvasState.h"
#include "CanvasStateData.h"


CanvasState::CanvasState(QWidget *parent, CanvasStateData &value)
    : QWidget(parent), canvasStateData(value)
{    
    setFixedSize(canvasStateData.width, canvasStateData.height);
}

void CanvasState::paintEvent(QPaintEvent *event)
{
    // Painter Initialization
    Q_UNUSED(event);
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);


    // Drawing Rectangles
    for(int i=0; i<canvasStateData.rects.size(); i++)
    {
        painter.drawRect(canvasStateData.rects[i]);
    }

    // Drawing Lines
    for(int i=0; i<canvasStateData.lines.size(); i++)
    {
        painter.setPen(canvasStateData.lines[i].qPen);
        painter.drawLine(canvasStateData.lines[i].qLine);
    }
    
    painter.setPen(Qt::black);
    
    // Drawing Texts
    for(int i=0; i<canvasStateData.texts.size(); i++)
    {
        painter.drawText(canvasStateData.texts[i].rect, Qt::AlignCenter, canvasStateData.texts[i].txt.c_str());
    }
    
        
    // Painter Ending
    painter.end();

}

void CanvasState::setPrintData(CanvasStateData value){
   
   canvasStateData = value ;
    
    repaint();
}



