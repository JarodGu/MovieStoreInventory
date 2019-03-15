//
// Created by Kaib Cropley on 3/8/2019.
//

#include <iostream>
#include "classic.h"

// Constructor
Classic::Classic(int stock, std::string director,
                 std::string title, std::string majorActor,
                 int releaseMonth, int releaseYear) :
        Movie('C', stock, director, title, releaseYear),
        majorActor{majorActor}, releaseMonth{releaseMonth} {

}

// Returns major actor
std::string Classic::getMajorActor() const {
    return majorActor;
}

// Returns release month
int Classic::getReleaseMonth() const {
    return releaseMonth;
}

// Compares classics against other classics by release date, major actor
bool Classic::operator>(const Classic &other) const {
    if (getMovieType() != other.getMovieType()) {
        return greaterThanMovieTypes(other);
    }
    if (getReleaseYear() > other.getReleaseYear()) {
        return true;
    }
    if (getReleaseYear() == other.getReleaseYear()) {
        if (releaseMonth > other.releaseMonth) {
            return true;
        } else if (releaseMonth == other.releaseMonth) {
            int compare = majorActor.compare(other.getMajorActor());
            return compare < 0;
        }
    }
    return false;
}

bool Classic::operator<(const Classic &other) const {
    return !(*(this) > other);
}

bool Classic::operator==(const Classic &other) const {
    return (getReleaseYear() == other.getReleaseYear()
            && releaseMonth == other.releaseMonth
            && majorActor == other.majorActor
            && getMovieType() == other.getMovieType());
}

bool Classic::operator!=(const Classic &other) const {
    return !(*(this) == other);
}

bool Classic::operator>=(const Classic &other) const {
    return (*(this) > other || *(this) == other);
}

bool Classic::operator<=(const Classic &other) const {
    return (*(this) < other || *(this) == other);
}

std::ostream &operator<<(std::ostream &out, const Classic &in) {
    out << in.string();
    return out;
}

std::string Classic::string() const {
    std::string out = "";
    out += getMovieType();
    out += " " + std::to_string(getStock()) + " ";
    out += getDirector() + " ";
    out += getTitle() + " ";
    out += getMajorActor() + " ";
    out += std::to_string(getReleaseMonth()) + " ";
    out += std::to_string(getReleaseYear());
    return out;
}




