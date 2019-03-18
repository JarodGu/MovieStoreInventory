//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/18/2019.
//
// Base file for all movie types within store
//

#include <iostream>
#include "movie.h"

// Constructor
Movie::Movie(char movieType, int stock, std::string director,
             std::string title, int releaseYear) : Media('D', stock),
                                                   movieType{movieType},
                                                   director{director},
                                                   title{title},
                                                   releaseYear{releaseYear} {

}

// Returns movie type
char Movie::getMovieType() const {
    return movieType;
}

// Returns movie's director
std::string Movie::getDirector() const {
    return director;
}

// Returns movie title
std::string Movie::getTitle() const {
    return title;
}

// Returns movies release year
int Movie::getReleaseYear() const {
    return releaseYear;
}

// Returns this movie to other movies based on their type
bool Movie::operator>(const Movie &other) const {
    greaterThanMovieTypes(other);
}

bool Movie::operator<(const Movie &other) const {
    return !(*(this) > other);
}

bool Movie::operator==(const Movie &other) const {
    return movieType == other.movieType;
}

bool Movie::operator!=(const Movie &other) const {
    return !(*(this) == other);
}

bool Movie::operator>=(const Movie &other) const {
    return (*(this) > other || *(this) == other);
}

bool Movie::operator<=(const Movie &other) const {
    return (*(this) < other || *(this) == other);
}

// Allows out putting string to ostream
std::ostream &operator<<(std::ostream &out, const Movie &in) {
    out << in.string();
    return out;
}

// Returns a string with all data about this movie
std::string Movie::string() const {
    return "";
}

bool Movie::greaterThanMovieTypes(const Movie &other) const {
    if (movieType == 'F') {
        return other.movieType != 'F';
    }
    if (movieType == 'D') {
        return !(other.movieType == 'F' || other.movieType == 'D');
    }
    if (movieType == 'C') {
        return !(other.movieType == 'F' ||
                 other.movieType == 'D' ||
                 other.getMovieType() == 'C');
    }
    // Covers future movie types
    return movieType > other.movieType;
}









