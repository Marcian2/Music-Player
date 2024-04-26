
#include"exception.h"
#include"songcontroller.h"
#include"assert.h"

void testAdd() {

    Repository repo;
    SongController controller(&repo);
    controller.add("Artist 1", "Title 1", 2023, {}, "url");
    assert(repo.find("Title 1", "Artist 1").getTitle() == "Title 1");
    try {
        controller.add("Artist 1", "Title 1", 2023, {}, "url");
        assert(false);
    } catch (const SongException& ex) {
       throw SongException(ex);
    }
}

void testFind() {

    Repository repo;
    Song song1("Artist 1", "Title 1", {}, 2023, "url");
    Song song2("Artist 2", "Title 2", {}, 2023, "url");
    repo.store(song1);
    repo.store(song2);
    SongController controller(&repo);
    assert(controller.find("Title 1", "Artist 1") == song1);
    assert(controller.find("Title 2", "Artist 2") == song2);
    try {
        controller.find("Title 3", "Artist 3");
        assert(false);
    } catch (const SongException& ex) {
        throw SongException(ex);
    }
}

void testGetFilesSortedByArtist() {
    Repository repo;
    Song song1("Artist B", "Title 1", {}, 2023, "url");
    Song song2("Artist A", "Title 2", {}, 2023, "url");
    Song song3("Artist C", "Title 3", {}, 2023, "url");
    repo.store(song1);
    repo.store(song2);
    repo.store(song3);
    SongController controller(&repo);
    vector<Song> sortedSongs = controller.getFilesSortedByArtist(true);
    assert(sortedSongs[0] == song2);
    assert(sortedSongs[1] == song1);
    assert(sortedSongs[2] == song3);
}

void testGetFilesSortedByTitle() {
    Repository repo;
    Song song1("Artist 1", "Title C", {}, 2023, "url");
    Song song2("Artist 2", "Title A", {}, 2023, "url");
    Song song3("Artist 3", "Title B", {}, 2023, "url");
    repo.store(song1);
    repo.store(song2);
    repo.store(song3);

    SongController controller(&repo);
    vector<Song> sortedSongs = controller.getFilesSortedByTitle(true);
    assert(sortedSongs[0] == song2);
    assert(sortedSongs[1] == song3);
    assert(sortedSongs[2] == song1);
}

void testDelete() {

    Repository repo;
    Song song1("Artist 1", "Title 1", {}, 2023, "url");
    Song song2("Artist 2", "Title 2", {}, 2023, "url");
    repo.store(song1);
    repo.store(song2);
    SongController controller(&repo);
    controller.deletet("Artist 1", "Title 1", {}, 2023, "url");
    try {
        repo.find("Title 1", "Artist 1");
        assert(false);  // This line should not be reached
    } catch (const SongException& ex) {
        throw SongException(ex);
    }
}


