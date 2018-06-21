#include "camera_ihm.h"
#include <QDebug>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>

//camera_ihm::camera_ihm(int id,QWidget *parent)
//    : QWidget(parent){
//    this->id=id;

//    initWidgets();
//    initLayout();
//    configureLayout();

//    setLayout(final_layout);
//}
int camera_ihm::c_id=0;

camera_ihm::camera_ihm(QHostAddress hostAddress,QWidget *parent)
    : QWidget(parent){
    this->hostAddress=hostAddress;
    id=c_id;
    c_id+=1;
    initWidgets();
    initLayout();
    configureLayout();

    setLayout(final_layout);
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
    initWidgetsValue();
}

void camera_ihm::initWidgetsValue()
{
    QString str = "Camera ";
    str.append(QString::number(id));
    CameraGroupBox->setTitle(str);

    toolButton->setText("...");
    toolButton->setEnabled(false);

    streamButton->setText("stream");
    streamButton->setEnabled(false);

    recButton->setText("rec");
    recButton->setEnabled(false);

    statutLabel->setText("Statut :");

    statutProgressBar->setValue(0);
    setStatut(1);
}

void camera_ihm::initLayout()
{
    camera_global_layout = new QGridLayout;
    final_layout = new QGridLayout;
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
    statutProgressBar->setTextVisible(true);
    statutProgressBar->setFormat(s);
}

void camera_ihm::setStatut(const int i)
{
    statutProgressBar->setTextVisible(true);
    QString text="";
    QPalette p = palette();
    int value=0;
    switch (i) {
    case -1:
        text="error";
        value=100;
        p.setColor(QPalette::Highlight, Qt::darkRed);
        break;
    case 0:
        text="standby";
        value=100;
        p.setColor(QPalette::Highlight, Qt::gray);
        break;
    case 1:
        text="initialisation";
        value=100;
        //p.setColor(QPalette::Highlight, Qt::darkBlue);
        break;
    case 2:
        text="work";
        value=100;
        p.setColor(QPalette::Highlight, Qt::darkGreen);
        break;
    default:
        break;
    }

    statutProgressBar->setValue(value);
    statutProgressBar->setPalette(p);
    statutProgressBar->setFormat(text);
}

QString camera_ihm::getStatut()
{
    return statutProgressBar->format();
}

void camera_ihm::setImage(QPixmap pix)
{
    videoLabel->setPixmap(pix);
}

camera_ihm::~camera_ihm() {}
