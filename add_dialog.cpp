#include "add_dialog.h"
#include "ui_add_dialog.h"

Add_Dialog::Add_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Dialog)
{
    ui->setupUi(this);
}

Add_Dialog::~Add_Dialog()
{
    delete ui;
}

void Add_Dialog::on_OK_clicked()
{ 
    nome = ui->get_nome->text();
    hora = ui->get_hora->text();
    pavimento = ui->get_pavimento->text();
    subleito = ui->get_subleito->text();
    pressao = ui->get_pressao->text();

    emit call_atualiza_lista(nome, hora, pavimento, subleito, pressao); //emite sinal
    hide();
}

void Add_Dialog::on_CANCELA_clicked()
{
    hide();
}
