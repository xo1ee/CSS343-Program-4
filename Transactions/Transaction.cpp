#include "Transaction.h"

Transaction::Transaction() {}

Transaction::~Transaction() {}

// -----------------------------------Transaction::findMovie-----------------------------------
// Description
// findMovie: returns a pointer to the Movie of the input string data
// preconditions: data is correct
// postconditions: returns ta pointer to the Movie of the input string data, returns nullptr
//                 if no Movie contains input data
// --------------------------------------------------------------------------------------------
Movie *Transaction::findMovie(MovieLib library, string data)
{
    return library.search(data);
}

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

    return actionCodes.codes.count(toupper(action)) != 0;
}