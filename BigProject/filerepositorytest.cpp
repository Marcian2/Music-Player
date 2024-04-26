#include "filerepository.h"
#include "song.h"
#include "assert.h"


void testLoad() {

    Filerepository fileRepo("songs.txt");
    fileRepo.load();
    assert(fileRepo.find("Title 1", "Artist 1").getTitle() == "Title 1");
    assert(fileRepo.find("Title 2", "Artist 2").getTitle() == "Title 2");
}

void testSave() {

    Filerepository fileRepo("songs.txt");
    Song song1("Artist 1", "Title 1", {}, 2023, "url");
    Song song2("Artist 2", "Title 2", {}, 2023, "url");
    fileRepo.store(song1);
    fileRepo.store(song2);


    fileRepo.save();


}



