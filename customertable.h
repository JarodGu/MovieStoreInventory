#include "customer.h"
#include <vector>
#include <string>

using namespace std;

class CustomerTable {
private:
    Customer* table[10000];
public:
    CustomerTable();
    ~CustomerTable();
    
    bool customerExists(const int IDinput) const;
    string getHistory(const int IDinput) const;
    
    void addCustomer(const int IDinput, const string fN, const string lN);
    void removeCustomer(const int IDinput);
    void addTransaction(const int IDinput, const string trans);
};