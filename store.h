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
#include "media.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "customertable.h"

//#include "customer.h"
//#include "movie.h"

class Store{
public:
    Store();
    ~Store();

    bool Borrow(char mediaType, int custID, Media &mov); // Do I need to make Movie const?

    bool Return(char mediaType, int custID, Media &mov);

    bool History(int custID) const;

    void getInventory() const;

    bool AddMovie(char genre, int stock, const string &director,
            const string &title, int year);

    bool AddClassicMovie(int stock, const string &director, const string &title,
            const string &actorFirst, const string &actorLast, int month, int year);

    bool AddCustomer(int custID, const string &first, const string &last);
private:
    BinTree Movies;
    CustomerTable Customers;
};

#endif //ASG4_STORE_H
