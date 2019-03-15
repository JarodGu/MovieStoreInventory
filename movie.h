//
// Created by Kaib Cropley on 3/8/2019.
//

#ifndef CROPLEY_ASSIGNMENT_4_MOVIE_H
#define CROPLEY_ASSIGNMENT_4_MOVIE_H


#include <string>
#include "media.h"

class Movie : public Media {

public:
    // Constructor
    Movie(char movieType, int stock, std::string director,
          std::string title, int releaseYear);

    // Returns movie type
    char getMovieType() const;

    // Returns movie director
    std::string getDirector() const;

    // Returns movie title
    std::string getTitle() const;

    // Returns movie's release year
    int getReleaseYear() const;

    // Compares movie compared to other movies by their type
    bool operator>(const Movie &other) const;

    bool operator<(const Movie &other) const;

    bool operator==(const Movie &other) const;

    bool operator!=(const Movie &other) const;

    bool operator>=(const Movie &other) const;

    bool operator<=(const Movie &other) const;

    virtual std::string string() const;

protected:
    friend std::ostream &operator<<(std::ostream &out, const Movie &in);

    bool greaterThanMovieTypes(const Movie &other) const;

private:
    // Movie data
    int releaseYear;
    std::string director;
    std::string title;
    char movieType;
};


#endif //CROPLEY_ASSIGNMENT_4_MOVIE_H
