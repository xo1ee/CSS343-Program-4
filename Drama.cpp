// ----------------------------------------------------- Drama.h ------------------------------------------------------
// Phohanh Tran CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/1/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - defines implementation for the functions and attributes used by the Drama parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#include "Drama.h"

// ---------------------------------------Drama::Drama()---------------------------------------
// Description
// default constructor: sets Drama values as default
// preconditions: Movie class and parameterized constructor is defined correctly
// postconditions: constructs a Drama object with all default values and a Movie parent
//                 with genre 'D'
// --------------------------------------------------------------------------------------------
Drama::Drama() : Movie('D') {}

// ---------------------------Drama::Drama(int, string, string, int)---------------------------
// Description
// paramaterized constructor: sets Drama genre, stock, director, title, and releaseYear
//                            to input values
// preconditions: input are valid, Movie parameterized constructor is defined correctly
// postconditions: constructs a Drama object and Movie parent with passed in values
// --------------------------------------------------------------------------------------------
Drama::Drama(int stock, string director,
             string title, int releaseYear) : Movie('D', stock, director,
                                                    title, releaseYear) {}

// ----------------------------------------Drama::~Drama---------------------------------------
// Description
// destructor: destructs Drama object
// preconditions: Drama class does not initialize memory
// postconditions: destructs Drama object
// --------------------------------------------------------------------------------------------
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