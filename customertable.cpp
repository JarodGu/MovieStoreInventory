// ------------- customertable.cpp ----------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 3/5/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Customer table implementation file
// -------------------------------------------------------------------------
#include "customertable.h"
/*
 * This is the HASHTABLE of customers
 */
using namespace std;

/*
 * set all slots to null ptr
 */
CustomerTable::CustomerTable() {
    for(int i = 0; i < 10000; i++) {
        table[i] = NULL;
    }
}

/*
 * makes all pointers back to null and deletes any customers
 */
CustomerTable::~CustomerTable() {
    for(int i = 0; i < 10000; i++) {
        removeCustomer(i);
    }
}

/*
 * returns if slot is valid 4 digit slot and if there is a customer at this hashSlot
 */
bool CustomerTable::customerExists(const int IDinput) const {
    return IDinput >= 1000 && IDinput <= 9999 && table[IDinput] != NULL;
}

/*
 * returns line by line history
 */
string CustomerTable::getHistory(const int IDinput) const{
    if(customerExists(IDinput)) {
        Customer* cust = table[IDinput];
        string output = (*cust).getHistory();
        return output;
    } else {
        return "";
    }
}


//adds customer to this HASHTABLE
void CustomerTable::addCustomer(const int IDinput, const string fN, const string lN) {
    if(!customerExists(IDinput)) {
        table[IDinput] = new Customer(IDinput, fN, lN);
    } 
}

//does the opposite
void CustomerTable::removeCustomer(const int IDinput) {
    if(customerExists(IDinput)) {
        delete table[IDinput];
        table[IDinput] = NULL;
    }
}

//adds transaction to table
void CustomerTable::addTransaction(const int IDinput, const string trans) {
    if(customerExists(IDinput)) {
        Customer* cust = table[IDinput];
        (*cust).addTransaction(trans);
    }
}