/********************************************************************************
** Form generated from reading UI file 'rcwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCWINDOW_H
#define UI_RCWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RCWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_ciudades;
    QLabel *label_ingrciudades;
    QLabel *label_CantPerm;
    QPushButton *pushButton_ciudades;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_adyacencias;
    QLabel *label;
    QLineEdit *lineEdit_ciudad_comienzo;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_resultado;
    QPushButton *pushButton_calcular;
    QLabel *label_2;
    QLineEdit *lineEdit_ciudades_final;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RCWindow)
    {
        if (RCWindow->objectName().isEmpty())
            RCWindow->setObjectName(QString::fromUtf8("RCWindow"));
        RCWindow->resize(800, 600);
        centralwidget = new QWidget(RCWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_ciudades = new QLineEdit(centralwidget);
        lineEdit_ciudades->setObjectName(QString::fromUtf8("lineEdit_ciudades"));
        lineEdit_ciudades->setGeometry(QRect(210, 20, 113, 21));
        label_ingrciudades = new QLabel(centralwidget);
        label_ingrciudades->setObjectName(QString::fromUtf8("label_ingrciudades"));
        label_ingrciudades->setGeometry(QRect(40, 20, 171, 21));
        label_CantPerm = new QLabel(centralwidget);
        label_CantPerm->setObjectName(QString::fromUtf8("label_CantPerm"));
        label_CantPerm->setGeometry(QRect(70, 50, 47, 13));
        pushButton_ciudades = new QPushButton(centralwidget);
        pushButton_ciudades->setObjectName(QString::fromUtf8("pushButton_ciudades"));
        pushButton_ciudades->setGeometry(QRect(220, 50, 80, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(420, 30, 321, 181));
        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 29, 281, 141));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_adyacencias = new QLabel(verticalLayoutWidget_2);
        label_adyacencias->setObjectName(QString::fromUtf8("label_adyacencias"));

        horizontalLayout_2->addWidget(label_adyacencias);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 101, 16));
        lineEdit_ciudad_comienzo = new QLineEdit(centralwidget);
        lineEdit_ciudad_comienzo->setObjectName(QString::fromUtf8("lineEdit_ciudad_comienzo"));
        lineEdit_ciudad_comienzo->setGeometry(QRect(180, 100, 113, 21));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(60, 240, 671, 151));
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 651, 111));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_resultado = new QLabel(verticalLayoutWidget_3);
        label_resultado->setObjectName(QString::fromUtf8("label_resultado"));

        verticalLayout_3->addWidget(label_resultado);

        pushButton_calcular = new QPushButton(centralwidget);
        pushButton_calcular->setObjectName(QString::fromUtf8("pushButton_calcular"));
        pushButton_calcular->setGeometry(QRect(590, 400, 80, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 140, 91, 16));
        lineEdit_ciudades_final = new QLineEdit(centralwidget);
        lineEdit_ciudades_final->setObjectName(QString::fromUtf8("lineEdit_ciudades_final"));
        lineEdit_ciudades_final->setGeometry(QRect(180, 140, 113, 21));
        RCWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RCWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        RCWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RCWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RCWindow->setStatusBar(statusbar);

        retranslateUi(RCWindow);

        QMetaObject::connectSlotsByName(RCWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RCWindow)
    {
        RCWindow->setWindowTitle(QCoreApplication::translate("RCWindow", "MainWindow", nullptr));
        label_ingrciudades->setText(QCoreApplication::translate("RCWindow", "Ingrese la cantidad de ciudades", nullptr));
        label_CantPerm->setText(QCoreApplication::translate("RCWindow", "(M\303\241x 10)", nullptr));
        pushButton_ciudades->setText(QCoreApplication::translate("RCWindow", "Continuar", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RCWindow", "ADYACENCIAS", nullptr));
        label_adyacencias->setText(QString());
        label->setText(QCoreApplication::translate("RCWindow", "Ciudad a comenzar:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("RCWindow", "RESULTADOS", nullptr));
        label_resultado->setText(QString());
        pushButton_calcular->setText(QCoreApplication::translate("RCWindow", "Calcular", nullptr));
        label_2->setText(QCoreApplication::translate("RCWindow", "Ciudad a finalizar:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RCWindow: public Ui_RCWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCWINDOW_H
