#ifndef CANVAS_STATE
#define CANVAS_STATE

#include <QWidget>
#include "CanvasStateData.h"

class CanvasState : public QWidget
{
    Q_OBJECT

public:
    CanvasState(QWidget *parent, CanvasStateData &value);
    void setPrintData(CanvasStateData value);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QString printData;
    float dcx;
    float pcx;
    int width, height;
    CanvasStateData canvasStateData ;
    
};


#endif