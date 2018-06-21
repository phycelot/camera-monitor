//-------------------------
//
// file created by Prouteau Antonin
// 14/06/2018
//
//-------------------------

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "camera_ihm.h"

#include <QTimer>
#include <QDebug>
#include <QDate>
#include <QDir>
#include <QVector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << __func__;

    QTimer::singleShot(100, this, SLOT(showFullScreen()));
    //init();
    camera_ihm *one = new camera_ihm(1);
    list_camera_ihm.push_back(one);
    list_camera_ihm.push_back(new camera_ihm(2));
    qDebug() << list_camera_ihm[0]->id;
}

void MainWindow::init()
{


    camera_ihm *one = new camera_ihm(1);
    camera_ihm *two = new camera_ihm(2);
    camera_ihm *three = new camera_ihm(3);
    camera_ihm *four = new camera_ihm(4);

#if 1
    ui->cameraGroupLayout->addWidget(one,0,0);
    ui->cameraGroupLayout->addWidget(two,0,1);
    ui->cameraGroupLayout->addWidget(three,1,0);
    ui->cameraGroupLayout->addWidget(four,1,1);
#endif
    one->setStatut(-1);
    two->setStatut();
    three->setStatut(1);
    four->setStatut(2);
}

void MainWindow::Disp(QImage image,int imageType)
{
//    for (int i=0;i<list_camera_ihm.length();i++)
//    {
//        if (true)//testsi c'est la bonne image/camera
//        {
//            int tempWidth = 100;
//            int tempHeight = 100;
//            QPixmap pix = QPixmap::fromImage(image.scaled(tempWidth, tempHeight));

//            //list_camera_ihm[i]->setImage(pix);
//        }
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
