//
// Created by Kaib Cropley on 3/8/2019.
//

#include <iostream>
#include "drama.h"

Drama::Drama(int stock, std::string director,
             std::string title, int releaseYear) :
        Movie('D', stock, director, title, releaseYear) {

}

bool Drama::operator>(const Drama &other) const {
    if (getMovieType() != other.getMovieType()) {
        return greaterThanMovieTypes(other);
    }
    if (getDirector() < other.getDirector()) {
        return true;
    }
    if (getDirector() == other.getDirector()) {
        return getTitle() < other.getTitle();
    }
    return false;
}

bool Drama::operator<(const Drama &other) const {
    return !(*(this) > other);
}

bool Drama::operator==(const Drama &other) const {
    return (getDirector() == other.getDirector()
            && getTitle() == other.getTitle()
            && getMovieType() == other.getMovieType());
}

bool Drama::operator!=(const Drama &other) const {
    return !(*(this) == other);;
}

bool Drama::operator>=(const Drama &other) const {
    return (*(this) > other || *(this) == other);
}

bool Drama::operator<=(const Drama &other) const {
    return (*(this) < other || *(this) == other);
}

std::ostream &operator<<(std::ostream &out, const Drama &in) {
    out << in.string();
    return out;
}

std::string Drama::string() const {
    std::string out;
    out += getMovieType();
    out += " " + std::to_string(getStock()) + " ";
    out += getDirector() + " ";
    out += getTitle() + " ";
    out += std::to_string(getReleaseYear());
    return out;
}




