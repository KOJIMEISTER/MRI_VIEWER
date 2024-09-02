#include "dialogwhichwind.h"
#include "ui_dialogwhichwind.h"
#include "mainwindow.h"

DialogWhichWind::DialogWhichWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWhichWind)
{
    ui->setupUi(this);

}

DialogWhichWind::~DialogWhichWind()
{
    delete ui;
}

void DialogWhichWind::on_btnToWin1_clicked()
{
    pickWindow(0);
    close();
}

void DialogWhichWind::on_btnToWin2_clicked()
{
    pickWindow(1);
    close();
}
