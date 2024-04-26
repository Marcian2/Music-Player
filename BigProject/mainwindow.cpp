#include "mainwindow.h"
#include <iostream>
#include <QMessageLogger>
#include <vector>
#include <utility>
#include <algorithm>
#include <QKeyEvent>
MainWindow::MainWindow(SongController* ctrl,QWidget* parent)
    : QMainWindow(parent)
{
    m_ctrl=ctrl;
    this->setupUI();

}

MainWindow::~MainWindow()
{
    delete m_buttonsLayout1;
    delete m_leftVLayout;
    delete m_middleVLayout;
    delete m_buttonsLayout2;
    delete m_rightVLayout;
    delete m_mainLayout;
    delete m_centralWidget;

}

void MainWindow::setGeo()
{
    m_add->setGeometry(QRect(QPoint(5, 3), QSize(77, 23)));
    m_delete->setGeometry(QRect(QPoint(6, 1), QSize(77, 23)));
    m_update->setGeometry(QRect(QPoint(7, 2), QSize(77, 23)));
    m_filter->setGeometry(QRect(QPoint(8, 3), QSize(77, 23)));
}

void MainWindow::onUpdateButton()
{
    QMessageBox::information(this, "Message", "Not implemented yet", QMessageBox::Ok);
}

void MainWindow::onFilterButton()
{
    QMessageBox::information(this, "Message", "Not implemented yet", QMessageBox::Ok);
}

void MainWindow::onMiddleButton()
{
    qDebug("The button does not work without selecting a song");
    if(!m_listSongs->selectedItems().empty())
        m_listPlaylist->addItem(m_listSongs->item(m_listSongs->row(m_listSongs->selectedItems()[0]))->text());
    else QMessageBox::information(this, "Message", "Select a song!", QMessageBox::Ok);
}


void MainWindow::setupUI()
{
    m_centralWidget = new QWidget();
    m_leftVLayout = new QVBoxLayout();

    m_listSongsLabel = new QLabel("All songs:");
    m_listSongs = new QListWidget();

    m_leftFormLayout = new QFormLayout();

    m_titleLable = new QLabel("Title:");
    m_titleText = new QLineEdit();

    m_artistLable = new QLabel("Artist:");
    m_artistText = new QLineEdit();

    m_durationLable = new QLabel("Duration:");
    m_durationText = new QLineEdit();

    m_linkLable = new QLabel("Link:");
    m_linkText = new QLineEdit();

    m_leftFormLayout->addRow(m_titleLable, m_titleText);
    m_leftFormLayout->addRow(m_artistLable, m_artistText);
    m_leftFormLayout->addRow(m_durationLable, m_durationText);
    m_leftFormLayout->addRow(m_linkLable, m_linkText);

    m_leftVLayout->addWidget(m_listSongsLabel);
    m_leftVLayout->addWidget(m_listSongs);


    //m_centralWidget->setLayout(m_leftVLayout);
    //this->setCentralWidget(m_centralWidget);

    m_buttonsLayout1 = new QHBoxLayout;
    m_buttonsLayout2 = new QHBoxLayout;

    m_add = new QPushButton("Add");
    m_add->setFixedSize(QSize(77,23));

    //connect(m_add, SIGNAL(clicked()), this, SLOT(exit_app()));
    QObject::connect(m_add, &QPushButton::released, this, &MainWindow::onAddButton);
    m_buttonsLayout1->addWidget(m_add);




    m_delete = new QPushButton("Delete");
    m_delete->setFixedSize(QSize(77, 23));
    QObject::connect(m_delete, &QPushButton::released, this, &MainWindow::onDeleteButton);
    m_buttonsLayout1->addWidget(m_delete);



    m_update = new QPushButton("Update");
    m_update->setFixedSize(QSize(77, 23));
    QObject::connect(m_update, &QPushButton::released, this, &MainWindow::onUpdateButton);
    m_buttonsLayout1->addWidget(m_update);



    m_filter = new QPushButton("Filter");
    m_filter->setFixedSize(QSize(77, 23));
    m_leftVLayout->addLayout(m_leftFormLayout);
    m_leftVLayout->addLayout(m_buttonsLayout1);
    QObject::connect(m_filter, &QPushButton::released, this, &MainWindow::onFilterButton);
    m_leftVLayout->addWidget(m_filter, 0, Qt::AlignCenter);


    //m_leftFormLayout->addRow(m_add, m_delete);
    //m_leftFormLayout->addRow(m_update, m_filter);

    // middle layout
    m_middleVLayout = new QVBoxLayout();
    m_middleFormLayout = new QFormLayout();

    m_toPlaylistButton = new QPushButton(">");
    m_toPlaylistButton->setFixedSize(QSize(77, 23));
    QObject::connect(m_toPlaylistButton, &QPushButton::released, this, &MainWindow::onMiddleButton);

    m_middleVLayout->addWidget(m_toPlaylistButton, 0,Qt::AlignVCenter);
    m_middleVLayout->addLayout(m_middleFormLayout);

    // right layout
    m_rightVLayout = new QVBoxLayout();
    m_rightFormLayout = new QFormLayout();

    m_listPlaylistLabel = new QLabel("Playlist:");
    m_listPlaylist = new QListWidget();



    m_rightVLayout->addWidget(m_listPlaylistLabel);
    m_rightVLayout->addWidget(m_listPlaylist);
    m_rightVLayout->addLayout(m_rightFormLayout);


    m_play = new QPushButton("Play");
    //m_play->setFixedSize(QSize(77, 23));
    m_next = new QPushButton("Next");
    //m_next->setFixedSize(QSize(77, 23));
    //m_rightFormLayout->addRow(m_listPlaylistLabel, m_listPlaylist);
    m_mainLayout = new QHBoxLayout;

    m_buttonsLayout2->addWidget(m_play);
    m_buttonsLayout2->addWidget(m_next);



    m_mainLayout->addLayout(m_leftVLayout);
    m_mainLayout->addLayout(m_middleVLayout);

    m_rightVLayout->addLayout(m_buttonsLayout2);

    m_mainLayout->addLayout(m_rightVLayout);
    m_centralWidget->setLayout(m_mainLayout);
    this->setCentralWidget(m_centralWidget);

}


void MainWindow::onAddButton() {
    QString title = m_titleText->text();
    QString artist = m_artistText->text();
    QString duration = m_durationText->text();
    QString link = m_linkText->text();

    if (title.isEmpty() || artist.isEmpty() || duration.isEmpty() || link.isEmpty()) {
        QMessageBox::information(this, "Message", "Fill in all the fields!", QMessageBox::Ok);
    } else {
        std::vector<std::string> lyrics;
        lyrics.push_back("Lyrics1");
        lyrics.push_back("Lyrics2");

        m_ctrl->add(artist.toStdString(), title.toStdString(), duration.toInt(), lyrics, link.toStdString());

        m_listSongs->addItem("Song: " + title + " || Artist: " + artist + " || Duration: " + duration + " || Link: " + link);

    }
}

void MainWindow::onDeleteButton()
{
    if (!m_listSongs->selectedItems().empty()) {
        int index = m_listSongs->currentRow();
        QListWidgetItem* selectedItem = m_listSongs->takeItem(index);
        QString songInfo = selectedItem->text();
        QString artist, title;

        // Extract artist and title from the song information
        int artistIndex = songInfo.indexOf("made by ") + 8;
        int titleIndex = songInfo.indexOf("Song: ") + 6;
        int titleEndIndex = songInfo.indexOf(" || made by ") - 1;
        artist = songInfo.mid(artistIndex, titleIndex - artistIndex - 12);
        title = songInfo.mid(titleIndex, titleEndIndex - titleIndex + 1);

        // Remove the song using the controller
        m_ctrl->deletet(artist.toStdString(), title.toStdString(), {}, 0, "");

        delete selectedItem;
    }
    else {
        QMessageBox::information(this, "Message", "Select a song!", QMessageBox::Ok);
    }
}





