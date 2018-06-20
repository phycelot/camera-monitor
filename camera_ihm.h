#ifndef CAMERA_HIM_H
#define CAMERA_HIM_H
#include <QDebug>
#include <QGroupBox>
#include <QGridLayout>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>

class camera_ihm: public QWidget
{
    Q_OBJECT
public:
    camera_ihm(int id,QWidget *parent=0);
    void setStatut(const QString s);
    QString getStatut();
    void setImage(QPixmap pix);
    ~camera_ihm();
private:
    int id;
    void initWidgets();
    void configureLayout();
    QGroupBox *CameraGroupBox;
    QToolButton *toolButton;
    QPushButton *streamButton;
    QPushButton *recButton;
    QLabel *statutLabel;
    QProgressBar *statutProgressBar;
    QLabel *videoLabel;
    QGridLayout *camera_global_layout;
    QGridLayout *final_layout;


};

#endif // camera_ihm_H