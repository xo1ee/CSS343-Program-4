#pragma once
#include "Transaction.h"
#include <string>
#include <cctype>

class TransactionFactory
{
public:
    TransactionFactory();
    ~TransactionFactory();

    /// @brief Creates a transaction based on the input action code
    /// @param actionCode The action code representing the type of transaction
    /// @return Pointer to the created Transaction object
    static Transaction *createTransaction(char actionCode);
};