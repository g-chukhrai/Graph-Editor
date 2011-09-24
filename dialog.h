#ifndef DIALOG_H
#define DIALOG_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT
public:
    Dialog(int, MainWindow*, QWidget *parent = 0);
    ~Dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Dialog *ui;
    MainWindow* mainW;
    int hideBut;
    void hideButtons();

private slots:
    void on_buttCancel_clicked();
    void on_buttMulti_clicked();
    void on_buttRobFloUpg_clicked();
    void on_buttRobFlor_clicked();
    void on_buttAlgUpg_clicked();
    void on_buttAlg_clicked();
};

#endif // DIALOG_H
