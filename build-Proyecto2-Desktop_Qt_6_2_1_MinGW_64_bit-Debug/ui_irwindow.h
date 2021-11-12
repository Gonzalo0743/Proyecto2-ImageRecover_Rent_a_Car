/********************************************************************************
** Form generated from reading UI file 'irwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IRWINDOW_H
#define UI_IRWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IRWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *lbl_image;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IRWindow)
    {
        if (IRWindow->objectName().isEmpty())
            IRWindow->setObjectName(QString::fromUtf8("IRWindow"));
        IRWindow->resize(800, 600);
        centralwidget = new QWidget(IRWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 510, 111, 21));
        lbl_image = new QLabel(centralwidget);
        lbl_image->setObjectName(QString::fromUtf8("lbl_image"));
        lbl_image->setGeometry(QRect(160, 80, 451, 341));
        IRWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(IRWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        IRWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(IRWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IRWindow->setStatusBar(statusbar);

        retranslateUi(IRWindow);

        QMetaObject::connectSlotsByName(IRWindow);
    } // setupUi

    void retranslateUi(QMainWindow *IRWindow)
    {
        IRWindow->setWindowTitle(QCoreApplication::translate("IRWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("IRWindow", "Choose an image", nullptr));
        lbl_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IRWindow: public Ui_IRWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IRWINDOW_H
