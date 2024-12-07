// ---------------------------------------------------- Comedy .h -----------------------------------------------------
// Phohanh Tran CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/1/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - defines implementation for the functions and attributes used by the Comedy parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#include "Comedy.h"

// --------------------------------------Comedy::Comedy()--------------------------------------
// Description
// default constructor: sets Comedy values as default
// preconditions: Movie class and parameterized constructor is defined correctly
// postconditions: constructs a Comedy object with all default values and a Movie parent
//                 with genre 'F'
// --------------------------------------------------------------------------------------------
Comedy::Comedy() : Movie('F') {}

// --------------------------Comedy::Comedy(int, string, string, int)--------------------------
// Description
// paramaterized constructor: sets Comedy genre, stock, director, title, and releaseYear
//                            to input values
// preconditions: inputs are different than Movie parent class
//                input are valid, Movie parameterized constructor is defined correctly
// postconditions: constructs a Comedy object and Movie parent with passed in values
// --------------------------------------------------------------------------------------------
Comedy::Comedy(int stock, string director,
               string title, int releaseYear) : Movie('F', stock, director,
                                                      title, releaseYear) {}

// --------------------------------Comedy::Comedy(string, int)---------------------------------
// Description
// paramaterized constructor: sets Comedy title and releaseYear to input values
// preconditions: inputs are different than Movie parent class
//                input are valid, Movie parameterized constructor is defined correctly
// postconditions: constructs a Comedy object and Movie parent with passed in values
//                 used to create a temporary Movie for search comparisons
// --------------------------------------------------------------------------------------------
Comedy::Comedy(string title, int releaseYear) : Movie('F', 0, "",
                                                      title, releaseYear) {}

// ---------------------------------------Comedy::~Comedy--------------------------------------
// Description
// destructor: destructs DrComedyama object
// preconditions: Comedy class does not initialize memory
// postconditions: destructs Comedy object
// --------------------------------------------------------------------------------------------
Comedy::~Comedy() {}

// --------------------------------------Comedy::operator<--------------------------------------
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
// operator==: checks the input movie has the exact same genre, director, title and releaseYear
//            as the current Comedy
// preconditions: Both Comedy objects are correctly instantiated, Comedy data may have different
//                capitalizations
// postconditions: returns true if the input Comedy is the same, makes no changes to either
//                 Comedy. compares current Movie with a temporary comparison Movie
// ---------------------------------------------------------------------------------------------
bool Comedy::operator==(const Movie &other) const
{
    const Comedy *otherF = dynamic_cast<const Comedy *>(&other);

    return (this->title == otherF->title) &&
           (this->releaseYear == otherF->releaseYear);
}