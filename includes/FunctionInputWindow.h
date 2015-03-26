//
//  FunctionInputWindow.h
//  2dpaint
//
//  Created by Rohan Raja on 24/03/15.
//
//

#ifndef ___dpaint__FunctionInputWindow__
#define ___dpaint__FunctionInputWindow__

#include <stdio.h>

#include <QMainWindow>
#include "window.h"

namespace Ui {
    class FunctionInputWindow;
}

class FunctionInputWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FunctionInputWindow(QWidget *parent = 0);
    ~FunctionInputWindow();
    Window *window;
    void evaluate(QString expression);
    
    private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();
    
    void on_pushButton_3_clicked();
    
    void on_pushButton_4_clicked();
    
private:
    Ui::FunctionInputWindow *ui;
    
};

#endif /* defined(___dpaint__FunctionInputWindow__) */
