// ------------- store.h ---------------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 3/9/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Header file for the store class
// -------------------------------------------------------------------------
// Contains functions to populate a Movie store with inventory and
// perform operations.
// -------------------------------------------------------------------------

#ifndef ASG4_STORE_H
#define ASG4_STORE_H
#include <iostream>
#include "bintree.h"
#include "media.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "customertable.h"

class Store{
public:
    Store();
    ~Store();

    bool Borrow(int custID, Movie &theMovie);

    bool Return(int custID, Movie &theMovie);

    bool History(int custID) const;

    void getInventory() const;

    bool AddMovie(char genre, int stock, string director,
            string title, int year);

    bool AddClassicMovie(int stock, string director, string title,
            string actorFirst, string actorLast, int month, int year);

    bool AddCustomer(int custID, const string &first, const string &last);

    // Functions to find movies (return and borrow)
    bool findComedy(string &title, int releaseYear, NodeData *&pTarget);
    bool findDrama(string &director, string &title, NodeData *&pTarget);
    bool findClassic(int releaseMonth, int releaseYear, string &actorfirst, string &actorLast,
            NodeData *&pTarget);

private:
    BinTree Movies;
    CustomerTable Customers;
};

#endif //ASG4_STORE_H
