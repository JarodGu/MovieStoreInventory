// ------------- customer.cpp ----------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 3/5/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Customer implementation file
// Represents a customer
// -------------------------------------------------------------------------
#include "customer.h"
using namespace std;

/*
 * this is cpp implementation fo cust class for use in HASHTABLE
 */

//default constructor initializes all elements to default values
Customer::Customer() {
    ID = 0;
    firstName = "";
    lastName = "";
}

//self-explanatory
Customer::Customer(const int inputID, const string fN, const string lN) {
    ID = inputID;
    firstName = fN;
    lastName = lN;
}

//getters

int Customer::getID() const {
    return ID;
}

string Customer::getFirstName() const {
    string outString = firstName;
    return outString;
}

string Customer::getLastName() const {
    string outString = lastName;
    return outString;
}

string Customer::getHistory() const {
    string build = "";
    for(int i = 0; i < history.size(); i++) {
        string curr = history.at(i);
        build += curr;
        if(i != history.size() - 1) {
            build += "\n";
        }
    }
    return build;
}

/*
 * Adds a string representing a customer transaction to the customer's
 * transaction history. String is formatted in the store class.
 */
void Customer::addTransaction(const string &trans) {
    string addTo = trans;
    history.push_back(addTo);
}

