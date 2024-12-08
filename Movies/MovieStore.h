#ifndef MOVIESTORE_H
#define MOVIESTORE_H

#include "../MovieLib.h"
#include "../Customers/HashTable.h"
#include "../Transactions/TransactionFactory.h"
#include "../Movies/MovieFactory.h"
#include "../Customers/Customer.h"

class MovieStore
{
public:
    MovieStore();
    ~MovieStore();

    bool doTransaction(char actionCode, const std::string &transactionData);
    bool addMovie(const std::string &movieData);
    bool addCustomer(const std::string &customerData);

private:
    MovieLib library;
    HashTable<int, Customer*> customers;

};

#endif // MOVIESTORE_H