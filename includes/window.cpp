#include <QtGui>
//#include "widget.h"
#include "CanvasState.h"
#include "window.h"
#include "CanvasStateData.h"
#include "MainCanvas.h"
#include "FunctionInputWindow.h"

Window::Window() : QWidget(), numRows(0)
{
    
//    QDialog *dialog = new QDialog;
//    dialog->setWindowTitle("Dialog");
//    dialog->show();
    
    
    funcView = new QListWidget(this);
    funcView->setMaximumWidth(300);
    canvasData = mainCanvas.calculateCanvasData();
    
    gobject = new CanvasState(this, canvasData);
    
    mainCanvas.canvas = gobject;
    
    left = new QPushButton("<", this);
    connect(left, SIGNAL(clicked()), this, SLOT(LeftSlot()));
    right = new QPushButton(">", this);
    connect(right, SIGNAL(clicked()), this, SLOT(RightSlot()));
    up = new QPushButton("Up", this);
    connect(up, SIGNAL(clicked()), this, SLOT(UpSlot()));
    down = new QPushButton("Down", this);
    connect(down, SIGNAL(clicked()), this, SLOT(DownSlot()));
    zin = new QPushButton("X+", this);
    connect(zin, SIGNAL(clicked()), this, SLOT(ZinSlot()));
    zout = new QPushButton("X-", this);
    connect(zout, SIGNAL(clicked()), this, SLOT(ZoutSlot()));
    
    zin_y = new QPushButton("Y+", this);
    connect(zin_y, SIGNAL(clicked()), this, SLOT(ZinSlot_y()));
    zout_y = new QPushButton("Y-", this);
    connect(zout_y, SIGNAL(clicked()), this, SLOT(ZoutSlot_y()));
    
    newButton = new QPushButton("Add New Function", this);
    connect(newButton, SIGNAL(clicked()), this, SLOT(NewSlot()));
    delButton = new QPushButton("Delete Function", this);
    connect(delButton, SIGNAL(clicked()), this, SLOT(DeleteSlot()));
    screenButton = new QPushButton("Screenshot", this);
    connect(screenButton, SIGNAL(clicked()), this, SLOT(ScreenSlot()));
    
    QLabel *topLab = new QLabel("<h3>Functions : </h3>");
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    QVBoxLayout *vlayout2 = new QVBoxLayout;
    QGridLayout *layout = new QGridLayout;
    //QGridLayout *layout = new QGridLayout;
    
    layout->addWidget(up, 0, 1);
    layout->addWidget(left, 1, 0);
    layout->addWidget(gobject, 1, 1);
    layout->addWidget(right, 1, 2);
    layout->addWidget(zin, 2, 0);
    layout->addWidget(down, 2, 1);
    layout->addWidget(zout, 2, 2);
    
    layout->addWidget(zin_y, 0, 0);
    layout->addWidget(zout_y, 0, 2);
    
    //vlayout2->addWidget(up);
    vlayout2->addLayout(layout);
    //vlayout2->addWidget(down);
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(topLab);
    vlayout->addWidget(funcView);
    vlayout->addWidget(newButton);
    vlayout->addWidget(delButton);
    vlayout->addWidget(screenButton);
    
    hlayout->addLayout(vlayout);
    hlayout->addLayout(vlayout2);
    
    setLayout(hlayout);
    
    //setLayout(layout);
    
    setWindowTitle(tr("2d-Plotter"));
    
    FunctionInputWindow *fiw = new FunctionInputWindow;
    fiw->setWindowTitle("Input Function");
    fiw->show();
    fiw->window = this;
    
}

void Window::redrawCanvasData(CanvasStateData cdata)
{
    canvasData = cdata;
    gobject->setPrintData(canvasData);
    
}

void Window::addFunction(string funcTxt)
{
    QColor newCol = mainCanvas.addFunction(funcTxt);
    myList.push_back(*new QString(("y = " + funcTxt).c_str()));
    myList_cols.push_back(newCol);
    funcView->addItem(*new QString(("y = " + funcTxt).c_str()));
    
    funcView->item(funcView->count() - 1)->setForeground(*(new QBrush(newCol)));
}

void Window::addNewFunc(QString s)
{
    myList.push_back(s);
    ++numRows;
    funcView->addItem(myList[myList.size() - 1]);
}

void Window::UpSlot()
{
    mainCanvas.moveCoordinate(3);
}

void Window::DownSlot()
{
   mainCanvas.moveCoordinate(2);
}
void Window::LeftSlot()
{
    mainCanvas.moveCoordinate(1);
}
void Window::RightSlot()
{
    mainCanvas.moveCoordinate(0);
}
void Window::ZinSlot()
{
    mainCanvas.zoom(0);
}
void Window::ZoutSlot()
{
    mainCanvas.zoom(1);
}

void Window::ZinSlot_y()
{
    mainCanvas.zoom(2);
}
void Window::ZoutSlot_y()
{
    mainCanvas.zoom(3);
}

void Window::NewSlot()
{
    FunctionInputWindow *fiw = new FunctionInputWindow;
    fiw->setWindowTitle("Input Function");
    fiw->show();
    fiw->window = this;
}

void Window::DeleteSlot()
{
    int in=0;
    QString txt = funcView->currentItem()->text();
    for(int i = 0; i< myList.size(); ++i){
        if(myList[i] == txt){
            in = i;
            break;
        }
    }
    mainCanvas.removeFunction(in);
    
    myList.erase(myList.begin() + in);
    myList_cols.erase(myList_cols.begin() + in);
    
    funcView->clear();
    for(int i = 0; i< myList.size(); ++i){
        funcView->addItem(myList[i]);
        funcView->item(funcView->count() - 1)->setForeground(*(new QBrush(myList_cols[i])));
        
    }
}

void Window::ScreenSlot()
{
    QPixmap originalPixmap = QPixmap::grabWindow( gobject->winId());
    originalPixmap.save("ScreenShot.png");
}
