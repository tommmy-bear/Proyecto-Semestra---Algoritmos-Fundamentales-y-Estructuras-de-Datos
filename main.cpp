#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>
#include "sorts.h"

#define spotify_file "spotify_2023.csv"

// Define a custom data structure to represent song stream information.
struct SongStream
{
    std::string song_name;
    long long no_streams;
    std::string artist_name;
};

bool compareSongStreams(const SongStream& a, const SongStream& b) {
    return a.no_streams < b.no_streams;
}

int main()
{
    std::ifstream file(spotify_file);
    std::string line;
    std::string artist;

    // Create a list to store song_stream data.
    std::list<SongStream> tracks;

    std::getline(file, line);

    std::size_t c1 = 0;
    std::size_t c2 = 0;

    std::cout << "Please enter an artist name: ";
    std::getline(std::cin, artist);
    std::transform(artist.begin(), artist.end(), artist.begin(), ::tolower);

    while (getline(file, line))
    {
        c1 = line.find(',');
        c2 = line.rfind(',');

        SongStream newTrack;
        newTrack.song_name = line.substr(c1 + 1, c2 - c1 - 1);
        newTrack.no_streams = std::stoll(line.substr(c2 + 1));
        newTrack.artist_name = line.substr(0, c1);

        tracks.push_back(newTrack);
    }

    // Sort the tracks list using a custom comparison function.
    tracks.sort(compareSongStreams);

    for (const SongStream& track : tracks)
    {
        std::string trackArtist = track.artist_name;
        std::transform(trackArtist.begin(), trackArtist.end(), trackArtist.begin(), ::tolower);

        if (trackArtist == artist)
        {
            std::cout << track.no_streams << "\t || " << track.song_name << " || " << track.artist_name << std::endl;
        }
    }

    // Close the file.
    file.close();
}
