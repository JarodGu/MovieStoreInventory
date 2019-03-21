//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/20/2019.
//
// Drama movie
//

#include <iostream>
#include "drama.h"

Drama::Drama(int stock, std::string director,
             std::string title, int releaseYear) :
        Movie('D', stock, director, title, releaseYear) {

}

// Compares Dramas against other Dramas by Director then title
bool Drama::operator>(const Drama &other) const {
    return (compare(other) == 1);
}

bool Drama::operator<(const Drama &other) const {
    return !(*(this) > other);
}

bool Drama::operator==(const Drama &other) const {
    return (compare(other) == 0);
}

bool Drama::operator!=(const Drama &other) const {
    return !(*(this) == other);
}

bool Drama::operator>=(const Drama &other) const {
    return (*(this) > other || *(this) == other);
}

bool Drama::operator<=(const Drama &other) const {
    return (*(this) < other || *(this) == other);
}

// Allows for converting this movie to ostream
std::ostream &operator<<(std::ostream &out, const Drama &in) {
    out << in.string();
    return out;
}

// Returns movie with all of it's details as a string
std::string Drama::string() const {
    std::string out;
    out += getMovieType();
    out += " " + std::to_string(getStock()) + " ";
    out += getDirector() + " ";
    out += getTitle() + " ";
    out += std::to_string(getReleaseYear());
    return out;
}

// Compares this movie to another
// Returns: -1 if <, 0 if ==, 1 if >
int Drama::compare(const Movie &other) const {
    if (compareMovieType(other) != 0) {
        return compareMovieType(other);
    }
    if (getDirector() == other.getDirector()) {
        if (getTitle() == other.getTitle()) {
            return 0;
        }
        if (getTitle() < other.getTitle()) {
            return 1;
        }
        if (getTitle() > other.getTitle()) {
            return -1;
        }
    }
    if (getDirector() < other.getDirector()) {
        return 1;
    }
    if (getDirector() > other.getDirector()) {
        return -1;
    }
}




