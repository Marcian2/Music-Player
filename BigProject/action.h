
#ifndef ACTION_H
#define ACTION_H
#include "repository.h"
#include "song.h"


class Action {
public:
    virtual void apply() = 0;
    virtual ~Action() {}
};

class ActionAdd : public Action {
private:
    Repository& repo;
    Song song;

public:
    ActionAdd(Repository& repository, const Song& song);
    void apply() override;
};


class ActionDelete : public Action {
private:
    Repository& repo;
    Song song;

public:
    ActionDelete(Repository& repository, const Song& song);
    void apply() override;
};

#endif // ACTION_H
