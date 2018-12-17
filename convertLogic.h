#ifndef CONVERTLOGIC_H
#define CONVERTLOGIC_H
#include <QString>
#include <QMainWindow>

#include <QObject>

enum numBase{  DEC = 10,OCT = 8,HEX = 16,BIN = 2,ERROR=-1 };

class ConvertLogic : public QObject
{
    Q_OBJECT
private:
    QMainWindow *window;
    numBase base;
    long value;
    void deleteFirst();
    void deleteLast();
public:
    //explicit ConvertLogic(QObject *parent = nullptr,QMainWindow window = nullptr);
     ConvertLogic(QObject*,QMainWindow*);
     ~ConvertLogic();
    void doCommand(QString);
    long getValue();
    numBase getBase();
    void setBase(numBase);
    numBase convToBase(QString);
signals:
    void numBaseChanged(numBase);
    void numChanged();
};

#endif // CONVERTLOGIC_H
