#ifndef ADD_DIALOG_H
#define ADD_DIALOG_H

#include <QDialog>

namespace Ui {
class Add_Dialog;
}

class Add_Dialog : public QDialog
{

    Q_OBJECT

public:
    explicit Add_Dialog(QWidget *parent = nullptr);
    QString hora, nome, pavimento, pressao, subleito;
    int ok = 0;
    ~Add_Dialog();

signals:
    void call_atualiza_lista(QString nome, QString hora, QString pavimento, QString subleito, QString pressao);

private slots:
    void on_OK_clicked();

    void on_CANCELA_clicked();

private:
    Ui::Add_Dialog *ui;
};

#endif // ADD_DIALOG_H
