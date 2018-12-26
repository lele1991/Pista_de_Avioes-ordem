#include "avioes.h"

Avioes::Avioes(QString nome, QTime time, QString pavimento, QString subleito, QString pressao)
{
    //this -> ptr implicito
    this->id = time.hour()*100 + time.minute();     //hora deslocada pra mostra lcd = ID   //HHMM
    this->nome = nome;
    this->time = time;
    this->pavimento = pavimento;
    this->subleito = subleito;
    this->pressao = pressao;
}

QString Avioes::avioes_str()
{
    QString output;
    output = output.sprintf("%04d", this->id) + "\t" + this->nome + "\t" + this->time.toString();
    return output;
}

QString Avioes::avioes_carac()
{
    QString output;
    output =this->nome +"\t"+ this->pavimento + "\t" + this->subleito + "\t" + this->pressao;
    return output;
}

bool Avioes::operator<(Avioes &comp_Aviao){
    if (this->id < comp_Aviao.id){
        return true;
    }
    return false;
}
