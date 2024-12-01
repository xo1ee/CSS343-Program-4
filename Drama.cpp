#include "Drama.h"

Drama::Drama() : Movie(), genre('D') {}

Drama::Drama(int stock, string director, string title, int releaseYear) : Movie(stock, director, title, releaseYear),
                                                                          genre('D') {}

Drama::~Drama() {}

// --------------------------------------Drama::operaor<--------------------------------------
// Description
// operator<: compares the ordering data of the input and current Drama by alphabetical value
//            of director then title
// preconditions: Drama is correctly instatiated, Drama data may have different
//                capitalizations
// postconditions: returns true if the input Drama is greater, makes no changes to either
//                 Drama
// ---------------------------------------------------------------------------------------------
bool Drama::operator<(const Movie &other) const
{
    const Drama *otherD = dynamic_cast<const Drama *>(&other);

    if (this->director < otherD->director)
        return true;

    if (this->director == otherD->director &&
        this->title < otherD->title)
        return true;
    return false;
}

// --------------------------------------Drama::operator==-------------------------------------
// Description
// printData: checks the input movie has the exact same genre, director, title and releaseYear
//            as the current Drama
// preconditions: Both Drama objects are correctly instantiated, Drama data may have different
//                capitalizations
// postconditions: returns true if the input Drama is the same, makes no changes to either
//                 Drama
// ---------------------------------------------------------------------------------------------
bool Drama::operator==(const Movie &other) const
{
    const Drama *otherD = dynamic_cast<const Drama *>(&other);

    return (this->director == otherD->director) &&
           (this->title == otherD->title) &&
           (this->releaseYear == otherD->releaseYear);
}