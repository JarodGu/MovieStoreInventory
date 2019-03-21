//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/20/2019.
//
// Comedy movie inheriting from the Movie and Media classes
// Contains all the same data as parent classes but different operators
//

#ifndef CROPLEY_ASSIGNMENT_4_COMEDY_H
#define CROPLEY_ASSIGNMENT_4_COMEDY_H


#include <string>
#include "movie.h"

class Comedy  : public Movie {
    // Allows for converting this movie to ostream
    friend std::ostream &operator<<(std::ostream &out, const Comedy &in);

public:
    // Constructor
    Comedy(int stock, std::string director,
            std::string title, int releaseYear);

    // Compares comedies against other comedies by title, released year
    bool operator>(const Comedy &other) const;

    bool operator<(const Comedy &other) const;

    bool operator==(const Comedy &other) const;

    bool operator!=(const Comedy &other) const;

    bool operator>=(const Comedy &other) const;

    bool operator<=(const Comedy &other) const;

    // Returns movie with all of it's details as a string
    std::string string() const override;

    // Compares this movie to another
    // Returns: -1 if <, 0 if ==, 1 if >
    int compare(const Movie &other) const override;
};


#endif //CROPLEY_ASSIGNMENT_4_COMEDY_H
