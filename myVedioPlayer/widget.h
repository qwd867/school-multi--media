#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QFileDialog>
#include <QString>
#include <QObject>
#include <Qt3DInput/QMouseEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *paintevent);
    void mouseDoubleClickEvent ( QMouseEvent *mouseevent );
    void startplay();

private slots:
    void on_pushButton_start_puse_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_pre_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_open_clicked();

    void on_hSlider_voice_valueChanged(int value);

    //void on_hSlider_progressBar_valueChanged(int value);使用这个会导致播放文件变卡

    void on_hSlider_progressBar_sliderMoved(int position);

    void on_pushButton_playorder_clicked();

    void on_pushButton_voicestates_clicked();

    void on_pushButton_fullscreen_clicked();

    void onItemDBCliked(const QModelIndex &index);

    void on_pushButton_screenshots_clicked();

    void sliderClicked();

    void on_pushButton_faster_clicked();


    void on_pushButton_preer_clicked();

private:
    Ui::Widget *ui;
    QMediaPlayer *myplayer = nullptr;
    QMediaPlaylist *myplayerlist = nullptr;
    QMediaPlaylist *randomplaylist =nullptr;
    QVideoWidget *mywidget = nullptr;
    QSqlQueryModel *model = nullptr;//包含id,name,url所有属性的model
    QSqlQueryModel *model2 = nullptr;//只有name属性的model
    QSqlDatabase db;
    QSqlQuery query;


    //QMouseEvent *event = nullptr;
    bool isstart = false;
    bool ismute =false;
    bool isfullscreen = false;
    bool isorderseted = false;
    int volume = 50;
    QString playorder = "order";
};

#endif // WIDGET_H
