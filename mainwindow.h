//-------------------------
//
// file created by Prouteau Antonin
// 14/06/2018
//
//-------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>
#include <QMainWindow>

#include "camera_ihm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QVector<camera_ihm*> list_camera_ihm;
    Ui::MainWindow *ui;
    void Disp(QImage image,int imageType);
    void init();
    void addCamera(QHostAddress hostAddress);
    void manageIhmPosition();

};

#endif // MAINWINDOW_H
