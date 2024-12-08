#pragma once
#include "Transaction.h"
#include "../MovieLib.h"
#include "../Movies/Movie.h"

class History : public Transaction
{
public:
    History();
    ~History();
    void doHistory(const int) const;
};