
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include"song.h"

using namespace std;

class Repository
{protected:
    vector<Song>& getSongs();
private:
    vector<Song> song;
public:

    Repository();
    //a
    Repository(const Repository &other)=delete; //copy constructor disabled
    Repository & operator=(const Repository &other)=delete; //asignment operator disabled
    //b
    virtual void store(const Song& s);
    //c
    virtual const Song& find(string title, string artist);
    //d
    virtual void remove(const Song& s);
    //e
    virtual vector<Song>& getall();
};

#endif // REPOSITORY_H
