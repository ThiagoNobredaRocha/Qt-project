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

void MainWindow::on_loginPushButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QString messageBoxTitle;
    QString messageBoxMessage;

    if (username == USERNAME && password == PASSWORD) {
        messageBoxTitle = "Autenticado com sucesso";
        messageBoxMessage = QString("O usuário ")+ui->usernameLineEdit->text() + " foi autenticado com sucesso";
    }
    else {
        messageBoxTitle = "Erro ao logar";
        messageBoxMessage = "Usuário ou senha incorretos";
    }

    QMessageBox::information(this, messageBoxTitle, messageBoxMessage, QMessageBox::Ok);
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setCheckable(true);

    if (ui->pushButton->isChecked()) {
        ui->pushButton->setText("ShowPass");
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
        qDebug() << "true";
    }else{
        ui->pushButton->setText("HidePass");
         ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);
        qDebug() << "false";
    }

}

