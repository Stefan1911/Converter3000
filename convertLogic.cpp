#include "convertLogic.h"

ConvertLogic::ConvertLogic(QObject *parent,QMainWindow* window) : QObject(parent)
{
    this->window = window;
    this->value = 0;
    this->base = HEX;
}
ConvertLogic::~ConvertLogic(){
    delete window;
}
long ConvertLogic::getValue(){
    return  this->value;
}
numBase ConvertLogic::getBase(){
    return this->base;
}

void ConvertLogic::doCommand(QString value){
    if(value=="CLEAR")
        this->value=0;
    else if(value=="-->")
        deleteFirst();
    else if(value=="<--")
        deleteLast();
    else
    {
        QString temp = QString::number(this->value,this->base);
        temp+=value;
        this->value = (temp).toLong(nullptr,this->base);
    }
    emit numChanged();
}

void ConvertLogic::setBase(numBase base){
    this->base = base;
}
void ConvertLogic::deleteLast(){
    QString temp = QString::number(this->value,this->base);
    int temp2= (temp[temp.length()-1]+"").toInt(nullptr,this->base);
    this->value-=temp2;
    this->value/=this->base;

}
void ConvertLogic::deleteFirst(){
    QString temp = QString::number(this->value,this->base);
    temp[0]= '0';
    this->value = temp.toInt(nullptr,this->base);
}

numBase ConvertLogic::convToBase(QString str){
    if(str == "DEC") return  DEC;
    if(str == "OCT") return  OCT;
    if(str == "HEX") return  HEX;
    if(str == "BIN") return  BIN;
    return ERROR;
}
