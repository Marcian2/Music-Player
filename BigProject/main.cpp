
#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include"songcontroller.h"
#include "filerepository.h"
#include "exception.h"

int main(int argc, char *argv[])
{   try {
        void runTestsRepository();
        void runTestsFileRepository();
        void runTestsController();
        std::cout << "All tests passed." << std::endl;
    } catch (const SongException& ex) {
        std::cerr << "Test failed with exception: " << ex.what() << std::endl;
    }

    QApplication a(argc, argv);

    Repository* repo = new Filerepository("song.txt");
    //    repo = new DBRepo("db.sql");

    SongController* ctrl = new SongController(repo);
    MainWindow w(ctrl);
    w.show();

    return a.exec();
}
