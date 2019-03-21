//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/20/2019.
//
// Classic movie
//

#include <iostream>
#include "classic.h"

// Constructor
Classic::Classic(int stock, std::string director,
                 std::string title, std::string actorFirst,
                 std::string actorLast, int releaseMonth, int releaseYear) :
        Movie('C', stock, director, title, releaseYear),
        actorFirst{actorFirst}, actorLast{actorLast},
        releaseMonth{releaseMonth} {

}

// Returns major actor's full name
std::string Classic::getMajorActor() const {
    return getActorFirst() + " " + getActorLast();
}

// Returns major actors first name
std::string Classic::getActorFirst() const {
    return actorFirst;
}

// Returns major actors last name
std::string Classic::getActorLast() const {
    return actorLast;
}

// Returns release month
int Classic::getReleaseMonth() const {
    return releaseMonth;
}

// Compares classics against other classics by release date, major actor
bool Classic::operator>(const Classic &other) const {
    return (compare(other) == 1);
}

bool Classic::operator<(const Classic &other) const {
    return !(*(this) > other);
}

bool Classic::operator==(const Classic &other) const {
    return (compare(other) == 0);
}

bool Classic::operator!=(const Classic &other) const {
    return (compare(other) != 0);
}

bool Classic::operator>=(const Classic &other) const {
    return (*(this) > other || *(this) == other);
}

bool Classic::operator<=(const Classic &other) const {
    return (*(this) < other || *(this) == other);
}

// Allows for converting this movie to ostream
std::ostream &operator<<(std::ostream &out, const Classic &in) {
    out << in.string();
    return out;
}

// Returns movie with all of it's details as a string
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

// Compares this movie to another
// Returns: -1 if <, 0 if ==, 1 if >
int Classic::compare(const Movie &other) const {
    if (compareMovieType(other) != 0) {
        return compareMovieType(other);
    }
    const auto *otherPtr = dynamic_cast<const Classic*>(&other);
    int temp = compareRelease(*otherPtr);
    if (temp == 0) {
        return compareActor(*otherPtr);
    }
    return temp;
}

// Compares this classics release date to another classics release date
// Returns: -1 if <, 0 if ==, 1 if >
int Classic::compareRelease(const Classic &other) const {
    if (getReleaseYear() == other.getReleaseYear()) {
        if (getReleaseMonth() == other.getReleaseMonth()) {
            return 0;
        }
        if (getReleaseMonth() < other.getReleaseMonth()) {
            return 1;
        }
        if (getReleaseMonth() > other.getReleaseMonth()) {
            return -1;
        }
    }
    if (getReleaseYear() < other.getReleaseYear()) {
        return 1;
    }
    if (getReleaseYear() > other.getReleaseYear()) {
        return -1;
    }
    return INT16_MAX;
}

// Compares this classics actor to another classics actor
// Returns: -1 if <, 0 if ==, 1 if >
int Classic::compareActor(const Classic &other) const {
    if (getActorFirst() == other.getActorFirst()) {
        if (getActorLast() == other.getActorLast()) {
            return 0;
        }
        if (getActorLast() > other.getActorLast()) {
            return 1;
        }
        if (getActorLast() < other.getActorLast()) {
            return -1;
        }
    }
    if (getActorFirst() > other.getActorFirst()) {
        return 1;
    }
    if (getActorFirst() < other.getActorFirst()) {
        return -1;
    }
    return INT16_MAX;
}







