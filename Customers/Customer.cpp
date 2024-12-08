// ---------------------------------------------------- Customer.cpp -----------------------------------------------------
// Kyle Lai CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/6/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - defines implementation for the functions and attributes used by the Customer parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#include "Customer.h"
#include <iostream>
using namespace std;

// constructor ----------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
Customer::Customer()
{

    setFirstName("");
    setLastName("");
    setCustomerID("");
}

// constructor ----------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
Customer::Customer(string first, string last, string id)
{
    setFirstName(first);
    setLastName(last);
    setCustomerID(id);
}

// desstructor ----------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
Customer::~Customer()
{
}

// setCustomerData -------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
bool Customer::setCustomerData(string first, string last, string id)
{
    return setFirstName(first) &&
           setLastName(last) &&
           setCustomerID(id);
}

// setCustomerID --------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
bool Customer::setCustomerID(string id)
{
    if (id.length() == ID_SIZE)
    {
        customerID = id;
        return true;
    }
    else
    {
        return false;
    }
}

// setFirstName --------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
bool Customer::setFirstName(string first)
{
    firstName = first;
    return true;
}

// setLastName ----------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
bool Customer::setLastName(string last)
{
    lastName = last;
    return true;
}

// getCustomerID --------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
string Customer::getCustomerID() const
{
    return customerID;
}

// getFirstName ---------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
string Customer::getFirstName() const
{
    return firstName;
}

// getLastName --------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
string Customer::getLastName() const
{
    return lastName;
}

// hash -----------------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
int Customer::hash() const
{
    string str = customerID;

    int retVal = 0;
    for (int i = 0; i < str.size(); i++)
    {
        retVal += str[i];
    }
    return retVal;
}

void Customer::updateHistoryLog(string history)
{
    historyLog.push_back(history);
}

// operator<< -----------------------------------------------------------
// Description:
// Precondition: NONE
// Features:
// ----------------------------------------------------------------------
ostream &operator<<(ostream &ostream, const Customer &rhs)
{
    ostream << "\tCustomer Name [" << rhs.getFirstName() << " ";
    ostream << rhs.getLastName() << "] ";
    ostream << "\tID [" << rhs.getCustomerID() << "] " << endl;
    for (int i = 0; i < rhs.historyLog.size(); i++)
    {
        ostream << "\t    " << rhs.historyLog[i] << endl;
    }

    return ostream;
}