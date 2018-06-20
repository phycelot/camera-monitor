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
    //initWidgets();

    QString str = "Camera ";
    str.append(QString::number(id));
    CameraGroupBox->setTitle(str);

    toolButton->setText("...");

    streamButton->setText("stream");

    recButton->setText("rec");

    statutProgressBar->setValue(0);
    statutProgressBar->setTextVisible(true);
    statutProgressBar->setFormat("Initialisation"); //use fonction

    //init cameragroupbox layout
    //QGridLayout *camera_global_layout = new QGridLayout;
    //QGridLayout *final_layout = new QGridLayout;

    configureLayout();

    setLayout(final_layout);
}

void camera_ihm::initWidgets()
{
    QGroupBox *CameraGroupBox = new QGroupBox();
    QToolButton *toolButton = new QToolButton;  //add action
    QPushButton *streamButton = new QPushButton;  //add action
    QPushButton *recButton = new QPushButton;    //add action
    QLabel *statutLabel = new QLabel("Statut :");
    QProgressBar *statutProgressBar = new QProgressBar; //add action //color modif //value modif //text modif
    QLabel *videoLabel = new QLabel;
}

void camera_ihm::configureLayout()
{
    camera_global_layout->addWidget(toolButton,0,0);
    camera_global_layout->addWidget(streamButton,0,1);
    camera_global_layout->addWidget(recButton,0,2);
    camera_global_layout->addWidget(statutLabel,0,3);
    camera_global_layout->addWidget(statutProgressBar,0,4);
    camera_global_layout->addWidget(videoLabel,1,0);

    CameraGroupBox->setLayout(camera_global_layout);
    final_layout->addWidget(CameraGroupBox);
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
