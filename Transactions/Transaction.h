#pragma once
#include <iostream>
#include <cctype>
#include <unordered_set>
#include "../MovieLib.h"
#include "../Movies/Movie.h"

using namespace std;

struct ActionCodes
{
    unordered_set<char> codes = {'B', 'R', 'I', 'H'};
};

class Transaction
{
private:
    ActionCodes actionCodes;

public:
    Transaction();
    virtual ~Transaction();

    /// @brief finds a Movie in MovieLib by movie data
    /// @param movie data
    /// @return pointer to Movie
    Movie *findMovie(MovieLib, string);

    /// @brief finds customer in CustomerTable by customer ID
    /// @param ID of customer to find
    /// @return true if customer with input ID is found, false if not
    bool findCustomer(int);

    /// @brief checks if the action code is valid
    /// @param action character code
    /// @return true if the code corresponds to a valid transaction, false if not
    bool validAction(char);
};