#include "Borrow.h"

Borrow::Borrow() : Transaction() {}

Borrow::~Borrow() {}

// --------------------------------------Borrow::doBorrow---------------------------------------
// Description
// doBorrow: decrements the stock of the Movie whose data is passed in as a string in the passed
//           in MovieLib
// preconditions: the data is correctly formatted, containing, customerId, genre, and the
//                necessary data to identify the correct Movie
// postconditions: removes from the stock of the input movie and adds to the transaction history
//                 of the customer whose ID was passed in. returns true if doBorrow was
//                 successful, false if else
// ---------------------------------------------------------------------------------------------
bool Borrow::doBorrow(MovieLib &movieLib, const string data) const
{
    stringstream ss(data);
    int customer;
    char dataType;

    ss >> customer >> dataType;

    string movieData;
    getline(ss, movieData);

    movieData.erase(0, 1);

    Movie *movie = movieLib.search(movieData);

    if (movie == nullptr || !movie->hasStock())
        return false;

    if (movie->genre == 'C')
    {
        Classic *classic = dynamic_cast<Classic *>(movie);
        if (!classic->actorHasStock(classic->getActor()))
            return false;
    }

    movie->removeStock();
    return true;
}
