//
// Created by Kaib Cropley on 3/8/2019.
//

#ifndef CROPLEY_ASSIGNMENT_4_COMEDY_H
#define CROPLEY_ASSIGNMENT_4_COMEDY_H


#include <string>
#include "movie.h"

class Comedy  : public Movie {
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

    virtual std::string string() const;
};


#endif //CROPLEY_ASSIGNMENT_4_COMEDY_H
