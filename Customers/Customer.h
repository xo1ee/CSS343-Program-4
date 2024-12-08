// ---------------------------------------------------- Customer.h -----------------------------------------------------
// Kyle Lai CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/6/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Customer parent class stores info about each unique customer and their transaction history
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------#ifndef CUSTOMER_H_
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <vector>
#include "HashTable.h"
// ID_SIZE must be 4 digits
const int ID_SIZE = 4;
using namespace std;

class Customer
{
    // operator<< displays the customers in a neatly fashion
    friend ostream &operator<<(ostream &ostream, const Customer &rhs);

public:
    // constructors
    Customer();
    Customer(string first, string last, string id);
    ~Customer();

    // Setters
    bool setCustomerID(string id);
    bool setFirstName(string first);
    bool setLastName(string last);
    bool setCustomerData(string first, string last, string id);

    // Getters
    string getCustomerID() const;
    string getFirstName() const;
    string getLastName() const;

    int hash() const;

    void updateHistoryLog(string history);

private:
    string firstName;
    string lastName;
    string customerID;

    vector<string> historyLog;
};

#endif