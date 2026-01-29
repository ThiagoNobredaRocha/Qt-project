#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton retarn =
    QMessageBox::question(this,"Test",ui->lineEdit->text(),QMessageBox::Yes|QMessageBox::No);
    if(retarn==QMessageBox::Yes)
        QApplication::quit();
    else QMessageBox::about(this,"Answer","wrong answer");
        //qDebug() << "wrong answer";
}

