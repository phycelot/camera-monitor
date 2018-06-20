#include "camera_ihm.h"
#include <QDebug>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>

camera_ihm::camera_ihm(int id,QWidget *parent)
    : QWidget(parent){
    this->id=id;
    //init the group box
    initWidgets();

    QString str = "Camera ";
    str.append(QString::number(id));
    this->CameraGroupBox->setTitle(str);

    this->toolButton->setText("...");

    this->streamButton->setText("stream");

    this->recButton->setText("rec");

    this->statutLabel->setText("Statut :");

    this->statutProgressBar->setValue(0);
//    this->statutProgressBar->setTextVisible(true);
//    this->statutProgressBar->setFormat("Initialisation"); //use fonction
    this->setStatut("Initialisation");
    //init cameragroupbox layout
    camera_global_layout = new QGridLayout;
    final_layout = new QGridLayout;

    configureLayout();

    setLayout(this->final_layout);
}

void camera_ihm::initWidgets()
{
    CameraGroupBox = new QGroupBox();
    toolButton = new QToolButton;  //add action
    streamButton = new QPushButton;  //add action
    recButton = new QPushButton;    //add action
    statutLabel = new QLabel();
    statutProgressBar = new QProgressBar; //add action //color modif //value modif //text modif
    videoLabel = new QLabel;
}

void camera_ihm::configureLayout()
{
    this->camera_global_layout->addWidget(toolButton,0,0);
    this->camera_global_layout->addWidget(streamButton,0,1);
    this->camera_global_layout->addWidget(recButton,0,2);
    this->camera_global_layout->addWidget(statutLabel,0,3);
    this->camera_global_layout->addWidget(statutProgressBar,0,4);
    this->camera_global_layout->addWidget(videoLabel,1,0);

    this->CameraGroupBox->setLayout(camera_global_layout);
    this->final_layout->addWidget(CameraGroupBox);
}


void camera_ihm::setStatut(const QString s)
{
    this->statutProgressBar->setTextVisible(true);
    this->statutProgressBar->setFormat(s);
}

QString camera_ihm::getStatut()
{
    return this->statutProgressBar->format();
}

void camera_ihm::setImage(QPixmap pix)
{
    videoLabel->setPixmap(pix);
}

camera_ihm::~camera_ihm() {}
