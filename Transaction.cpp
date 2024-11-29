#include "Transaction.h"

Transaction::Transaction() {}

Transaction::~Transaction() {}

/**
 *
 */
bool Transaction::findCustomer(int id)
{
    return true;
}

bool Transaction::validAction(char action)
{
    action = toupper(action);
    return actionCodes.codes.find(action) != actionCodes.codes.end();
}