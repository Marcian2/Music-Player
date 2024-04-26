#include "song.h"

#include<iostream>
#include<string>
using namespace std;
#include<vector>


Song::Song(string artist, string title, vector<string> Lyrics,int year, string url) {
    this->artist = artist;
    this->title = title;
    this->Lyrics= Lyrics;
    this->year = year;
    this->url = url;
}

string Song::getArtist() const
{
    return artist;
}

string Song::getTitle() const
{
    return title;
}

vector<string> Song::getLyrics() const
{
    return Lyrics;
}

void Song::setArtist( string artist)
{
    this->artist = artist;
}

void Song::setTitle(const string title)
{
    this->title=title;
}

void Song::setLyrics(vector<string> Lyrics)
{
    this->Lyrics=Lyrics;
}

void Song::setUrl(string url){
    this->url=url;
}

void Song::setYear(int year){
    this->year=year;
}

int Song::getyear() const
{
    return year;
}

string Song::geturl() const{
    return url;
}

Song::~Song()
{
    return;
}

bool Song::operator==(const Song &other) const
{
        return artist == other.artist &&
               title == other.title &&
               Lyrics == other.Lyrics &&
               year == other.year &&
               url == other.url;

}




