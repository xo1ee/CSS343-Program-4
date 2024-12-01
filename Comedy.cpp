#include "Comedy.h"

Comedy::Comedy() : Movie() {}

Comedy::Comedy(int stock, string director,
               string title, int releaseYear) : Movie('F', stock, director,
                                                      title, releaseYear) {}

Comedy::~Comedy() {}

// --------------------------------------Comedy::operaor<--------------------------------------
// Description
// operator<: compares the ordering data of the input and current Comedy by alphabetical value
//            of title then release year
// preconditions: Comedy is correctly instatiated, Comedy data may have different
//                capitalizations
// postconditions: returns true if the input Comedy is greater, makes no changes to either
//                 Comedy
// ---------------------------------------------------------------------------------------------
bool Comedy::operator<(const Movie &other) const
{
    const Comedy *otherF = dynamic_cast<const Comedy *>(&other);

    if (this->title < otherF->title)
        return true;

    if (this->title == otherF->title)
    {
        return this->releaseYear < otherF->releaseYear;
    }
    return false;
}

// --------------------------------------Comedy::operator==-------------------------------------
// Description
// printData: checks the input movie has the exact same genre, director, title and releaseYear
//            as the current Comedy
// preconditions: Both Comedy objects are correctly instantiated, Comedy data may have different
//                capitalizations
// postconditions: returns true if the input Comedy is the same, makes no changes to either
//                 Comedy
// ---------------------------------------------------------------------------------------------
bool Comedy::operator==(const Movie &other) const
{
    const Comedy *otherF = dynamic_cast<const Comedy *>(&other);

    return (this->director == otherF->director) &&
           (this->title == otherF->title) &&
           (this->releaseYear == otherF->releaseYear);
}