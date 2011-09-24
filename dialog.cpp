#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(int hB,MainWindow* mW,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mainW = mW;
    this->hideBut = hB;
    this->hideButtons();
    this->setWindowTitle(this->mainW->windowTitle());
    this->setWindowIcon(this->mainW->windowIcon());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Dialog::hideButtons()
{
    switch(this->hideBut)
    {
    case 1:
        ui->buttAlg->setDisabled(true);
        ui->buttRobFlor->setDisabled(true);
        break;
    case 2:
        ui->buttAlg->setDisabled(true);
        ui->buttAlgUpg->setDisabled(true);
        ui->buttRobFlor->setDisabled(true);
        break;
    case 3:
        ui->buttAlg->setDisabled(true);
        ui->buttAlgUpg->setDisabled(true);
        ui->buttRobFlor->setDisabled(true);
        ui->buttRobFloUpg->setDisabled(true);
        break;
    }
}

void Dialog::on_buttAlg_clicked()
{
    this->close();
    mainW->beginFind(0);
}

void Dialog::on_buttAlgUpg_clicked()
{
    this->close();
    mainW->beginFind(1);
}

void Dialog::on_buttRobFlor_clicked()
{
    this->close();
    mainW->beginFind(2);
}

void Dialog::on_buttRobFloUpg_clicked()
{
    this->close();
    mainW->beginFind(3);
}

void Dialog::on_buttMulti_clicked()
{
    this->close();
    mainW->beginFind(4);
}

void Dialog::on_buttCancel_clicked()
{
    this->close();
}

