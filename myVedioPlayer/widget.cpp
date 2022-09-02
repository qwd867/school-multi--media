#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //注册数据库
    qDebug()<<QSqlDatabase::drivers();  //打印看看（已经存在的）驱动是什么
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("media.db");
    qDebug()<<"创建了media.ab数据库";


    //打开数据库
    bool dbok = db.open();
    if(dbok)
    {
        qDebug()<<"成功打开数据库";
    }
    else
    {
        qDebug()<<db.lastError();
        exit(-1);
    }
    //创建表
    query=QSqlQuery(db);//20220830 高博洋 遇到问题：必须加这一行，否则会报错：QSqlQuery::exec: database not open
    query.exec("create table if not exists media_info(media_id integer primary key autoincrement,name text, url text)");
    qDebug()<<"成功创建media_info表";


    //20220830 高博洋 显示数据库媒体在播放列表
    model = new QSqlQueryModel;
    model->setQuery("select * from media_info order by media_id asc");
    model2 = new QSqlQueryModel;
    model2->setQuery("select name from media_info order by media_id asc");
    ui->tableView->setModel(model2);

    //创建对象
    myplayer = new QMediaPlayer;
    myplayerlist = new QMediaPlaylist;
    randomplaylist =new QMediaPlaylist;
    mywidget = new QVideoWidget(ui->label);

    mywidget->resize(ui->label->size());//设置播放窗口大小==label标签大小

    //清理播放list
    myplayerlist->clear();
    randomplaylist ->clear();

    //myplayerlist初始化

    QString url;
    QStringList mylist;
    QString str=QString("select url from media_info order by media_id asc");//取出url
    query.exec(str);

    while (query.next())
        {
            url = query.value("url").toString();
            mylist.append(url);                //如果有数据，取第一列,也就是url，添加到list
        }

    QSqlRecord record = model->record();

    for(const auto & k : mylist)
    {
        myplayerlist->addMedia(QUrl(k));
        randomplaylist->addMedia(QUrl(k));
        qDebug()<<"数据库赋值播放列表完毕";
    }

    //myplayer赋值初始化
    myplayer->setPlaylist(myplayerlist);//设置播放列表
    myplayer->setVideoOutput(mywidget);//设置输出显示的位置


    setWindowTitle("音视频播放器");
    myplayer->setVolume(volume);//初始化声音大小50
    // !!!!!!!!!!此处可修改信号与槽!!!!!!!!!!!!!!
    ui->hSlider_voice->setValue(volume);//初始化滑动条大小50

    //固定进度条长度：ui->hSlider_progressBar->setRange(0,100000);

    //变换进度条长度
    connect(myplayer,&QMediaPlayer::durationChanged,ui->hSlider_progressBar,[&](qint64 temp){
         ui->hSlider_progressBar->setRange(0,(int)temp);
    });

    //进度条位置变化
    connect(myplayer,&QMediaPlayer::positionChanged,ui->hSlider_progressBar,&QSlider::setValue);

    //自定义的信号costomSliderClicked()
    connect(ui->hSlider_progressBar,SIGNAL(costomSliderClicked()),this,SLOT(sliderClicked()));

    //监听播放列表的双击
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(onItemDBCliked(QModelIndex)));

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
    //判断播放顺序改变后，改变列表是否已经设置完成
    if(!isorderseted)
    {
        isorderseted=true;

        if("shuffle"==playorder)
        {
            myplayer->setPlaylist(randomplaylist);
        }
        else if("order"==playorder)
        {
            myplayer->setPlaylist(myplayerlist);
        }
    }

    //20220830 高博洋 优化:使用myplayer而不是myplayerlist,否则randomplaylist只能播放一个
    myplayer->playlist()->previous();
    //myplayerlist->previous();

    //20220829 高博洋 优化:点击“上一个”按钮后立即播放文件
    startplay();

}

void Widget::on_pushButton_next_clicked()
{
    myplayer->stop();

    //判断播放顺序改变后，改变列表是否已经设置完成
    if(!isorderseted)
    {
        isorderseted=true;

        if("shuffle"==playorder)
        {
            myplayer->setPlaylist(randomplaylist);
        }
        else if("order"==playorder)
        {
            myplayer->setPlaylist(myplayerlist);
        }
    }



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



    for(const auto & k : mylist)
    {
        myplayerlist->addMedia(QUrl(k));
        randomplaylist->addMedia(QUrl(k));
        qDebug()<<"open正在调用";

        //20220830 高博洋 数据库添加数据
        /*----获取视频文件的名字---*/
        int index=-1, lastIndex;
        do{
           lastIndex = index;
           index = k.indexOf('/',index+1);
        }while(index!=-1);
        QString name = k.right(k.length()-lastIndex-1);
        /*---------------------*/
        QString cmd = QString("insert into media_info(name,url) values('%1','%2')").arg(name).arg(k);
        if(!query.exec(cmd)){
              qDebug()<<"Error 2 (insert error)"<<query.lastError().text();
              return;
        }
        else
        {
            model->setQuery("select * from media_info");
            model2->setQuery("select name from media_info");
            ui->tableView->setModel(model2);
            qDebug()<<"媒体添加成功";
        }
    }

    //打开文件添加歌曲后，数据库内歌曲会变化，播放列表也应根据数据库对应变化
    model2->setQuery("select name from media_info order by media_id asc");
    ui->tableView->setModel(model2);

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
        isorderseted = false;

        //20220830 高博洋 优化：将下面这行代码放置到on_pushButton_pre_clicked和on_pushButton_next_clicked中，
        //                    点击其中一个按钮后myplayer的playlist再发生改变，以便点击playorder按钮时不发生歌曲切换
        //myplayer->setPlaylist(randomplaylist);

        qDebug()<<"正在随机播放";

        //20220830 高博洋 优化：暂停时候切换播放顺序不立即播放
        //startplay();
    }
    else if("shuffle"==playorder)
    {
        //qDebug()<<"切换为顺序播放";
        playorder = "order";
        ui->pushButton_playorder->setStyleSheet("QPushButton#pushButton_playorder{border-image:url(:/new/prefix1/image/顺序播放.png)}");
        isorderseted = false;

        //20220830 高博洋 优化：将下面这行代码放置到on_pushButton_pre_clicked和on_pushButton_next_clicked中，
        //                    点击其中一个按钮后myplayer的playlist再发生改变，以便点击playorder按钮时不发生歌曲切换
        //myplayer->setPlaylist(myplayerlist);

        qDebug()<<"正在顺序播放";

        //20220830 高博洋 优化：暂停时候切换播放顺序不立即播放
        //startplay();
    }

}

void Widget::on_pushButton_voicestates_clicked()
{
    if(!ismute)//未静音时点击
    {
        ui->pushButton_voicestates->setStyleSheet("QPushButton#pushButton_voicestates{border-image:url(:/new/prefix1/image/声音静音.png)}");
        ismute = true;
        volume = myplayer->volume();//保存静音前音量
        myplayer->setVolume(0);
        ui->hSlider_voice->setValue(0);//设置滑动条声音为0
        qDebug()<<"已静音";
    }
    else//静音时点击
    {
        ui->pushButton_voicestates->setStyleSheet("QPushButton#pushButton_voicestates{border-image:url(:/new/prefix1/image/声音.png)}");
        ismute = false;
        myplayer->setVolume(volume);//恢复静音前音量
        ui->hSlider_voice->setValue(volume);
        qDebug()<<"取消静音";
    }
}

//按钮点击全屏
void Widget::on_pushButton_fullscreen_clicked()
{
    if(!isfullscreen)
    {
        ui->pushButton_fullscreen->setStyleSheet("QPushButton#pushButton_fullscreen{border-image:url(:/new/prefix1/image/退出全屏.png)}");
        isfullscreen = true;
        Widget::showFullScreen();
        qDebug()<<"点击全屏";
    }
    else
    {
        ui->pushButton_fullscreen->setStyleSheet("QPushButton#pushButton_fullscreen{border-image:url(:/new/prefix1/image/全屏.png)}");
        isfullscreen = false;
        Widget::showNormal();
        qDebug()<<"取消全屏";
    }
}

//鼠标双击全屏
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(!isfullscreen)
    {
        ui->pushButton_fullscreen->setStyleSheet("QPushButton#pushButton_fullscreen{border-image:url(:/new/prefix1/image/退出全屏.png)}");
        isfullscreen = true;
        Widget::showFullScreen();
        qDebug()<<"点击全屏";
    }
    else
    {
        ui->pushButton_fullscreen->setStyleSheet("QPushButton#pushButton_fullscreen{border-image:url(:/new/prefix1/image/全屏.png)}");
        isfullscreen = false;
        Widget::showNormal();
        qDebug()<<"取消全屏";
    }
}

/*
 * 双击播放列表，播放相应视频
*/
void Widget::onItemDBCliked(const QModelIndex &index){
    qDebug()<<index.row();  //打印用户点击的第几行
    QSqlRecord record = model->record(index.row());  //得到在数据库表中是第几条记录

    //测试，并且URL中的中文能够正常输出
    qDebug()<<"媒体文件信息：  name："<<record.value("name").toString()<<"   URL:"<<record.value("url").toString();

    int media_id=record.value("media_id").toInt();
    //播放相应视频，这里应该用绝对路径（否则选择播放源的功能就不能在整个文件管理器进行了）
    QString path = record.value("url").toString();
    path = QDir::toNativeSeparators(path);
    //myplayer->setMedia(QMediaContent(QUrl::fromLocalFile(path)));




    QString url;
    QStringList mylist1;
    QString str=QString("select url from media_info where media_id>=%1 order by media_id asc").arg(media_id);//取出url//此处field()数据库指令执行错误会导致“进入whiel循环体”
                                                                          //“click数据库赋值播放列表完毕”无法执行,需要正确设置自定义排序功能
    QString str2=QString("select url from media_info where media_id<%1 order by media_id asc").arg(media_id);

    //设置str
    query.exec(str);
    qDebug()<<"数据库select完毕";
    while (query.next())
    {
            url = query.value("url").toString();
            mylist1.append(url);                //如果有数据，取第一列,也就是shidu，添加到list
            qDebug()<<"进入while循环体";
    }

    if(myplayerlist->clear())
    {
        qDebug()<<"myplayerlist->clear";
    }


    //设置str2
    query.exec(str2);
    qDebug()<<"数据库select完毕";
    while (query.next())
    {
            url = query.value("url").toString();
            mylist1.append(url);                //如果有数据，取第一列,也就是shidu，添加到list
            qDebug()<<"进入while循环体";
    }
    //此处没有上面的claer函数，因为要从上面往下面加
    for(const auto & k : mylist1)
    {
        myplayerlist->addMedia(QUrl(k));
        //randomplaylist->addMedia(QUrl(k));
        qDebug()<<"click数据库赋值播放列表完毕";
    }


    myplayer->setPlaylist(myplayerlist);
    qDebug()<<"这句执行了";




    //如果上面的代码能找到数据库自定义排序函数，删除这行代码
   // isorderseted = false;

    startplay();
}

//20220830 李俊 截图功能
void Widget::on_pushButton_screenshots_clicked()
{
    //QPixmap pixmap = QPixmap::grabWidget(this);
    QPixmap pixmap = QPixmap::grabWindow(this->winId());
    pixmap.save("d:\\b.png","png");
    qDebug()<<"已截图保存";
}

/*
* slider点击事件发生后，改变视频的进度
*/
void Widget::sliderClicked(){
    myplayer->setPosition(ui->hSlider_progressBar->value());
}


