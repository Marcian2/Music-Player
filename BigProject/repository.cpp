
#include "repository.h"
#include<string>
#include"song.h"
#include<stdexcept>
#include<vector>
#include"exception.h"
#include<algorithm>
using namespace  std;

//song is the vector name from repository, Song is the name of the class in the header

vector<Song> &Repository::getSongs()
{
    return song;
}

Repository::Repository()
{

}

void Repository::store(const Song &s)
{
    for(int i=0;i<song.size();i++)
        if(song[i].getArtist()==s.getArtist() && song[i].getTitle()==s.getTitle())
            throw SongException("A song already exists"); // fix this by giving the artist and title

    song.push_back(s);
}

const Song &Repository::find(string artist, string title)
{

    auto it = find_if(song.begin(),song.end(),[artist,title](const Song &song){return song.getTitle()==title && song.getArtist()==artist;});
    if(it == song.end()){
        throw SongException("A song doesnt exist"); // same as above ask at lab

    }
    return *it;
}

void Repository::remove(const Song &s)
{   int j=0;
    for(int i=0;i<=song.size();i++)
        if(song[i].getArtist()==s.getArtist() && song[i].getTitle()==s.getTitle())
        {song.erase(song.begin()+i);
            j=1;
            break;}
    if(j==1)
        throw SongException("A song does not exist");
}

vector<Song> &Repository::getall()
{
    return song;
}

