#include "rem_dialog.h"
#include "ui_rem_dialog.h"

rem_Dialog::rem_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rem_Dialog)
{
    ui->setupUi(this);
}

rem_Dialog::~rem_Dialog()
{
    delete ui;
}

void rem_Dialog::on_CANCELA_rem_clicked()
{
    hide();
}

void rem_Dialog::on_OK_rem_clicked()
{
    i = ui->get_numero->text();
    emit call_limpa(i);
    hide();
}
