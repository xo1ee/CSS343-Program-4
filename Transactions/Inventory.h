#pragma once
#include "Transaction.h"
#include "../MovieLib.h"
#include "../Movies/Movie.h"

class Inventory : public Transaction
{
public:
    Inventory();    // basic constructor

    ~Inventory();   // basic destructor

    // prints the contents of the passed in MovieLib
    void doInventory(const MovieLib &MovieLib) const;
};