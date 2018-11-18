#include "playermainwin.h"
#include "ui_playermainwin.h"
#include <QHBoxLayout>
#include <QFile>

PlayerMainWin::PlayerMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayerMainWin)
{
    vlcPlayer = NULL;
    vlcInstance = libvlc_new(0, NULL);
    if (vlcInstance == NULL) {
        exit(1);
    }

    ui->setupUi(this);
    initUI();
    initChannelList();
    QObject::connect(channelList,SIGNAL(currentRowChanged(int)),this,SLOT(initVlcAndPlay(int)));
}

void PlayerMainWin::initUI()
{
    //central widget
    QWidget *widget = new QWidget;
    this->setCentralWidget(widget);
    this->setWindowTitle("HLSPlayer");

    //video widget
    videoWidget = new QVideoWidget(widget);
    videoWidget->setAutoFillBackground( true );
    QPalette plt = palette();
    plt.setColor( QPalette::Window, Qt::black );
    videoWidget->setPalette( plt );

    //listwidget
    channelList = new QListWidget();
    channelList->setMinimumWidth(90);
    channelList->setMaximumWidth(90);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(2);
    mainLayout->addWidget(videoWidget);
    mainLayout->addWidget(channelList);
    widget->setLayout(mainLayout);
}

void PlayerMainWin::fullScreen()
{
    videoWidget->setFullScreen(true);
}

void PlayerMainWin::initVlcAndPlay(int idx)
{
    const char *url = channelInfo[idx].url.c_str();
    stop();
    /* Stop if something is playing */
    if (vlcPlayer && libvlc_media_player_is_playing(vlcPlayer))
    {
       stop();
    }

    /* Create a new Media */
    libvlc_media_t *vlcMedia = libvlc_media_new_location(vlcInstance, url);
    if (!vlcMedia)
    {
        return;
    }

    /* Create a new libvlc player */
    vlcPlayer = libvlc_media_player_new_from_media (vlcMedia);

    libvlc_media_release(vlcMedia);

    libvlc_media_player_set_xwindow(vlcPlayer, videoWidget->winId());

    /*start play */
    libvlc_audio_set_volume(vlcPlayer,100);
    libvlc_delay(0);
    libvlc_media_player_play (vlcPlayer);
    fullScreen();

}

void PlayerMainWin::stop() {
    if(vlcPlayer) {
        /* stop the media player */
        libvlc_media_player_stop(vlcPlayer);

        /* release the media player */
        libvlc_media_player_release(vlcPlayer);

        /* Reset application values */
        vlcPlayer = NULL;
    }
}


bool PlayerMainWin::initChannelList()
{
    for(int i=0; i<CHANNEL_NUM-1; i++)
    {
        channelInfo[i].name = "";
        channelInfo[i].url = "";
        channelInfo[i].enable = false;
    }

    QFile file("./config");
    int ret = file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(ret < 0)
    {
        exit(-1);
    }
    int idx = 0;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        std::string str(line);
        if (str.length() != 0)
        {
            str = str.substr(0,str.length()-1);
            int comma_idx = str.find(",");
            std::string buffer = str.substr(comma_idx+1);
            std::string str_url = str.substr(0,comma_idx);

            channelInfo[idx].name = buffer;
            channelInfo[idx].url = str_url;
            channelInfo[idx].enable = true;
            idx ++ ;
        }
    }

    for(int i=0; i< CHANNEL_NUM-1; i++)
    {
        if(channelInfo[i].enable)
        {
            QListWidgetItem *item = new QListWidgetItem();
            item->setText(channelInfo[i].name.c_str());
            channelList->addItem(item);
        }
    }
}

PlayerMainWin::~PlayerMainWin()
{
    delete ui;
    if (vlcInstance)
    {
        libvlc_release(vlcInstance);
    }
}
