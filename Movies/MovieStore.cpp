#include "MovieStore.h"
#include "../Transactions/Borrow.h"
#include "../Transactions/Return.h"
#include "../Transactions/Inventory.h"
#include "../Transactions/History.h"

MovieStore::MovieStore() : library(), customers() {}

MovieStore::~MovieStore() {}

bool MovieStore::doTransaction(char actionCode, const std::string &transactionData)
{
    Transaction *transaction = TransactionFactory::createTransaction(actionCode);
    if (transaction == nullptr)
    {
        std::cout << "Invalid action code: " << actionCode << std::endl;
        return false;
    }

    bool result = transaction->execute(library, customers, transactionData);
    delete transaction;
    return result;
}

bool MovieStore::addMovie(const std::string &movieData)
{
    if (movieData.empty())
    {
        std::cout << "Invalid movie data: " << movieData << std::endl;
        return false;
    }

    bool result = library.insert(movieData);
    if (!result)
    {
        std::cout << "Failed to insert movie: " << movieData << std::endl;
    }
    return result;
}

bool MovieStore::addCustomer(const std::string &customerData)
{
    std::stringstream ss(customerData);
    int id;
    std::string lastName, firstName;
    ss >> id >> lastName >> firstName;

    if (ss.fail() || id < 1000 || id > 9999)
    {
        std::cout << "Invalid customer data: " << customerData << std::endl;
        return false;
    }

    Customer *newCustomer = new Customer(firstName, lastName, std::to_string(id));
    bool result = customers.insert(id, newCustomer);
    if (!result)
    {
        delete newCustomer;
        std::cout << "Failed to insert customer: " << customerData << std::endl;
    }
    return result;
}