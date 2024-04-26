
#include "Song.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QListWidget>
#include <QKeyEvent>
#include "songcontroller.h"
class Song;
class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(SongController* m_ctrl,QWidget* parent = nullptr);
    ~MainWindow();
    void setGeo();
    void updateSongList();
public slots:
    void onAddButton();
    void onUpdateButton();
    void onFilterButton();
    void onDeleteButton();
    void onMiddleButton();

private:
    void setupUI();
    SongController* m_ctrl;


    QHBoxLayout* m_mainLayout;
    QHBoxLayout* m_buttonsLayout1;
    QHBoxLayout* m_buttonsLayout2;


    std::vector<Song> m_songPlayList;

    QWidget* m_centralWidget;
    QVBoxLayout* m_leftVLayout;
    QFormLayout* m_leftFormLayout;

    // form layout
    QLabel* m_titleLable;
    QLineEdit* m_titleText;

    QLabel* m_artistLable;
    QLineEdit* m_artistText;

    QLabel* m_durationLable;
    QLineEdit* m_durationText;

    QLabel* m_linkLable;
    QLineEdit* m_linkText;

    QLabel* m_listSongsLabel;
    //QTextEdit* m_listSongs;
    QListWidget* m_listSongs;


    QPushButton* m_add;
    QPushButton* m_delete;
    QPushButton* m_update;
    QPushButton* m_filter;

    // middle layout
    QVBoxLayout* m_middleVLayout;
    QFormLayout* m_middleFormLayout;

    //form layout
    QPushButton* m_toPlaylistButton;

    // right layout
    QVBoxLayout* m_rightVLayout;
    QFormLayout* m_rightFormLayout;

    //form layout
    QLabel* m_listPlaylistLabel;
    QListWidget* m_listPlaylist;

    QPushButton* m_play;
    QPushButton* m_next;
};

