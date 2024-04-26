
#include "playlist.h"

Playlist::Playlist()
{

}

void Playlist::add(const Song &song)
{
    songs.push_back(song);
}
void Playlist::clear()
{
    songs.clear();
}

void Playlist::remove(const Song &song)
{
    for (auto it = songs.begin(); it != songs.end(); ++it)
    {if (it->getArtist() == song.getArtist() && it->getTitle() == song.getTitle())
        {   songs.erase(it);
            break;
        }
    }

}

