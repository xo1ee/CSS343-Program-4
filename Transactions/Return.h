#pragma once
#include "Transaction.h"
#include "../MovieLib.h"
#include "../Movies/Movie.h"

class Return : public Transaction
{
public:
    Return();

    ~Return();

    bool doReturn(MovieLib &, const string) const; // adds to the stock of the input movie
};