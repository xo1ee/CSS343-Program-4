#include "Movie.h"

Movie::Movie() : genre('-'), stock(0), director("Director"), title("Title"), releaseYear("0000") {}

Movie::~Movie() {}

// ---------------------------------------Movie::hasStock--------------------------------------
// Description
// hasStock: checks if the movie has stock
// preconditions: Movie is correctly instatiated
// postconditions: returns true if the movie has stock over 0, false if not, and throws an
//                 error if the stock is negative
// --------------------------------------------------------------------------------------------
bool Movie::hasStock() const
{
    if (stock < 0)
        throw invalid_argument("Movie stock is negative");

    return stock > 0;
}

// ---------------------------------------Movie::addStock--------------------------------------
// Description
// addStock: adds to the movie stock
// preconditions: Movie is correctly instatiated
// postconditions: adds to movie stock, should be called when Return::doReturn is called
// --------------------------------------------------------------------------------------------
void Movie::addStock()
{
    stock++;
}

// --------------------------------------Movie::removeStock-------------------------------------
// Description
// removeStock: removes from the movie stock
// preconditions: Movie is correctly instatiated and does not have empty stock
// postconditions: removes from movie stock, should be called when Return::doBorrow is called
// ---------------------------------------------------------------------------------------------
void Movie::removeStock()
{
    if (stock < 0)
        throw invalid_argument("Movie stock is negative");

    if (stock == 0)
        throw invalid_argument("Movie is not in stock");

    stock--;
}

// // ---------------------------------------Movie::printData--------------------------------------
// // Description
// // printData: prints movie data
// // preconditions: Movie is correctly instatiated
// // postconditions: makes no changes to Movie
// // ---------------------------------------------------------------------------------------------
// void Movie::printData() const
// {
//     cout << genre << " " << stock << " " << director << " "
//          << title << " " << releaseYear << endl;
// }

// // --------------------------------------Movie::operator<--------------------------------------
// // Description
// // printData: compares the ordering data of the input and current Movie
// // preconditions: Both Movie objects are correctly instantiated
// // postconditions: returns true if the input Movie is greater, makes no changes to either Movie
// // ---------------------------------------------------------------------------------------------
// bool Movie::operator<(const Movie &) const { return true; }

// // -------------------------------------Movie::operator==--------------------------------------
// // Description
// // printData: checks the input Movie is the same as the current Movie
// // preconditions: Both Movie objects are correctly instantiated
// // postconditions: returns true if the input Movie is the same, makes no changes to either Movie
// // ---------------------------------------------------------------------------------------------
// bool Movie::operator==(const Movie &) const { return true; }