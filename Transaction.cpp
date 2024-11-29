#include "Transaction.h"

Transaction::Transaction() {}

Transaction::~Transaction() {}

// ----------------------------------Transaction::findCustomer---------------------------------
// Description
// findCustomer: returns true if a customer with an id of the input int is found
// preconditions: id may not correspond with a character
// postconditions: returns true if the id is present in CustomerTable, false if not
// --------------------------------------------------------------------------------------------
bool Transaction::findCustomer(int id)
{
    return true;
}

// ----------------------------------Transaction::validAction----------------------------------
// Description:
// validAction: checks that the input is a valid action code
// preconditions: action code may not be a letter
// postconditions: returns true if the input is a valid action code false if not
// --------------------------------------------------------------------------------------------
bool Transaction::validAction(char action)
{
    if (!isalpha(action))
        return false;

    action = toupper(action);
    return actionCodes.codes.find(action) != actionCodes.codes.end();
}