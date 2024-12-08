#include "Return.h"

Return::Return() {}

Return::~Return() {}

// --------------------------------------Return::doReturn---------------------------------------
// Description
// doReturn: increments the stock of the Movie whose data is passed in as a string in the passed
//           in MovieLib
// preconditions: the data is correctly formatted, containing, customerId, genre, and the
//                necessary data to identify the correct Movie
// postconditions: adds to the stock of the input movie and adds to the transaction history
//                 of the customer whose ID was passed in. returns true if doReturn was
//                 successful, false if else
// ---------------------------------------------------------------------------------------------
bool Return::doReturn(MovieLib &movieLib, const string data) const
{

    stringstream ss(data);
    int customer;
    char dataType, genre;

    ss >> customer >> dataType >> genre;

    string movieData;
    getline(ss, movieData);
    movieData.erase(0, 1);
    cout << "WITHIN DORETURN " << movieData << endl;

    Movie *movie = movieLib.search(movieData);

    if (movie == nullptr)
        return false;

    movie->addStock();
    return true;
}