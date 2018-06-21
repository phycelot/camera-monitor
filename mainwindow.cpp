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

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << __func__;

    QTimer::singleShot(100, this, SLOT(showFullScreen()));
    //init();
    QHostAddress hostAddress;
    addCamera(hostAddress);
}

void MainWindow::addCamera(QHostAddress hostAddress)
{
    list_camera_ihm.push_back(new camera_ihm(hostAddress));
    manageIhmPosition();
}

void MainWindow::manageIhmPosition()
{
    int len = list_camera_ihm.length();
    if(len>0)
    {
        ui->cameraGroupLayout->addWidget(list_camera_ihm[0],0,0);
        if(len>1)
        {
           ui->cameraGroupLayout->addWidget(list_camera_ihm[1],0,1);
           if(len>2)
           {
               ui->cameraGroupLayout->addWidget(list_camera_ihm[2],1,0);
               if(len>3)
               {
                   ui->cameraGroupLayout->addWidget(list_camera_ihm[3],1,1);
               }
           }
        }
    }
}

void MainWindow::init()
{
}

void MainWindow::init()
{

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
