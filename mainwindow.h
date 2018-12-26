#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include <string>
#include "avioes.h"
#include "add_dialog.h"
#include "rem_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void atualiza_lista(QString nome, QString hora, QString pavimento, QString subleito, QString pressao);
    void atualiza_lista_remove(QString i);

private slots:

    void on_listar_avioes_clicked();

    void on_listar_caract_clicked();

    void n_avioes( int i);

    void on_add_aviao_clicked();

    void on_rem_aviao_clicked();

    void on_autoriza_A_clicked();

    void on_autoriza_B_clicked();

    void on_autoriza_C_clicked();

private:
    Ui::MainWindow *ui;
    std::list<Avioes> avioes_l;
    std::list<Avioes>::iterator ptr;
    Add_Dialog *adddialog;
    rem_Dialog *remdialog;

};

#endif // MAINWINDOW_H
