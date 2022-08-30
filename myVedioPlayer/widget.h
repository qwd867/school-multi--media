#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QFileDialog>
#include <QString>

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
    void paintEvent(QPaintEvent *event);
    void startplay();

private slots:
    void on_pushButton_start_puse_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_pre_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_open_clicked();

    void on_hSlider_voice_valueChanged(int value);

    //void on_hSlider_progressBar_valueChanged(int value);

    void on_hSlider_progressBar_sliderMoved(int position);

    void on_pushButton_playorder_clicked();

    void on_pushButton_voicestates_clicked();

private:
    Ui::Widget *ui;
    QMediaPlayer *myplayer = nullptr;
    QMediaPlaylist *myplayerlist = nullptr;
    QMediaPlaylist *randomplaylist =nullptr;
    QVideoWidget *mywidget = nullptr;
    bool isstart = false;
    bool ismute =false;
    int volume = 50;
    QString playorder = "order";
};

#endif // WIDGET_H
