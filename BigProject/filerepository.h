
#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H

#include "repository.h"



class Filerepository : public Repository
{
private:
    string filepath;
public:
    Filerepository(const string& filepath);
    void load();
    void save();
    //from repository
    Filerepository(const Filerepository &other)=delete; //copy constructor disabled
    Filerepository & operator=(const Filerepository &other)=delete; //asignment operator disabled
    void store(const Song &s) override;
    void remove(const Song &s) override;
    vector<Song>& getAll();
};

#endif // FILEREPOSITORY_H
