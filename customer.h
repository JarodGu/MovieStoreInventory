#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Customer {
private:
    int ID;
    string firstName;
    string lastName;
    vector<string> history;
public:
    Customer();
    Customer(const int, const string, const string);
    
    int getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getHistory() const;
    
    void addTransaction(const string&);
};