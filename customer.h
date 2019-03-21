// ------------- customer.h ----------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 3/5/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Customer header file
// Represents a customer
// -------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/*
 * represents individual customer class
 */

class Customer {
private:
    //all elements of customer

    int ID;
    string firstName;
    string lastName;
    //vector of pre formatted tranactions made by this cust
    vector<string> history;
public:
    //customer inits
    Customer();
    Customer(const int, const string, const string);

    //getters
    int getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getHistory() const;

    //adds preformatted string to this history
    void addTransaction(const string&);
};