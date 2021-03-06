#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"convertLogic.h"
#include <QMainWindow>
#include<QString>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    ConvertLogic* mozak;
    void enableAll();
    void disableBin();
    void disableOct();
    void disableDec();
    void connectAll();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onNmberChanged();
    void onNumBaseChanged();
private slots:
    void onBtnClicked();

};

#endif // MAINWINDOW_H
