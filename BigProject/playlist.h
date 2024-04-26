
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include "song.h"

using namespace std;

class Playlist {
private:
    vector<Song> songs;

public:
    Playlist();
    void add(const Song& song);
    void clear();
    void remove(const Song& song);
    void generateRandom(int n);

};
#endif // PLAYLIST_H
