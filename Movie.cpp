#include "Movie.h"

Movie::Movie() : genre('-'), stock(0), director("Anonymous"), title("Untitled"), releaseYear("0000") {}

Movie::Movie(int stock, string director, string title, string releaseYear) : stock(stock), genre('-'),
                                                                             director(director),
                                                                             title(title),
                                                                             releaseYear(releaseYear) {}
Movie::~Movie() {}

// -------------------------------------Movie::toLowerString------------------------------------
// Description
// toLowerString: changes a string to be lowercased
// preconditions: string may not contain all alphabetical characters
// postconditions: returns a copy of the input string that is lowercased
// ---------------------------------------------------------------------------------------------
string Movie::toLowerString(const string &str) const
{
    string toBeLowered = str;
    transform(toBeLowered.begin(), toBeLowered.end(),
              toBeLowered.begin(), [](unsigned char c)
              { return tolower(c); });
    return toBeLowered;
}

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

// ---------------------------------------Movie::printData--------------------------------------
// Description
// printData: prints Movie data
// preconditions: Movie is correctly instatiated
// postconditions: makes no changes to Movie
// ---------------------------------------------------------------------------------------------
void Movie::printData() const
{
    cout << genre << " " << stock << " " << director << " "
         << title << " " << releaseYear << endl;
}