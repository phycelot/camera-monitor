//-------------------------
//
// file created by Prouteau Antonin
// 14/06/2018
//
//-------------------------

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usefull.h"
#include <QTimer>
#include <QDebug>
#include <QDate>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qInstallMessageHandler(usefull::myMessageOutput); // Install the handler
    qDebug() << __func__;
    ui->setupUi(this);
    init();
}

void MainWindow::init()
{
    QTimer::singleShot(100, this, SLOT(showFullScreen()));
    QString text="statut";
    qDebug() << ui->statutProgress->format();
    ui->statutProgress->setValue(12);
    ui->statutProgress->setTextVisible(true);
    QLabel *label = ui->statutProgress->findChild<QLabel *>();
    if (label)
    {
        label->setText(text);
    }
    //    ui->statutProgress->setFormat(text);
    //    ui->statutProgress_2->setFormat(text);
    //    ui->statutProgress_3->setFormat(text);
    //    ui->statutProgress_4->setFormat(text)
}

MainWindow::~MainWindow()
{
    delete ui;
}
