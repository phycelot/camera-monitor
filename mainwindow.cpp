//-------------------------
//
// file created by Prouteau Antonin
// 14/06/2018
//
//-------------------------

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usefull.h"

#include "camera_ihm.h"

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

    camera_ihm *one = new camera_ihm(1);
    camera_ihm *two = new camera_ihm(2);
    camera_ihm *three = new camera_ihm(3);
    camera_ihm *four = new camera_ihm(4);

//    one->setStatut("cours toujours");
//    qDebug() << one->getStatut();
//    two->setStatut("reste tranquille");
#if 1
    ui->cameraGroupLayout->addWidget(one,0,0);
    ui->cameraGroupLayout->addWidget(two,0,1);
    ui->cameraGroupLayout->addWidget(three,1,0);
    ui->cameraGroupLayout->addWidget(four,1,1);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
