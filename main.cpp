#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include "sorts.h" // Assuming this header contains the custom sorting function.
#define spotify_file "spotify_2023.csv" // Define the CSV file name as a macro.

// Define a custom data structure to represent song stream information.
typedef struct song_stream
{
    std::string song_name;
    long long no_streams;
    std::string artist_name;
};

// Custom comparison function for sorting song_stream objects by stream count.
bool compare(song_stream A, song_stream B)
{
    return A.no_streams > B.no_streams;
}

// Custom less-than operator for song_stream objects based on stream count.
bool operator<(song_stream const &lhs, song_stream const &rhs)
{
    return lhs.no_streams > rhs.no_streams;
}

// Custom comparison function to check if a song_stream's artist name matches a given name.
bool compare_name(song_stream A, std::string name)
{
    return A.artist_name == name;
}

int main()
{
    // Read the file
    std::ifstream file(spotify_file);
    // Variables
    std::string line;
    std::string artist;

    // Vector to store song_stream data.
    std::vector<struct song_stream> tracks;

    // This will not consider headlines
    std::getline(file, line);

    std::size_t c1 = 0;
    std::size_t c2 = 0;

    // Read each line of the CSV file and extract song information.
    while (getline(file, line))
    {
        // Find positions of commas in the CSV line.
        c1 = line.find(',');
        c2 = line.rfind(',');

        // Create a song_stream object and add it to the tracks vector.
        tracks.push_back(
            song_stream{
                song_name : line.substr(c1 + 1, c2 - c1 - 1),
                no_streams : std::stoll(line.substr(c2 + 1)),
                artist_name : line.substr(0, c1)
            });
    }

    // Sort the tracks vector using a custom sorting function (merge sort).
    Sorts<song_stream>().ordenaMerge(tracks);

    // Prompt the user to enter an artist's name.
    std::cout << "Please enter an artist name: ";
    std::getline(std::cin, artist);

    // Search and print songs by the entered artist.
    for (song_stream track : tracks)
    {
        if (track.artist_name.compare(artist) == 0)
        {
            std::cout << track.no_streams << "\t || " << track.song_name << " || " << track.artist_name << std::endl;
        }
    }

    // Close the file.
    file.close();
}
