#pragma once
#include <iostream>
#include <cctype>
#include <set>
#include "Movie.h"

using namespace std;

struct ActionCodes
{
    set<char> codes = {'B', 'R', 'I', 'H'};
};

class Transaction
{
private:
    ActionCodes actionCodes;

public:
    Transaction();
    ~Transaction();

    // *Movie findMovie(string);

    /// @brief finds customer in CustomerTable by customer ID
    /// @param ID of customer to find
    /// @return true if customer with input ID is found, false if not
    bool findCustomer(int);

    /// @brief checks if the action code is valid
    /// @param action character code
    /// @return true if the code corresponds to a valid transaction, false if not
    bool validAction(char);
};