//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/18/2019.
//
// Drama movie
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

    std::string string() const override;

    int compare(const Movie &other) const override;
};


#endif //CROPLEY_ASSIGNMENT_4_DRAMA_H
