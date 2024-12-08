#include "TransactionFactory.h"
#include "Borrow.h" // Include specific transaction types
#include "Return.h"
#include "Inventory.h"
#include "History.h"

TransactionFactory::TransactionFactory() {}

TransactionFactory::~TransactionFactory() {}

Transaction* TransactionFactory::createTransaction(char actionCode)
{
    switch (toupper(actionCode))
    {
    case 'B':
        return new Borrow();
    case 'R':
        return new Return();
    case 'I':
        return new Inventory();
    case 'H':
        return new History();
    default:
        return nullptr;
    }
}