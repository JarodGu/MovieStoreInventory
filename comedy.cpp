//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/20/2019.
//
// Comedy movie
//

#include<iostream>
#include "comedy.h"

Comedy::Comedy(int stock, std::string director,
               std::string title, int releaseYear) :
        Movie('F', stock, director, title, releaseYear) {

}

// Compares comedies against other comedies by title, released year
bool Comedy::operator>(const Comedy &other) const {
    return (compare(other) == 1);
}

bool Comedy::operator<(const Comedy &other) const {
    return !(*(this) > other);
}

bool Comedy::operator==(const Comedy &other) const {
    return (compare(other) == 0);
}

bool Comedy::operator!=(const Comedy &other) const {
    return !(*(this) == other);
}

bool Comedy::operator>=(const Comedy &other) const {
    return (*(this) > other || *(this) == other);
}

bool Comedy::operator<=(const Comedy &other) const {
    return (*(this) < other || *(this) == other);
}

// Allows for converting this movie to ostream
std::ostream &operator<<(std::ostream &out, const Comedy &in) {
    out << in.string();
    return out;
}

// Returns movie with all of it's details as a string
std::string Comedy::string() const {
    std::string out = "";
    out += getMovieType();
    out += " " + std::to_string(getStock()) + " ";
    out += getDirector() + " ";
    out += getTitle() + " ";
    out += std::to_string(getReleaseYear());
    return out;
}

// Compares this movie to another
// Returns: -1 if <, 0 if ==, 1 if >
int Comedy::compare(const Movie &other) const {
    if (compareMovieType(other) != 0) {
        return compareMovieType(other);
    }
    if (getTitle() == other.getTitle()) {
        if (getReleaseYear() == other.getReleaseYear()) {
            return 0;
        }
        if (getReleaseYear() > other.getReleaseYear()) {
            return 1;
        }
        if (getReleaseYear() < other.getReleaseYear()) {
            return -1;
        }
    }
    if (getTitle() < other.getTitle()) {
        return 1;
    }
    if (getTitle() > other.getTitle()) {
        return -1;
    }
}
