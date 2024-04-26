
#include "action.h"

ActionAdd::ActionAdd(Repository &repository, const Song &song)
    : repo(repository), song(song) {}

void ActionAdd::apply() {
    repo.remove(song);
}



ActionDelete::ActionDelete(Repository &repository, const Song &song)
    : repo(repository), song(song) {}

void ActionDelete::apply() {
    repo.store(song);
}
