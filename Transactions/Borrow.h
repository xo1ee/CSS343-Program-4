#pragma once
#include "Transaction.h"
#include "../MovieLib.h"
#include "../Movies/Movie.h"

class Borrow : public Transaction
{
public:
    Borrow();

    ~Borrow();

    bool doBorrow(MovieLib &, const string) const; // passes in data for a movie to borrow
};