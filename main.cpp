#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
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

    // Sort the tracks list using a custom sorting function (merge sort).
    Sorts<SongStream> sorter;
    sorter.ordenaMerge(tracks);

    std::cout << "Please enter an artist name: ";
    std::getline(std::cin, artist);
    std::transform(artist.begin(), artist.end(), artist.begin(), ::tolower);

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
