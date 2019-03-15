//
// Created by Kaib Cropley on 3/8/2019.
//

#ifndef CROPLEY_ASSIGNMENT_4_CLASSIC_H
#define CROPLEY_ASSIGNMENT_4_CLASSIC_H


#include "movie.h"

class Classic : public Movie {
public:
    // Constructor
    Classic(int stock, std::string director,
            std::string title, std::string majorActor,
            int releaseMonth, int releaseYear);

    // Returns major actor
    std::string getMajorActor() const;

    // Returns release month
    int getReleaseMonth() const;

    // Compares classics against other classics by release date, major actor
    bool operator>(const Classic &other) const;

    bool operator<(const Classic &other) const;

    bool operator==(const Classic &other) const;

    bool operator!=(const Classic &other) const;

    bool operator>=(const Classic &other) const;

    bool operator<=(const Classic &other) const;

    friend std::ostream& operator<<(std::ostream& out, const Classic& in);

    virtual std::string string() const;

private:
    // Data only within Classic movies
    std::string majorActor;
    int releaseMonth;
};


#endif //CROPLEY_ASSIGNMENT_4_CLASSIC_H
