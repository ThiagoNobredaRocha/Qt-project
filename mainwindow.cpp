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
