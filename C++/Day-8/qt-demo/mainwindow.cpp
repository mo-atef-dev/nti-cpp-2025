#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_return_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Message", "Hello Qt!");
}

void MainWindow::on_return_pressed()
{
    QString text = ui->lineEdit->text();
    QMessageBox::information(this, "Message", text);
}







































