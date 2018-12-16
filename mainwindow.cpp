#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->mozak = new ConvertLogic(nullptr,this);
    ui->setupUi(this);
    connect(this->mozak,SIGNAL(numChanged()),this,SLOT(onNmberChanged()));
    connect(this->ui->radioDEC,SIGNAL(toggled(bool)),this,SLOT(onNumBaseChanged()));
    connect(this->ui->radioHEX,SIGNAL(toggled(bool)),this,SLOT(onNumBaseChanged()));
    connect(this->ui->radioOCT,SIGNAL(toggled(bool)),this,SLOT(onNumBaseChanged()));
    connect(this->ui->radioBIN,SIGNAL(toggled(bool)),this,SLOT(onNumBaseChanged()));

     connect(this->ui->button0,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button1,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button2,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button3,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button4,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button5,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button6,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button7,SIGNAL(clicked()),this,SLOT(onBtnClicked()));

     connect(this->ui->button8,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->button9,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttona,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttonb,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttonc,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttond,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttone,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttonf,SIGNAL(clicked()),this,SLOT(onBtnClicked()));

     connect(this->ui->buttonClear,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttonLeft,SIGNAL(clicked()),this,SLOT(onBtnClicked()));
     connect(this->ui->buttonRight,SIGNAL(clicked()),this,SLOT(onBtnClicked()));


}
void MainWindow::onBtnClicked(){
    QPushButton *b=(QPushButton*)sender();
    QString str=b->text();
    mozak->add(str);

}

MainWindow::~MainWindow()
{
    delete mozak;
    delete ui;
}

void MainWindow::onNmberChanged()
{
    QString conValue;
    QString trueValue;
    conValue = QString::number(this->mozak->getValue(),this->mozak->getBase());
    trueValue = QString::number(this->mozak->getValue(),10);
    ui->truValueLabel->setText(trueValue);
    ui->conValueLabel->setText(conValue);
}

void MainWindow::onNumBaseChanged(){

    QRadioButton* tempRadio = (QRadioButton*)sender();

    if(tempRadio->isChecked()){
        QString temp = tempRadio->text() ;
        this->mozak->setBase(this->mozak->convToBase(temp));
        this->onNmberChanged();
        enableAll();
        if(temp=="DEC")
            disableDec();
        if(temp=="OCT")
            disableOct();
        if(temp=="BIN")
            disableBin();
    }


};
void MainWindow::enableAll(){
    ui->button0->setEnabled(true);
    ui->button1->setEnabled(true);
    ui->button2->setEnabled(true);
    ui->button3->setEnabled(true);
    ui->button4->setEnabled(true);
    ui->button5->setEnabled(true);
    ui->button6->setEnabled(true);
    ui->button7->setEnabled(true);

    ui->button8->setEnabled(true);
    ui->button9->setEnabled(true);
    ui->buttona->setEnabled(true);
    ui->buttonb->setEnabled(true);
    ui->buttonc->setEnabled(true);
    ui->buttond->setEnabled(true);
    ui->buttone->setEnabled(true);
    ui->buttonf->setEnabled(true);
}

void MainWindow::disableBin(){
    disableOct();
    ui->button2->setEnabled(false);
    ui->button3->setEnabled(false);
    ui->button4->setEnabled(false);
    ui->button5->setEnabled(false);
    ui->button6->setEnabled(false);
    ui->button7->setEnabled(false);

}
void MainWindow::disableOct(){
    disableDec();
    ui->button8->setEnabled(false);
    ui->button9->setEnabled(false);
}

void MainWindow::disableDec(){
    ui->buttona->setEnabled(false);
    ui->buttonb->setEnabled(false);
    ui->buttonc->setEnabled(false);
    ui->buttond->setEnabled(false);
    ui->buttone->setEnabled(false);
    ui->buttonf->setEnabled(false);
}


void MainWindow::on_pushButton_clicked()
{
    //this->ui->conValueLabel->setText("9");
    this->mozak->add("1");
}
