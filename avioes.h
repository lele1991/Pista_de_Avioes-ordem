#ifndef AVIOES_H
#define AVIOES_H


#include <QDateTime>

using namespace std;

class Avioes
{
public:
   // Avioes();
    Avioes(QString nome, QTime time, QString pavimento, QString subleito, QString pressao);
    QString avioes_str();
    QString avioes_carac();

    bool operator<(Avioes &comp_Aviao);

private:
    int id;
    QString nome;
    QTime time;
    QString pavimento;
    QString subleito;
    QString pressao;
};

#endif // AVIOES_H
