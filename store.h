// ------------- store.h ---------------------------------------------------
// Jarod Guerrero CSS 343 C
// Created 3/9/19
// Last Modified 3/9/19
// -------------------------------------------------------------------------
// Header file for the store class
// -------------------------------------------------------------------------
// Contains functions to populate a Movie store with inventory and
// perform operations with customers based on file input.
// -------------------------------------------------------------------------

#ifndef ASG4_STORE_H
#define ASG4_STORE_H
#include <iostream>
#include "bintree.h"

class Store{
public:
    // Reads input from data4movies.txt
    //bool readMovieFile;

    // Reads input from data4customers.txt
    //bool readCustomerFile;

    // Reads input from data4commands.txt
    //bool readCommandfile;



private:
    BinTree Movies;
};

#endif //ASG4_STORE_H
