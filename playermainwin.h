#ifndef PLAYERMAINWIN_H
#define PLAYERMAINWIN_H

#ifndef INT64_C
#define INT64_C
#define UINT64_C
#endif

#include <QMainWindow>
#include <QUrl>
#include <QVideoWidget>
#include <QListWidget>
#define CHANNEL_NUM 100

extern "C"
{
    #include <vlc.h>
}

namespace Ui {
class PlayerMainWin;
}

class PlayerMainWin : public QMainWindow
{
    Q_OBJECT

    struct ChannelInfo
    {
        std::string name;
        std::string url;
        bool enable;
    };

public:
    explicit PlayerMainWin(QWidget *parent = 0);
    ~PlayerMainWin();

private:
    Ui::PlayerMainWin *ui;
    QVideoWidget *videoWidget;
    QListWidget * channelList;

    libvlc_instance_t *_vlcinstance;
    libvlc_media_player_t *_mp;
    libvlc_media_t *_m;

    ChannelInfo channelInfo[CHANNEL_NUM];
    libvlc_instance_t *vlcInstance;
    libvlc_media_player_t *vlcPlayer;
private slots:
    void fullScreen();
    void initVlcAndPlay(int);

private:
    bool initChannelList();
    void stop();
    void initUI();
};

#endif // PLAYERMAINWIN_H
