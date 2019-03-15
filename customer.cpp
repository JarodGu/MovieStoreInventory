#include "customer.h"
using namespace std;

Customer::Customer() {
    ID = 0;
    firstName = "";
    lastName = "";
}

Customer::Customer(const int inputID, const string fN, const string lN) {
    ID = inputID;
    firstName = fN;
    lastName = lN;
}

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

void Customer::addTransaction(const string trans) {
    string addTo = trans;
    history.push_back(addTo);
}

