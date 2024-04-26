
#include "repository.h"
#include "song.h"
#include "assert.h"
#include "exception.h"
void testStore() {
    Repository repo;
    Song song("Artist 1", "Title 1", {}, 2023, "url");
    repo.store(song);
    assert(repo.find("Title 1", "Artist 1") == song);

    try {
        repo.store(song);
        assert(false);
    } catch (const SongException& ex) {
        throw SongException(ex);
    }
}

void testfind() {
    Repository repo;
    Song song1("Artist 1", "Title 1", {}, 2023, "url");
    Song song2("Artist 2", "Title 2", {}, 2023, "url");
    repo.store(song1);
    repo.store(song2);

    assert(repo.find("Title 1", "Artist 1") == song1);
    assert(repo.find("Title 2", "Artist 2") == song2);

    try {
        repo.find("Title 3", "Artist 3");
        assert(false);
    } catch (const SongException& ex) {
        throw SongException(ex);
    }
}

void testRemove() {
    Repository repo;
    Song song1("Artist 1", "Title 1", {}, 2023, "url");
    Song song2("Artist 2", "Title 2", {}, 2023, "url");
    repo.store(song1);
    repo.store(song2);

    repo.remove(song1);

    try {
        repo.find("Title 1", "Artist 1");
        assert(false);
    } catch (const SongException& ex) {
        throw SongException(ex);
    }

    try {
        repo.remove(song1);
        assert(false);
    } catch (const SongException& ex) {
        throw SongException(ex);
    }
}

