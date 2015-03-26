#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include "CanvasState.h"
#include "CanvasStateData.h"
#include "MainCanvas.h"
#include <string>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

    void redrawCanvasData(CanvasStateData cdata);
    
    void addFunction(string funcTxt);
    
    void addNewFunc(QString s);
    
private:
    int numRows;
    CanvasState *gobject;
    CanvasStateData canvasData ;
    MainCanvas mainCanvas ;
    
    QPushButton *up;
    QPushButton *down;
    QPushButton *left;
    QPushButton *right;
    QPushButton *zin;
    QPushButton *zout;
    QPushButton *zin_y;
    QPushButton *zout_y;
    
    QListWidget *funcView;
    QPushButton *newButton;
    QPushButton *delButton;
    QPushButton *screenButton;
    QVector<QString> myList;
    QVector<QColor> myList_cols;
    QGridLayout *funcList;
    
    private slots:
    void UpSlot();
    void DownSlot();
    void LeftSlot();
    void RightSlot();
    void ZinSlot();
    void ZoutSlot();
    void ZinSlot_y();
    void ZoutSlot_y();
    void NewSlot();
    void DeleteSlot();
    void ScreenSlot();
    
    
    
    //void NewSlot();
   
};

#endif