//
// Created by Kaib Cropley on 3/8/2019.
//

#include<iostream>
#include "comedy.h"

Comedy::Comedy(int stock, std::string director,
               std::string title, int releaseYear) :
        Movie('F', stock, director, title, releaseYear) {

}

bool Comedy::operator>(const Comedy &other) const {
    if (getMovieType() != other.getMovieType()) {
        return greaterThanMovieTypes(other);
    }
    if (getTitle() < other.getTitle()) {
        return true;
    }
    if (getTitle() == other.getTitle()) {
        return (getReleaseYear() > other.getReleaseYear());
    }
    return false;
}

bool Comedy::operator<(const Comedy &other) const {
    return !(*(this) > other);
}

bool Comedy::operator==(const Comedy &other) const {
    return (getTitle() == other.getTitle()
            && getReleaseYear() == other.getReleaseYear()
            && getMovieType() == other.getMovieType());
}

bool Comedy::operator!=(const Comedy &other) const {
    return !(*(this) == other);
}

bool Comedy::operator>=(const Comedy &other) const {
    return (*(this) > other || (*(this) == other));
}

bool Comedy::operator<=(const Comedy &other) const {
    return (*(this) < other || (*(this) == other));
}

std::ostream &operator<<(std::ostream &out, const Comedy &in) {
    out << in.string();
    return out;
}

std::string Comedy::string() const {
    std::string out = "";
    out += getMovieType();
    out += " " + std::to_string(getStock()) + " ";
    out += getDirector() + " ";
    out += getTitle() + " ";
    out += std::to_string(getReleaseYear());
    return out;
}
