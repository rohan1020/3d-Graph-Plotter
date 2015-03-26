//
//  FunctionInputWindow.cpp
//  2dpaint
//
//  Created by Rohan Raja on 24/03/15.
//
//

#include "FunctionInputWindow.h"
#include "ui_FunctionInputWindow.h"
#include <iostream>

FunctionInputWindow::FunctionInputWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::FunctionInputWindow)
{
    ui->setupUi(this);
}

FunctionInputWindow::~FunctionInputWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_clicked()
//{
//    QString s = ui->textEdit->toPlainText();
//    ui->label->setText(s);
//}

void FunctionInputWindow::on_pushButton_clicked()             //Proceed Button
{
    QString expression = ui->textEdit->toPlainText();
    evaluate(expression);
    
    
    
}

void FunctionInputWindow::on_pushButton_2_clicked()          //y=sin(x)
{
    QString expression = "sin(x)";
    evaluate(expression);
    
}

void FunctionInputWindow::on_pushButton_3_clicked()         //y=exp(x)
{
    QString expression ="exp(x)";
    evaluate(expression);
    
}

void FunctionInputWindow::on_pushButton_4_clicked()        //y=exp(cos(2*x))
{
    QString expression = "x+cos(x)-sin(2*x)+cos(6*x+pi)";
    evaluate(expression);
        // x + cos(x) - sin(2*x) + cos(6*x+ pi)
}

void FunctionInputWindow::evaluate(QString expression)
{
    //std::cout << "Proceedng with Expression : " << expression.toStdString() << "\n" ;
    window->addFunction(expression.toStdString());
    window->show();
    this->close();
}