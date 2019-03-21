//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/20/2019.
//
// Classic movie
//

#ifndef CROPLEY_ASSIGNMENT_4_CLASSIC_H
#define CROPLEY_ASSIGNMENT_4_CLASSIC_H


#include "movie.h"

class Classic : public Movie {
    // Allows for converting this movie to ostream
    friend std::ostream& operator<<(std::ostream& out, const Classic& in);

public:
    // Constructor
    Classic(int stock, std::string director,
            std::string title, std::string actorFirst, std::string actorLast,
            int releaseMonth, int releaseYear);

    // Returns major actors full name
    std::string getMajorActor() const;

    // Returns major actors first name
    std::string getActorFirst() const;

    // Returns major actors last name
    std::string getActorLast() const;

    // Returns release month
    int getReleaseMonth() const;

    // Compares classics against other classics by release date, major actor
    bool operator>(const Classic &other) const;

    bool operator<(const Classic &other) const;

    bool operator==(const Classic &other) const;

    bool operator!=(const Classic &other) const;

    bool operator>=(const Classic &other) const;

    bool operator<=(const Classic &other) const;

    // Returns movie with all of it's details as a string
    std::string string() const override;

    // Compares this movie to another
    // Returns: -1 if <, 0 if ==, 1 if >
    int compare(const Movie &other) const override;

private:
    // Data only within Classic movies
    std::string actorFirst;
    std::string actorLast;
    int releaseMonth;

    // Compares this classics release date to another classics release date
    // Returns: -1 if <, 0 if ==, 1 if >
    int compareRelease(const Classic &other) const;

    // Compares this classics actor to another classics actor
    // Returns: -1 if <, 0 if ==, 1 if >
    int compareActor(const Classic &other) const;
};


#endif //CROPLEY_ASSIGNMENT_4_CLASSIC_H
