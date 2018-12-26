#ifndef REM_DIALOG_H
#define REM_DIALOG_H

#include <QDialog>

namespace Ui {
class rem_Dialog;
}

class rem_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit rem_Dialog(QWidget *parent = nullptr);
    QString i;
    ~rem_Dialog();

signals:
    void call_limpa(QString i);

private slots:
    void on_CANCELA_rem_clicked();

    void on_OK_rem_clicked();

private:
    Ui::rem_Dialog *ui;
};

#endif // REM_DIALOG_H
