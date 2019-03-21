// ------------- customertable.h ----------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 3/5/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Customer table implementation file
// Hash table
// -------------------------------------------------------------------------
#include "customer.h"
#include <vector>
#include <string>

using namespace std;

/*
 * This class is a HASHTABLE that stores customers
 */
class CustomerTable {
private:
    //customer id hashes to index in hashtable
    Customer* table[10000];
public:
    //sets to all empty customers
    CustomerTable();
    ~CustomerTable();

    //is there a customer with IDinput ID
    bool customerExists(const int IDinput) const;
    //returns line by line string history with earliest transactions first
    string getHistory(const int IDinput) const;

    //adds new customer to corresponding ID slot if a customer does not already exist
    void addCustomer(const int IDinput, const string fN, const string lN);
    //deletes customer at this corresponding ID, new customer can be added in this slot
    void removeCustomer(const int IDinput);
    //adds properly formatted transaction to this customer for retrieval later
    void addTransaction(const int IDinput, const string trans);
};