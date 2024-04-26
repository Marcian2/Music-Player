
#ifndef SONG_EXCEPTION_H
#define SONG_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class SongException : public exception {
public:
    explicit SongException(const string& description);
    const char* what() const noexcept override;

private:
    string description_;
};

#endif  // SONG_EXCEPTION_H
