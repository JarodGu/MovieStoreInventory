// ------------- store.cpp -------------------------------------------------
// Jarod Guerrero CSS 343 C
// Created 3/9/19
// Last Modified 3/20/19
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
    // Do I need to create empty binary tree and customertable?
    ///// I don't think so, depending on your implementation it should be done already
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
 * doesn't exist in the store's library.
 * Adds a transaction to the customer's history.
 * Format: Cust#<ID> borrowed <MovieTitle>
 * Precondition: The Movie exists within the database
 */
bool Store::Borrow(int custID, Movie &theMovie)
{
    if(theMovie.borrowStock())
    {
        // Add transaction to customer
        string transaction = "Cust#" + to_string(custID) + " borrowed " + theMovie.getTitle();
        Customers.addTransaction(custID, transaction);
        return true;
    } else {
            // movie out of stock
            cout << "Error: Movie currently out of stock" << endl;
    }
    //cout << "Error: Movie not in inventory" << endl;
    return false;

}

/*
 * Customer returns a movie and its stock goes up by 1
 * Returns false if the movie does not exist in store's library.
 * Adds a transaction to the customer's history.
 * Format: Cust#<ID> returned <MovieTitle>
 */
bool Store::Return(int custID, Movie &theMovie)
{
    theMovie.returnStock();
    // Add transaction to customer
    string transaction = "Cust#" + to_string(custID) + " returned " + theMovie.getTitle();
    Customers.addTransaction(custID, transaction);
    return true;

}

/*
 * Outputs the customer's transaction history.
 * Returns false if the customer ID doesn't exist.
 */
bool Store::History(int custID) const
{
    if(!Customers.customerExists(custID))
    {
        cout << "Error: Customer does not exist" << endl;
        return false;
    }
    cout << "\n--- Transaction History for Cust#" << custID << endl;
    cout << Customers.getHistory(custID);
    return true;
}

/*
 * Prints out the stores current movie inventory in sorted order
 * provided in the assignment4.doc. Outputs Comedies, Dramas,
 * then Classics.
 */
void Store::getInventory() const
{
    // Traverse BinTree inorder and cout all elements
    if(Movies.isEmpty())
    {
        cout << "Store empty. Is it Black Friday?" << endl;
    } else {
        cout << Movies << endl;
    }
}

/*
 * Adds a Comedy or Drama movie to the inventory.
 * Returns false if unsupported genre or movie
 * already exists.
 */
bool Store::AddMovie(char genre, int stock, string director, string title, int year)
{
    // Create movie object on heap
    // If it does, delete then return false w/ error message
    // Otherwise add it to the inventory using insert (sorted)
    if(genre == 'F') // Comedy
    {
        Comedy *mov = new Comedy(stock, director, title, year);
        NodeData *temp = new NodeData(mov);
        return Movies.insert(temp); // Returns false if the movie already exists
    }
    else if(genre == 'D') // Drama
    {
        Drama *mov = new Drama(stock, director, title, year);
        NodeData *temp = new NodeData(mov);
        return Movies.insert(temp); // Returns false if the movie already exists
    }
    return false;
    // Check if it already exists
}

/*
 * Adds a Classical movie to the inventory.
 * Returns false if unsupported genre or movie already exists.
 */
bool Store::AddClassicMovie(int stock, string director, string title, string actorFirst,
                            string actorLast, int month, int year)
{
    Classic *mov = new Classic(stock, director, title, actorFirst, actorLast, month, year);
    NodeData *temp = new NodeData(mov);
    return Movies.insert(temp);
}

/*
 * Adds a customer to the customer hash table
 */
bool Store::AddCustomer(int custID, const string &first, const string &last)
{
    if(Customers.customerExists(custID)){
        return false; // Customer already exists
    }
    Customers.addCustomer(custID, first, last);
    return true;
}

/*
 * Functions to retrieve a movie based on criterion.
 * Returns false if the movie could not be found.
 * Returns true and sets pTarget to point to the movie
 * in inventory if found.
 */
///////////////////////////////////////////////////////////////
bool Store::findComedy(string &title, int releaseYear, NodeData* &pTarget)
{
    return Movies.retrieveComedy(title, releaseYear, pTarget);
}

bool Store::findDrama(string &director, string &title, NodeData *&pTarget)
{
    return Movies.retrieveDrama(director, title, pTarget);
}

bool Store::findClassic(int releaseMonth, int releaseYear, string &actorFirst, string &actorLast, NodeData *&pTarget)
{
    return Movies.retrieveClassic(releaseMonth, releaseYear, actorFirst, actorLast, pTarget);
}
