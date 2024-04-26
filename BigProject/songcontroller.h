
#ifndef SONGCONTROLLER_H
#define SONGCONTROLLER_H
#include"repository.h"
#include "action.h"
#include <stack>

class SongController
{public:
    Repository* repo;
    stack<Action*> undoStack;
    stack<Action*> redoStack;
    void clearRedoStack();
public:
    SongController(Repository *r);
    //b
    void add(string artist, string title,int year ,vector<string> Lyrics=vector<string>(), string url=" ");
    //c
    const Song& find(string title, string artist);
    //d
    vector<Song> getFilesSortedByArtist(bool increasingOrder)const;
    //e
    vector<Song> getFilesSortedByTitle(bool increasingOrder) const ;
    void deletet(string artist, string title,vector<string> Lyrics ,int year, string url);
    Song removebyindex(int n);
    Song findbyindex(int n);
    //undo redo
    void redo();
    void undo();
};




#endif // SONGCONTROLLER_H
