
#include "songcontroller.h"
#include "exception.h"
#include<algorithm>
#include <stack>
//helper function
void SongController::clearRedoStack() {
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }
}

SongController::SongController(Repository *r):repo {r}
{

}

void SongController::add(string artist, string title, int year, vector<string> Lyrics, string url)
{
    Song song(artist, title, Lyrics, year, url);
    repo->store(song);
    Action* action = new ActionAdd(*repo, song);
    undoStack.push(action);
    clearRedoStack();

}

void SongController::deletet(string artist, string title,vector<string> Lyrics,  int year, string url)
{
    Song song(artist, title, Lyrics, year, url);
    repo->remove(song);
    Action* action = new ActionDelete(*repo, song);
    undoStack.push(action);
    clearRedoStack();

}

Song SongController::removebyindex(int n)
{
    vector<Song> songs = repo->getall();
    if (n >= 0 && n < songs.size()) {
        Song removedSong = songs[n];
        repo->remove(removedSong);
        Action* action = new ActionDelete(*repo, removedSong);
        undoStack.push(action);
        clearRedoStack();
        return removedSong;
    }
    throw SongException("Invalid index");
}
Song  SongController::findbyindex(int n)
{
    vector<Song> songs = repo->getall();
    return songs[n];
}

const Song &SongController::find(string title, string artist)
{
    for(const Song&song:repo->getall())
        if(song.getArtist()==artist && song.getTitle()==title)
            return song;

    throw SongException("This song does not exist");
}

vector<Song> SongController::getFilesSortedByArtist(bool increasingOrder) const
{
    vector<Song> files= repo->getall();
    // Sort the files by artist's name using lambda expression
    if (increasingOrder) {
        sort(files.begin(), files.end(), [](const Song& a, const Song& b) {
            return a.getArtist() < b.getArtist();
        });
    } else {
        sort(files.begin(), files.end(), [](const Song& a, const Song& b) {
            return a.getArtist() > b.getArtist();
        });
    }

    return files;
}

vector<Song> SongController::getFilesSortedByTitle(bool increasingOrder) const
{
    vector<Song> files= repo->getall();
    // Sort the files by title using lambda expression
    if (increasingOrder) {
        sort(files.begin(), files.end(), [](const Song& a, const Song& b) {
            return a.getTitle() < b.getTitle();
        });
    } else {
        sort(files.begin(), files.end(), [](const Song& a, const Song& b) {
            return a.getTitle() > b.getTitle();
        });
    }

    return files;
}


void SongController::undo()
{
    if (!undoStack.empty()) {
        Action* action = undoStack.top();
        undoStack.pop();
        action->apply();
        redoStack.push(action);
    }
}

void SongController::redo()
{
    if (!redoStack.empty()) {
        Action* action = redoStack.top();
        redoStack.pop();
        action->apply();
        undoStack.push(action);
    }
}



