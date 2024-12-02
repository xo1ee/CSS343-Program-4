// ---------------------------------------------------- Movie.cpp -----------------------------------------------------
// Phohanh Tran CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/1/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - implements the functions and attributes used by the Movie parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions. 
// --------------------------------------------------------------------------------------------------------------------
#include "Movie.h"

// ----------------------------------------Movie::Movie----------------------------------------
// Description
// default constructor: sets Movie values as default
// preconditions: Movie class is defined correctly
// postconditions: constructs a Movie object with all default values
// --------------------------------------------------------------------------------------------
Movie::Movie() : mediaType('D'), genre('-'), stock(0),
                 director(""), title(""), releaseYear(0) {}

// -------------------------------------Movie::Movie(char)-------------------------------------
// Description
// paramaterized constructor 1: sets Movie values as default, except for genre
// preconditions: inputs are valid, will be passed in a valid genre character, to be used
//                by Movie subclasses in the default constructor
// postconditions: constructs a Movie object with all default values, except genre
//                 the constructed Movie will be stored by Movie subclasses when constructed
//                 with their default constructor
// --------------------------------------------------------------------------------------------
Movie::Movie(char genre) : mediaType('D'), genre(genre), stock(0),
                           director(""), title(""), releaseYear(0) {}

// ------------------------Movie::Movie(char, int, string, string, int)------------------------
// Description
// paramaterized constructor 2: sets Movie genre, stock, director, title, and releaseYear
//                              to input values
// preconditions: input are valid, will be used in Movie subclass paramaterized constructors
// postconditions: constructs a Movie object with passed in values,
//                 the constructed Movie will be stored by Movie subclasses when constructed
//                 with their paramaterized constructor
// --------------------------------------------------------------------------------------------
Movie::Movie(char genre, int stock, string director,
             string title, int releaseYear) : mediaType('D'), genre(genre),
                                              stock(stock),
                                              director(director),
                                              title(title),
                                              releaseYear(releaseYear) {}

// ----------------------------------------Movie::~Movie---------------------------------------
// Description
// destructor: destructs Movie object
// preconditions: Movie class does not initialize memory
// postconditions: destructs Movie object
// --------------------------------------------------------------------------------------------
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