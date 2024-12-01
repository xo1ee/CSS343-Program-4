#include "Movie.h"

Movie::Movie() : genre('-'), stock(0), mediaType('D'), director(""), title(""), releaseYear(0) {}

Movie::Movie(int stock, string director, string title, int releaseYear) : stock(stock), genre('-'),
                                                                          mediaType('D'),
                                                                          director(director),
                                                                          title(title),
                                                                          releaseYear(releaseYear) {}
Movie::~Movie() {}

// ------------------------------------Movie::toLowerString------------------------------------
// Description
// toLowerString: lowercases input string
// preconditions: input string may not have all alphabetical characters
// postconditions: returns copy of string with all alphabetical characters lowercased
// --------------------------------------------------------------------------------------------
string Movie::toLowerString(const string str) const
{
    string toLower = str;
    transform(toLower.begin(), toLower.end(), toLower.begin(),
              [](unsigned char c)
              { return tolower(c); });
    return toLower;
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
// printData: prints Movie data in form: Genre, Media Type, Title, Director, Release year,
//            Stock
// preconditions: Movie is correctly instatiated
// postconditions: makes no changes to Movie
// ---------------------------------------------------------------------------------------------
void Movie::printData() const
{
    cout << left << setw(6) << genre
         << setw(8) << mediaType
         << setw(35) << title
         << setw(20) << director
         << setw(6) << releaseYear
         << stock
         << endl;
}