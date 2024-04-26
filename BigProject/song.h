
#ifndef SONG_H
#define SONG_H
#include<iostream>
#include<string>
using namespace std;
#include<vector>


class Song {
private:
    string artist;
    string title;
    vector<string> Lyrics;
    int year;
    string url;

public:
    Song(string artist, string title, vector<string> Lyrics, int year, string url);
    //getters
    string getArtist() const;
    string getTitle() const;
    vector<string> getLyrics() const;
    int getyear() const;
    string geturl() const;
    //setters
    void setArtist(const string artist) ;
    void setTitle(const string title) ;
    void setLyrics(vector<string> Lyrics) ;
    void setYear(int year);
    void setUrl(const string url);

    ~Song();
    bool operator==(const Song& other) const;


};

#endif // SONG_H
