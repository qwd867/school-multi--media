#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建对象
    myplayer = new QMediaPlayer;
    myplayerlist = new QMediaPlaylist;
    randomplaylist =new QMediaPlaylist;
    mywidget = new QVideoWidget(ui->label);

    mywidget->resize(ui->label->size());//设置播放窗口大小==label标签大小

    //myplayer赋值初始化
    myplayer->setPlaylist(myplayerlist);//设置播放列表
    myplayer->setVideoOutput(mywidget);//设置输出显示的位置


    setWindowTitle("音视频播放器");
    myplayer->setVolume(50);//初始化声音大小50
    // !!!!!!!!!!此处可修改信号与槽!!!!!!!!!!!!!!
    ui->hSlider_voice->setValue(50);//初始化滑动条大小50

    //固定进度条长度：ui->hSlider_progressBar->setRange(0,100000);

    //变换进度条长度
    connect(myplayer,&QMediaPlayer::durationChanged,ui->hSlider_progressBar,[&](qint64 temp){
         ui->hSlider_progressBar->setRange(0,(int)temp);
    });

    //进度条位置变化
    connect(myplayer,&QMediaPlayer::positionChanged,ui->hSlider_progressBar,&QSlider::setValue);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    mywidget->resize(ui->label->size());
}


//20220829 高博洋 优化:开始播放相关事件整合
void Widget::startplay()
{
    ui->pushButton_start_puse->setStyleSheet("QPushButton#pushButton_start_puse{border-image:url(:/new/prefix1/image/暂停.png)}");
    isstart = true;
    myplayer->play();

    ui->pushButton_stop->setEnabled(true);
}

void Widget::on_pushButton_start_puse_clicked()
{
    if(isstart)
    {
        ui->pushButton_start_puse->setStyleSheet("QPushButton#pushButton_start_puse{border-image:url(:/new/prefix1/image/播放.png)}");
        isstart = false;
        myplayer->pause();
    }
    else
    {
        //点击播放按钮后，开始播放文件
        startplay();
    }
}

void Widget::on_pushButton_stop_clicked()
{
    ui->pushButton_start_puse->setStyleSheet("QPushButton#pushButton_start_puse{border-image:url(:/new/prefix1/image/播放.png)}");
    isstart = false;
    myplayer->stop();

    ui->pushButton_stop->setEnabled(false);
}

void Widget::on_pushButton_pre_clicked()
{
    myplayer->stop();

    //20220830 高博洋 优化:使用myplayer而不是myplayerlist,否则randomplaylist只能播放一个
    myplayer->playlist()->previous();
    //myplayerlist->previous();

    //20220829 高博洋 优化:点击“上一个”按钮后立即播放文件
    startplay();

}

void Widget::on_pushButton_next_clicked()
{
    myplayer->stop();

    //20220830 高博洋 优化:使用myplayer而不是myplayerlist,否则randomplaylist只能播放一个
    myplayer->playlist()->next();
    //myplayerlist->next();

    //20220829 高博洋 优化：点击“下一个”按钮后立即播放文件
    startplay();
}

void Widget::on_pushButton_open_clicked()
{
    QStringList mylist=QFileDialog::getOpenFileNames(this,"选择播放资源","C:\\Users\\user\\Desktop","allfiles(*.*);;"
                                                                                                  "MP3(*.mp3);;"
                                                                                                  "MP4(*.mp4);;");
    myplayerlist->clear();
    randomplaylist ->clear();

    for(const auto & k : mylist)
    {
        myplayerlist->addMedia(QUrl(k));
        randomplaylist->addMedia(QUrl(k));

       qDebug()<<"open正在调用";
    }

    //20220829 高博洋 优化：打开文件后立即播放文件
    startplay();

}

void Widget::on_hSlider_voice_valueChanged(int value)
{
    myplayer->setVolume(value);
}

/*不应该使用此函数进行进度条拖动，否则视频会变得很卡
  void Widget::on_hSlider_progressBar_valueChanged(int value)
{
    //加了这行代码后视频播放就变得一卡一卡的！！！！
   myplayer->setPosition(value);
   qDebug()<<"valuechanged正在运行";
}*/

void Widget::on_hSlider_progressBar_sliderMoved(int position)
{
    myplayer->setPosition(position);
    qDebug()<<"valuechanged正在运行";
}

void Widget::on_pushButton_playorder_clicked()
{

    if("order"==playorder)
    {
       // qDebug()<<"切换为随机播放";
        playorder = "shuffle";
        ui->pushButton_playorder->setStyleSheet("QPushButton#pushButton_playorder{border-image:url(:/new/prefix1/image/随机播放.png)}");
        randomplaylist->shuffle();
        myplayer->setPlaylist(randomplaylist);
        qDebug()<<"正在随机播放";
        startplay();
    }
    else if("shuffle"==playorder)
    {
        //qDebug()<<"切换为顺序播放";
        playorder="order";
        ui->pushButton_playorder->setStyleSheet("QPushButton#pushButton_playorder{border-image:url(:/new/prefix1/image/顺序播放.png)}");
        myplayer->setPlaylist(myplayerlist);
        qDebug()<<"正在顺序播放";
        startplay();
    }

}
