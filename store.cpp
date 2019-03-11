// ------------- store.cpp -------------------------------------------------
// Jarod Guerrero CSS 343 C
// Created 3/9/19
// Last Modified 3/10/19
// -------------------------------------------------------------------------
// Implementation file for the store class
// -------------------------------------------------------------------------
// Contains functions to populate a Movie store with inventory and
// perform operations with customers based on file input.
// -------------------------------------------------------------------------
#include "store.h"

/*
 * Default constructor. Makes a new store with an empty movie inventory
 * and customer database
 */
Store::Store()
{

}

/*
 * Destructor
 */
Store::~Store()
{

}

/*
 * Customer borrows a movie and its stock goes down by 1
 * Returns false if the movie is out of stock or
 * doesn't exist
 */
bool Store::Borrow(char mediaType, Movie &theMovie)
{
    return false;
}

/*
 * Customer returns a movie and its stock goes up by 1
 * Returns false if the movie does not exist in inventory.
 */
bool Store::Return(char mediaType, Movie &theMovie)
{

    return false;
}

/*
 * Returns the customer's transaction history
 */
bool Store::History(Customer &cust) const
{
    return false;
}

/*
 * Prints out the stores current movie inventory in sorted order
 * provided in the assignment4.doc
 */
void Store::getInventory() const
{
    // Traverse BinTree inorder and cout all elements
}

/*
 * Adds a movie to the inventory.
 * Returns false if unsupported genre or movie
 * already exists.
 */
bool Store::AddMovie(char genre, int stock, const string &director, const string &title, int year)
{
    return false;
}

/*
 * Adds a classical movie to the inventory.
 * Returns false if unsupported genre or movie already exists.
 */
bool Store::AddClassicMovie(int stock, const string &director, const string &title, const string &actorFirst,
                            const string &actorLast, int month, int year)
{
    return false;
}

/*
 * Adds a customer to the customer hash table
 */
bool Store::AddCustomer(int custID, const string &first, const string &last)
{
    return false;
}


