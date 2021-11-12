#include "rcwindow.h"
#include "ui_rcwindow.h"
#include "graph.h"
#include "iostream"
#include "QString"
#include "QMessageBox"


RCWindow::RCWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RCWindow)
{
    ui->setupUi(this);
}

RCWindow::~RCWindow()
{
    delete ui;
}

Graph gr;
int Vertices = 0;


void RCWindow::on_pushButton_ciudades_clicked()
{
    QString ingreso_ciudades = ui->lineEdit_ciudades->text();
    int Vertices = ingreso_ciudades.toInt();

        string total_ciudades[10] = {"A","B","C","D","E","F","G","H","I","J"};
        gr.Start();

        for(int i=0; i< Vertices; i++){
            if(Vertices> 15){
                cout<<"El numero no coincide"<<endl;
                break;
            }
            gr.InsVertice(total_ciudades[i]);
     }

        srand((unsigned int)time(NULL));

        int g = 0;
        int rand1, rand2, res;
        while (g<(Vertices*2)-2) {

            rand1 = rand()%Vertices;
            rand2 = rand()%Vertices;
            res = (rand()%20)+1;

            if(rand1 == rand2){
                continue;
            }
            gr.InsArista(gr.GetVertice(total_ciudades[rand1]), gr.GetVertice(total_ciudades[rand2]),res);
            g++;
    }
        if(Vertices<=10){
            QString label_msg = QString::fromStdString(gr.listAdyacente());
            QMessageBox::information(this,"Ciudades","El numero de ciudades ingresadas es de: "+ingreso_ciudades);
            ui->label_adyacencias->setText(label_msg);
        }
        else if (Vertices > 10 or Vertices ==0){
            QMessageBox::information(this,"Ciudades","Se ingreso un numero mayor a 10, intente otra vez");

        }
}


void RCWindow::on_pushButton_calcular_clicked()
{
    QString ciudad_comienzo = ui->lineEdit_ciudad_comienzo->text();
    QString ciudad_final = ui->lineEdit_ciudades_final->text();
    string resultado_alg = gr.PrimMejor(gr.GetVertice(ciudad_comienzo.toStdString()),gr.GetVertice(ciudad_final.toStdString()));
    QString label_result = QString::fromStdString(resultado_alg);
    ui->label_resultado->setText(label_result);
}

