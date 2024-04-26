
#ifndef SONGCONTROLLER_TEST_H
#define SONGCONTROLLER_TEST_H

#include <iostream>

class SongControllerTest {
public:
    void runTestsController() {
        void testAdd();
        void testFind();
        void testGetFilesSortedByArtist();
        void testGetFilesSortedByTitle();
        void testDelete();
    }
};
#endif // SONGCONTROLLER_TEST_H
