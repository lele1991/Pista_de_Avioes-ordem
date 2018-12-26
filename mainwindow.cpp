#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_dialog.h"
#include <QDebug>
#include <iterator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->avioes_l.push_back(Avioes("BOEING 737NG               ",QTime(06,10),"F", "A","W"));
    this->avioes_l.push_back(Avioes("AIRBUS A320                ",QTime(07,15),"R","B","X"));
    this->avioes_l.push_back(Avioes("ATR                        ",QTime(10,20),"R","B","Y"));
    this->avioes_l.push_back(Avioes("BAC ONE-ELEVEN             ",QTime(11,45),"R","D","Z"));
    this->avioes_l.push_back(Avioes("BEECHCRAFT BARON           ",QTime(11,50),"F","C","Z"));
    this->avioes_l.push_back(Avioes("BEECHCRAFT KING AIR        ",QTime(12,20),"R","A","X"));
    this->avioes_l.push_back(Avioes("BEECHCRAFT BONANZA         ",QTime(12,30),"F","A","Y"));
    this->avioes_l.push_back(Avioes("BELL 429                   ",QTime(13,10),"R", "C","X"));
    this->avioes_l.push_back(Avioes("BOEING 707                 ",QTime(13,35),"F","D","W"));
    this->avioes_l.push_back(Avioes("BOEING B-29 SUPERFORTRESS  ",QTime(14,05),"R","A","X"));
    this->avioes_l.push_back(Avioes("BOEING B-52 STRATOFORTRESS ",QTime(14,15),"F","B","Y"));
    this->avioes_l.push_back(Avioes("BOMBARDIER CHALLENGER      ",QTime(14,40),"F","C","W"));
    this->avioes_l.push_back(Avioes("CESSNA 206                 ",QTime(15,20),"R","C","Z"));
    this->avioes_l.push_back(Avioes("DIAMOND DA-42 TWIN STAR    ",QTime(15,30),"R","A","W"));
    this->avioes_l.push_back(Avioes("LANCAIR EVOLUTION          ",QTime(15,55),"F","B","W"));
    this->avioes_l.push_back(Avioes("MD NOTAR                   ",QTime(16,00),"R","B","X"));
    this->avioes_l.push_back(Avioes("MOONEY AIRPLANE COMPANY    ",QTime(16,25),"F","D","Y"));
    this->avioes_l.push_back(Avioes("NORTH AMERICAN T-6 TEXAN   ",QTime(17,20),"R","C","Z"));
    this->avioes_l.push_back(Avioes("PILATUS PC-12              ",QTime(18,40),"R","A","Y"));
    this->avioes_l.push_back(Avioes("PATURI                     ",QTime(19,10),"F","B","X"));
    this->avioes_l.push_back(Avioes("PIPER MALIBU               ",QTime(20,40),"R","C","W"));
    this->avioes_l.push_back(Avioes("SANTOS DUMONT 14-BIS       ",QTime(21,45),"F","D","Y"));
    this->avioes_l.push_back(Avioes("SUPERMARINE SPITFIRE       ",QTime(22,30),"R","D","X"));
    this->avioes_l.push_back(Avioes("SUPER PETREL               ",QTime(23,10),"R","C","W"));
    this->avioes_l.push_back(Avioes("SOCATA TB                  ",QTime(23,40),"R","B","Z"));

    adddialog = new Add_Dialog(this);
    remdialog = new rem_Dialog(this);

    connect(adddialog, SIGNAL(call_atualiza_lista(QString, QString, QString, QString, QString)),this,
                              SLOT(atualiza_lista(QString, QString, QString, QString, QString ))); //recebe o sinal do emite do adddialog

    connect(remdialog, SIGNAL(call_limpa(QString)),this, SLOT(atualiza_lista_remove(QString))); //remove

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listar_avioes_clicked()
{
    QString lista = "ID\tNome\t                        Hora\n";

    for(ptr = avioes_l.begin(); ptr != avioes_l.end(); ptr++)
    {
        lista += ptr->avioes_str() + "\n";
    }

    ui->txt_console->setText(lista);
    n_avioes(static_cast<int>(avioes_l.size()));        //LCD

}

void MainWindow::on_listar_caract_clicked()
{
    unsigned int i = avioes_l.size();

    if(i != 0){
        QString lista = "PAVIMENTO:\n"
                          "F – pavimento flexível (asfalto geralmente);\n"
                          "R – pavimento rígido (concreto geralmente).\n\n"
                          "RESISTÊNCIA DO SUBLEITO:\n"
                          "A – alta;\n"
                          "B – média;\n"
                          "C - baixa;\n"
                          "D - ultra-baixa.\n\n"
                          "PRESSÃO MÁXIMA ADMISSÍVEL DOS PNEUS:\n"
                          "W - alta (sem limite);\n"
                          "X – média (até 1,5 MPa);\n"
                          "Y - baixa (até 1,0 MPa);\n"
                          "Z - muito baixa (até 0,5 MPa)\n\n"
                          "Nome\t                   Pavimento  Subleito  Pressão\n";
        ptr = avioes_l.begin();
        lista += ptr->avioes_carac()+"\n";
        ui->txt_console->setText(lista);
    }
}

void MainWindow::n_avioes(int i)
{
    ui->lcdNumber->display(i);
}

void MainWindow::on_autoriza_A_clicked()
{
    QString aviao = "Autorizando decolagem na pista A:\n";

    if(avioes_l.size() != 0){
        ptr = avioes_l.begin();
        aviao += ptr->avioes_str();
        ui->txt_console->setText(aviao);
        n_avioes(static_cast<int>(avioes_l.size()-1));
        avioes_l.pop_front();
    }
}

void MainWindow::on_autoriza_B_clicked()
{
    QString aviao = "Autorizando decolagem na pista B:\n";

    if(avioes_l.size() != 0){
        ptr = avioes_l.begin();
        aviao += ptr->avioes_str();
        ui->txt_console->setText(aviao);
        n_avioes(static_cast<int>(avioes_l.size()-1));
        avioes_l.pop_front();
    }
}

void MainWindow::on_autoriza_C_clicked()
{
    QString aviao = "Autorizando decolagem na pista C:\n";
    if(avioes_l.size() != 0){
        ptr = avioes_l.begin();
        aviao += ptr->avioes_str();
        ui->txt_console->setText(aviao);
        n_avioes(static_cast<int>(avioes_l.size()-1));        //LCD
        avioes_l.pop_front();
    }
}

void MainWindow::on_add_aviao_clicked()
{
    adddialog->show();
}

void MainWindow::on_rem_aviao_clicked()
{
    remdialog->show();
}

void MainWindow::atualiza_lista(QString nome, QString hora, QString pavimento, QString subleito, QString pressao)
{
    this->avioes_l.push_back(Avioes(nome,QTime::fromString(hora),pavimento,subleito,pressao));
    avioes_l.sort();
}

void MainWindow::atualiza_lista_remove(QString i)
{
    size_t j = i.toUInt()-1;
    //qDebug() << j << "\n";
    if (j<avioes_l.size()){
        ptr = avioes_l.begin();
        std::advance(ptr, j);
        avioes_l.erase(ptr);
    }
}
