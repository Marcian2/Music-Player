
#include "exception.h"
using namespace std;
#include<string>





SongException::SongException(const string& description)
    : description_(description) {}

const char* SongException::what() const noexcept {
    return description_.c_str();
}
