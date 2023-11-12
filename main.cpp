#include "DoublyLinkedList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>

// Ignore spaces
std::string trim(const std::string &s) {
    size_t start = s.find_first_not_of(" \n\r\t\f\v");
    size_t end = s.find_last_not_of(" \n\r\t\f\v");
    return (start == std::string::npos || end == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

// Look up and show artist's songs
void searchArtist(DoublyLinkedList &list, const std::string &inputArtist) {
    std::ifstream file("project.csv");
    if (!file.is_open()) {
        std::cerr << "Error at opening the file" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Do not count first line

    while (std::getline(file, line)) {
        std::istringstream s(line);
        std::string artist_name, track_name, field;
        unsigned long long streams;

        std::getline(s, artist_name, ',');
        std::getline(s, track_name, ',');
        std::getline(s, field, ',');
        streams = std::stoull(field);

        artist_name = trim(artist_name);

        if (artist_name == inputArtist) {
            Node* newNode = new Node(artist_name, track_name, streams);
            list.append(newNode);
        }
    }

    file.close();

    // Sort list
    list.sort();
    list.printList();
}

// Función para añadir datos al archivo CSV.
void addDataToFile() {
    std::string artist_name, track_name, field;
    unsigned long long streams;

    std::cout << "Enter the artist name: ";
    std::getline(std::cin, artist_name);
    std::cout << "Enter song's name: ";
    std::getline(std::cin, track_name);
    std::cout << "Enter the number of streams: ";
    std::cin >> streams;

    std::ofstream file("project.csv", std::ios::app); // Opens the file
    if (file.is_open()) {
        file << artist_name << "," << track_name << "," << streams << "\n";
        file.close();
    } else {
        std::cerr << "Error at opening the file." << std::endl;
    }
}

int main() {
    DoublyLinkedList list;
    int option;

    std::cout << "Welcome to Spotify :), please enter an option: : \n";
    std::cout << "1. Search an artist\n";
    std::cout << "2. Add data\n";
    std::cin >> option;
    std::cout <<""<<std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    if (option == 1) {
        std::string inputArtist;
        std::cout << "Enter the artist name: : ";
        std::getline(std::cin, inputArtist);
        inputArtist = trim(inputArtist);
        searchArtist(list, inputArtist);
    } else if (option == 2) {
        addDataToFile();
    } else {
        std::cout << "No valid option." << std::endl;
    }

    return 0;
}
