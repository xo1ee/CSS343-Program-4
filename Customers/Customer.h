#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>

class Customer
{
    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);

public:
    Customer();
    Customer(const std::string &first, const std::string &last, const std::string &id);
    ~Customer();

    void addTransaction(const std::string &transaction);
    const std::vector<std::string> &getTransactions() const;

    std::string getID() const;
    int hash() const;

private:
    std::string firstName;
    std::string lastName;
    std::string customerID;
    std::vector<std::string> transactionHistory;
};

#endif
