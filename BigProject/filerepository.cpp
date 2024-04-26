
#include "filerepository.h"
#include<fstream>
#include "exception.h"
using namespace std;

Filerepository::Filerepository(const string &filepath):filepath(filepath)
{

}

void Filerepository::load()
{   ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filepath);
    }

    string line;
    while (std::getline(file, line)) {
        // Parse the line and create Song objects
        string delimiter = ",";
        string title = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());

        string artist = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());

        // Create the Song object
        Song s(artist, title, {}, 0, "");  // Provide default values for Lyrics, year, and url

        // Add the Song object to the repository
        try {
            store(s);
        } catch (const SongException& ex) {
            // Handle duplicate songs or any other exceptions
            // You can ignore duplicates or handle them as per your requirements
            // For now, we are just printing an error message
            std::cerr << "Error while loading song: " << ex.what() << std::endl;
        }
    }

    file.close();
}

void Filerepository::save()
{
    ofstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filepath);
    }

    vector<Song>& songs = getall();
    for (const Song& song : songs) {
        file << song.getTitle() << "," << song.getArtist() << "\n";
    }

    file.close();
}


void Filerepository::store(const Song& s) {
    Repository::store(s); // Call parent class implementation
    save(); // Save the data to the file
}

void Filerepository::remove(const Song& s) {
    Repository::remove(s); // Call parent class implementation
    save(); // Save the data to the file
}

vector<Song> &Filerepository::getAll()
{
    return getSongs();
}




