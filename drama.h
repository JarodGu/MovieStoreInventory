//
// Created by Kaib Cropley on 3/8/2019.
//

#ifndef CROPLEY_ASSIGNMENT_4_DRAMA_H
#define CROPLEY_ASSIGNMENT_4_DRAMA_H

#include "movie.h"

class Drama : public Movie {
    friend std::ostream &operator<<(std::ostream &out, const Drama &in);
public:
    // Constructor
    Drama(int stock, std::string director,
           std::string title, int releaseYear);

    // Compares Dramas against other Dramas by Director then title
    bool operator>(const Drama &other) const;

    bool operator<(const Drama &other) const;

    bool operator==(const Drama &other) const;

    bool operator!=(const Drama &other) const;

    bool operator>=(const Drama &other) const;

    bool operator<=(const Drama &other) const;

    virtual std::string string() const;
};


#endif //CROPLEY_ASSIGNMENT_4_DRAMA_H
