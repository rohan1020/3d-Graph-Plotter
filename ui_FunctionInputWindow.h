/********************************************************************************
** Form generated from reading UI file 'FunctionInputWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONINPUTWINDOW_H
#define UI_FUNCTIONINPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FunctionInputWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FunctionInputWindow)
    {
        if (FunctionInputWindow->objectName().isEmpty())
            FunctionInputWindow->setObjectName(QString::fromUtf8("FunctionInputWindow"));
        FunctionInputWindow->resize(508, 474);
        centralWidget = new QWidget(FunctionInputWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(120, 60, 261, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 370, 501, 57));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 70, 67, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 40, 261, 17));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 140, 261, 95));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 40, 261, 17));

        verticalLayout->addWidget(label_4);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        FunctionInputWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FunctionInputWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 508, 25));
        FunctionInputWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FunctionInputWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FunctionInputWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FunctionInputWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FunctionInputWindow->setStatusBar(statusBar);

        retranslateUi(FunctionInputWindow);

        QMetaObject::connectSlotsByName(FunctionInputWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FunctionInputWindow)
    {
        FunctionInputWindow->setWindowTitle(QApplication::translate("FunctionInputWindow", "FunctionInputWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("FunctionInputWindow", "Proceed", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FunctionInputWindow", "      y=", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FunctionInputWindow", "Enter Function:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FunctionInputWindow", "Examples:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("FunctionInputWindow", "y=sin(x)", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("FunctionInputWindow", "y=exp(x)", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("FunctionInputWindow", "y=x+cos(x)-sin(2*x)+cos(6*x+pi)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FunctionInputWindow: public Ui_FunctionInputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONINPUTWINDOW_H
