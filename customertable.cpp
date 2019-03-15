#include "customertable.h"

using namespace std;

CustomerTable::CustomerTable() {
    for(int i = 0; i < 10000; i++) {
        table[i] = NULL;
    }
}

CustomerTable::~CustomerTable() {
    for(int i = 0; i < 10000; i++) {
        removeCustomer(i);
    }
}

bool CustomerTable::customerExists(const int IDinput) const {
    return IDinput >= 1000 && IDinput <= 9999 && table[IDinput] != NULL;
}

string CustomerTable::getHistory(const int IDinput) const{
    if(customerExists(IDinput)) {
        Customer* cust = table[IDinput];
        string output = (*cust).getHistory();
        return output;
    } else {
        return "";
    }
}

void CustomerTable::addCustomer(const int IDinput, const string fN, const string lN) {
    if(!customerExists(IDinput)) {
        table[IDinput] = new Customer(IDinput, fN, lN);
    } 
}

void CustomerTable::removeCustomer(const int IDinput) {
    if(customerExists(IDinput)) {
        delete table[IDinput];
        table[IDinput] = NULL;
    }
}

void CustomerTable::addTransaction(const int IDinput, const string trans) {
    if(customerExists(IDinput)) {
        Customer* cust = table[IDinput];
        (*cust).addTransaction(trans);
    }
}