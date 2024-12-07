#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "MovieLib.h"
#include "Movies/MovieFactory.h"
#include "Movies/Movie.h"
#include "Movies/Comedy.h"
#include "Movies/Drama.h"
#include "Movies/Classic.h"
#include "Transactions/Transaction.h"

using namespace std;

// -----------------------------------------printMovie-----------------------------------------
// Description
// printMovie: helper function, calls Movie::printData() after printing '\t' for easier
//             debugging
// preconditions: Movie is correctly defined
// postconditions: makes no changes
// --------------------------------------------------------------------------------------------
void printMovie(Movie &movie)
{
    cout << "\tPrint Movie:" << endl;
    cout << "\t";
    movie.printData();
}

// ----------------------------------------test_hasStock---------------------------------------
// Description
// test_hasStock: tests Movie::hasStock()
// preconditions: Movie is correctly defined
// postconditions: contains asserts which will hault program if outputs are not as expected
// --------------------------------------------------------------------------------------------
bool test_hasStock()
{
    const int stock = 0;
    const string director = "John Smith";
    const string title = "Movie 1";
    const int releaseYear = 2024;
    const int stock2 = 10;

    /** COMEDY TESTS */
    Comedy comedy;
    assert(comedy.hasStock() == false);

    Comedy comedyNoStock(stock, director, title, releaseYear);
    assert(comedyNoStock.hasStock() == false);

    Comedy comedyHasStock(stock2, director, title, releaseYear);
    assert(comedyHasStock.hasStock() == true);

    /** DRAMA TESTS  */
    Drama drama;
    assert(drama.hasStock() == false);
    Drama dramaNoStock(stock, director, title, releaseYear);
    assert(dramaNoStock.hasStock() == false);

    Drama dramaHasStock(stock2, director, title, releaseYear);
    assert(dramaHasStock.hasStock() == true);

    /** CLASSIC TESTS */

    return true;
}

// --------------------------------test_removeStock_whenStockIs0-------------------------------
// Description
// test_removeStock_whenStockIs0: helper function for test_removeStock(). Tests removeStock()
//                                throws an exception when removing from a movie with no stock
// preconditions: Movie is correctly defined
// postconditions: contains asserts which will hault program if outputs are not as expected
// --------------------------------------------------------------------------------------------
void test_removeStock_whenStockIs0(Movie &movie)
{
    // printMovie(movie);

    bool exceptionThrown = false;
    try
    {
        movie.removeStock();
    }
    catch (const std::invalid_argument &e)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown == true);
    assert(!movie.hasStock());
    cout << "\tPassed removeStock when stock = 0 Test" << endl;
}

// ----------------------------------------test_addStock---------------------------------------
// Description
// test_addStock: tests Movie::addStock() with a Comedy created with and without parameterized
//                constructor
// preconditions: Movie is correctly defined
// postconditions: contains asserts which will hault program if outputs are not as expected
// --------------------------------------------------------------------------------------------
bool test_addStock()
{
    const int stock = 0;
    const string director = "John Smith";
    const string title = "Movie 1";
    const int releaseYear = 2024;

    /** COMEDY TESTS */
    Comedy emptyComedy;

    assert(!emptyComedy.hasStock());
    emptyComedy.addStock();
    assert(emptyComedy.hasStock());

    Comedy paramComedy(stock, director, title, releaseYear);

    assert(!paramComedy.hasStock());
    paramComedy.addStock();
    assert(paramComedy.hasStock());

    return true;

    /** DRAMA TESTS */
    Drama emptyDrama;

    assert(!emptyDrama.hasStock());
    emptyDrama.addStock();
    assert(emptyDrama.hasStock());

    Drama paramDrama(stock, director, title, releaseYear);

    assert(!paramDrama.hasStock());
    paramDrama.addStock();
    assert(paramDrama.hasStock());

    /** CLASSIC TESTS */

    return true;
}

// --------------------------------------test_removeStock--------------------------------------
// Description
// test_removeStock: tests Movie::removeStock()
// preconditions: Movie is correctly defined
// postconditions: contains asserts which will hault program if outputs are not as expected
// --------------------------------------------------------------------------------------------
bool test_removeStock()
{
    const int stock = 10;
    const string director = "John Smith";
    const string title = "Movie 1";
    const int releaseYear = 2024;

    /**
     * COMEDY TESTS
     */
    Comedy comedy;
    test_removeStock_whenStockIs0(comedy);
    Comedy comedyHasStock(stock, director, title, releaseYear);
    assert(comedyHasStock.hasStock());
    for (int i = 0; i < stock; i++)
        comedyHasStock.removeStock();

    test_removeStock_whenStockIs0(comedyHasStock);
    cout << "\tComedy passed removeStock when stock = 0 Test" << endl;

    /**
     * DRAMA TESTS
     */
    Drama drama;
    test_removeStock_whenStockIs0(drama);

    Drama dramaHasStock(stock, director, title, releaseYear);
    assert(dramaHasStock.hasStock());
    for (int i = 0; i < stock; i++)
        dramaHasStock.removeStock();

    test_removeStock_whenStockIs0(dramaHasStock);
    cout << "\tDrama passed removeStock when stock = 0 Test" << endl;

    /**
     * CLASSIC TESTS
     */
    // Classic classic;
    // test_removeStock_whenStockIs0(classic);

    // Classic classicHasStock(stock, director, title, releaseYear);
    // assert(classicHasStock.hasStock());
    // for (int i = 0; i < stock; i++)
    //     classicHasStock.removeStock();

    // test_removeStock_whenStockIs0(classicHasStock);
    // cout << "\tClassic passed removeStock when stock = 0 Test" << endl;

    return true;
}

// --------------------------------------test_greaterThan--------------------------------------
// Description
// test_greaterThan: tests Movie::operator<()
// preconditions: Movie is correctly defined
// postconditions: contains asserts which will hault program if outputs are not as expected
// --------------------------------------------------------------------------------------------
bool test_greaterThan()
{
    const int stock = 10;
    const string director = "John Smith";
    const string director2 = "Orange Man";
    const string title = "Movie 1";
    const int releaseYear = 2024;
    const int releaseYear2 = 2025;
    const string title3 = "Movie 2";
    const string titleLowered = "movie";
    const string titleCapped = "MOVIE";

    /** COMEDY TESTS */
    Comedy comedy;
    Comedy comedy2;

    assert((comedy < comedy2) == false);
    cout << "Equal Comedy passed" << endl;

    Comedy paramComedy(stock, director, title, releaseYear);

    assert((paramComedy < comedy) == false);
    cout << "\tDifferent Comedy passed" << endl;

    Comedy paramComedy2(stock, director, title, releaseYear2);

    printMovie(paramComedy);
    printMovie(paramComedy2);
    assert((paramComedy < paramComedy2) == true);
    cout << "\tComedy of same title different year passed" << endl;

    Comedy paramComedy3(stock, director, title3, releaseYear2);

    assert((paramComedy2 < paramComedy3) == true);
    cout << "\tComedy of different title same year passed" << endl;

    Comedy paramComedy4(stock, director, title, releaseYear);
    assert((paramComedy < paramComedy4) == false);
    cout << "\tComedy with same data passed" << endl;

    Comedy paramComedy5(stock, director, title, releaseYear);

    Comedy paramComedy6(stock, director, titleLowered, releaseYear);
    printMovie(paramComedy5);
    printMovie(paramComedy6);
    assert((paramComedy5 < paramComedy6) == true);
    cout << "\tComedy with differently-cased title passed" << endl;

    /** DRAMA TESTS */
    Drama drama;
    Drama drama2;

    assert((drama < drama2) == false);
    cout << "Equal Drama passed" << endl;

    Drama paramDrama(stock, director, title, releaseYear);

    assert((paramDrama < drama) == false);
    cout << "\tDifferent Drama passed" << endl;

    Drama paramDrama2(stock, director, title3, releaseYear);
    assert((paramDrama < paramDrama2) == true);
    cout << "\tDrama with same director different title passed" << endl;

    Drama paramDrama3(stock, director2, title3, releaseYear);
    assert((paramDrama2 < paramDrama3) == true);
    cout << "\tDrama with different director same title passed" << endl;

    Drama paramDrama4(stock, director, title, releaseYear);
    assert((paramDrama < paramDrama4) == false);
    cout << "\tDrama with same data passed" << endl;

    /** CLASSIC TESTS */

    return true;
}

// ----------------------------------------test_equalTo----------------------------------------
// Description
// test_equalTo: tests Movie::operator<()
// preconditions: Movie is correctly defined
// postconditions: contains asserts which will hault program if outputs are not as expected
// --------------------------------------------------------------------------------------------
bool test_equalTo()
{
    const int stock = 10;
    const string director = "John Smith";
    const string title = "Movie 1";
    const int releaseYear = 2024;
    const string titleCapped = "MOVIE 1";

    /** COMEDY TESTS */
    Comedy comedy;
    Comedy comedy2;

    assert(comedy == comedy2);
    cout << "\tEmpty comedy passed" << endl;

    Comedy paramComedy(stock, director, title, releaseYear);
    Comedy paramComedy2(stock, director, title, releaseYear);
    assert(paramComedy == paramComedy2);
    cout << "\tComedy with params passed" << endl;

    assert(!(comedy == paramComedy2));
    cout << "\tComedy with different data passed" << endl;

    Comedy paramComedyCapped(stock, director, titleCapped, releaseYear);
    assert(!(paramComedy == paramComedyCapped));
    cout << "\tComedy with capitalized title passed" << endl;

    /** DRAMA TESTS */
    Drama drama;
    Drama drama2;

    assert(drama == drama2);
    cout << "\tEmpty drama passed" << endl;

    Drama paramDrama(stock, director, title, releaseYear);
    Drama paramDrama2(stock, director, title, releaseYear);
    assert(paramDrama == paramDrama2);
    cout << "\tDrama with params passed" << endl;

    assert(!(drama == paramDrama));
    cout << "\tDrama with different data passed" << endl;

    Drama paramDramayCapped(stock, director, titleCapped, releaseYear);
    assert(!(paramDrama == paramDramayCapped));
    cout << "\tDrama with capitalized title passed" << endl;

    /** CLASSIC TESTS */

    return true;
}

// --------------------------------------test_createMovie--------------------------------------
// Description
// test_createMovie: tests MovieFactory::createMovie()
// preconditions: MovieFactory and Movie subclasses are correctly defined
// postconditions: tests MovieFactory can create movies based on movie data
// --------------------------------------------------------------------------------------------
bool test_createMovie()
{
    MovieFactory moviefac;

    vector<string> testData = {
        "F, 10, Nora Ephron, You've Got Mail, 1998",
        "D, 10, Steven Spielberg, Schindler's List, 1993",
        "C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938",
        "C, 10, George Cukor, Holiday, Cary Grant 9 1938",
        "Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971",
        "D, 10, Phillippe De Broca, King of Hearts, 1967",
    };

    // cout << "\tMOVIE LIBRARY CONTENTS: " << endl;
    int count = 0;
    for (string line : testData)
    {
        // cout << count++ << "th movie!" << endl;
        // cout << "\t";
        Movie *movie = moviefac.createMovie(line);
        if (movie == nullptr)
            continue;
    }
    // cout << "END" << endl;

    return true;
}

// --------------------------------------test_insertMovie--------------------------------------
// Description
// test_insertMovie: tests MovieLibrary::insertMovie()
// preconditions: MovieLib, MovieFactory and Movie subclasses are correctly defined
// postconditions: tests insertMovie functionality
// --------------------------------------------------------------------------------------------
bool test_insertMovie()
{
    MovieLib movielib;
    MovieFactory fac;
    // // VECTOR VERSION
    // vector<string>
    //     testData = {
    //         // "F, 10, a, TITLE1, 1998",
    //         // "F, 10, a, TITLE2, 1999",
    //         // "F, 10, a, TITLE2, 1998",
    //         // "F, 10, a, TITLE2, 1000",
    //         // "F, 10, a, TITLE2, 2000",
    //         // "F, 10, a, TITLE3, 1993",
    //         // "F, 10, a, TITLE4, 2003",

    //         // "D, 10, b, cTitle, 2000",
    //         // "D, 10, b, bTitle, 2000",
    //         // "D, 10, a, bTitle, 2000",
    //         // "D, 10, a, cTitle, 2000",
    //         // "D, 10, a, aTitle, 2000",
    //         // "D, 10, c, aTitle, 2000",
    //         // "D, 10, b, aTitle, 2000",

    //         // "C, 10, a, TITLE1, John Smith 3 1998",
    //         // "C, 10, a, TITLE1, John Smith 2 1998", // previous month
    //         // "C, 10, a, TITLE1, John Smith 4 1997", // next year
    //         "C, 10, a, TITLE1, Amy Smith 3 1998",
    //         "C, 10, a, TITLE1, Amy Smith 3 2000",
    //         "C, 10, a, TITLE1, John Smith 3 2000",
    //         "C, 10, a, TITLE1, John Smith 6 1998",

    //     };
    // for (string line : testData)
    // {
    //     assert(movielib.insert(line));
    //     // movielib.print();
    // }

    // // FILE INPUT VERSION

    ifstream infile("data4movies.txt");
    if (!infile)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }

    string line;
    while (!infile.eof())
    {
        char genre;
        getline(infile, line);

        Movie *newMovie = fac.createMovie(line);
        // cout << "INSERT: " << line << endl;

        if (line == "")
            break;

        genre = line[0];
        GenreCodes genreCodes;
        if (genreCodes.codes.count(toupper(genre)) == 0)
        {
            assert(movielib.insert(line) == false);
            continue;
        }

        assert(movielib.insert(line));
        // movielib.print();
    }
    movielib.print();

    return true;
}

// -----------------------------------------test_search----------------------------------------
// Description
// test_search: tests MovieLibrary::search()
// preconditions: MovieLib, MovieLibrary and Movie subclasses are correctly defined
// postconditions: tests search functionality
// --------------------------------------------------------------------------------------------
bool test_search()
{
    MovieLib storeActual;
    MovieFactory createExpected;

    vector<string> testData = {
        "F, 10, Nora Ephron, You've Got Mail, 1998",
        "D, 10, Steven Spielberg, Schindler's List, 1993",
        "C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938",
        "C, 10, George Cukor, Holiday, Cary Grant 9 1938",
        "Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971",
        "D, 10, Phillippe De Broca, King of Hearts, 1967",
    };

    for (string line : testData)
        storeActual.insert(line);
    storeActual.print();

    vector<Movie *> movies;
    int count = 0;

    for (string line : testData)
    {
        cout << "\t" << count++ << "th line ";
        cout << line << endl;

        Movie *inLibrary = storeActual.search(line);
        Movie *movie = createExpected.createMovie(line);
        if (movie == nullptr)
            continue;

        // cout << "THE NODE FROM THE LIBRARY: " << endl;
        // inLibrary->printData();
        // cout << "THE NODE WE WANT: " << endl;
        // movie->printData();
        assert(*movie == *inLibrary);
    }

    return true;
}

// -----------------------------------------test_search2---------------------------------------
// Description
// test_search2: tests MovieLibrary::search()
// preconditions: MovieLib, MovieLibrary and Movie subclasses are correctly defined
// postconditions: tests search functionality in the context of how transaction commands
//                 are formatted
// --------------------------------------------------------------------------------------------
bool test_search2()
{
    MovieLib storeActual;
    MovieFactory createExpected;
    vector<string> testDataStore = {
        "F, 10, Nora Ephron, You've Got Mail, 1998",
        "D, 10, Steven Spielberg, Schindler's List, 1993",
        "C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938",
        "C, 10, George Cukor, Holiday, Cary Grant 9 1938",
        "Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971",
        "D, 10, Phillippe De Broca, King of Hearts, 1967",
    };

    vector<string> testDataSearch = {
        "F You've Got Mail, 1998",
        "D Steven Spielberg, Schindler's List",
        "C 9 1938 Katherine Hepburn",
        "C 9 1938 Cary Grant",
        "Z Harold and Maude, Ruth Gordon 2 1971",
        "D Phillippe De Broca, King of Hearts",
    };

    vector<string> testDataNotStored = {
        "D Barry Levinson, Good Morning Vietnam",
        "C 5 1940 Katherine Hepburnd",
        "F Sleepless in Seattle, 1993",
        "C 2 1971 Malcolm McDowell",
        "C 3 1971 Ruth Gordon",
        "C 9 1938 Joe Schmo",
    };

    for (string line : testDataStore)
        storeActual.insert(line);

    storeActual.print();

    vector<Movie *> movies;
    int count = 0;

    for (string line : testDataSearch)
    {
        stringstream ss1(line);
        char genre;
        ss1 >> genre;

        Movie *inLibrary = storeActual.search(line);
        line.erase(0, 2);
        Movie *movie = createExpected.createTemp(genre, line);
        if (movie == nullptr)
            continue;

        cout << "THE NODE FROM THE LIBRARY: " << endl;
        inLibrary->printData();
        cout << "THE NODE WE WANT: " << endl;
        movie->printData();
        assert(*movie == *inLibrary);
    }

    for (string line : testDataNotStored)
    {
        stringstream ss1(line);
        char genre;
        ss1 >> genre;
        line.erase(0, 2);
        cout << "\t" << count++ << "th line: ";
        cout << "Genre: [" << genre << "]" << endl;
        cout << line << endl;

        Movie *inLibrary = storeActual.search(line);
        Movie *movie = createExpected.createTemp(line[0], line);
        if (movie == nullptr)
            continue;

        cout << "THE NODE FROM THE LIBRARY: " << endl;
        inLibrary->printData();
        cout << "THE NODE WE WANT: " << endl;
        movie->printData();
        assert(!(*movie == *inLibrary));
    }

    return true;
}

// --------------------------------------test_validAction--------------------------------------
// Description
// test_validAction: tests Transaction::validAction() with lowercase and uppercase alphabetical
//                   input, numerical input, and symbol character input
// preconditions: Transaction is correctly defined
// postconditions: contains asserts which will hault program if outputs are not as expected
// --------------------------------------------------------------------------------------------
bool test_validAction()
{
    Transaction transac;

    const int ascii_a = 97;
    const int ascii_A = 65;

    const vector<int> expectedAlpha = {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    vector<int> actual;

    for (int letter = ascii_a; letter < ascii_a + 25; letter++)
    {
        // cout << (char)letter << ": " << transac.validAction(letter) << endl;
        actual.push_back(transac.validAction(letter));
    }
    assert(expectedAlpha.size() == actual.size());
    assert(expectedAlpha == actual);
    cout << "\tLowercase Tests passed" << endl;

    actual.clear();
    assert(actual.empty());

    for (int letter = ascii_A; letter < ascii_A + 25; letter++)
    {
        // cout << (char)letter << ": " << transac.validAction(letter) << endl;
        actual.push_back(transac.validAction(letter));
    }
    assert(expectedAlpha.size() == actual.size());
    assert(expectedAlpha == actual);
    cout << "\tUppercase Tests passed" << endl;

    actual.clear();
    assert(actual.empty());

    const vector<char> input = {'1', '2', '3', '[', '=', '~', '\''};
    const vector<int> expected = {0, 0, 0, 0, 0, 0, 0};
    assert(input.size() == expected.size());

    for (int i = 0; i < input.size(); i++)
    {
        // cout << input[i] << ": " << transac.validAction(input[i]) << endl;
        actual.push_back(transac.validAction(input[i]));
    }
    assert(expected.size() == actual.size());
    assert(expected == actual);
    cout << "\tOther Char Tests passed" << endl;

    return true;
}

int main()
{
    // // Movie method tests
    // if (test_hasStock())
    //     cout << "Movie::hasStock works:" << endl;

    // if (test_addStock())
    //     cout << "Movie::addStock works:" << endl;

    // if (test_removeStock())
    //     cout << "Movie::removeStock works:" << endl;

    // if (test_greaterThan())
    //     cout << "Movie::operator< works:" << endl;

    // if (test_equalTo())
    //     cout << "Movie::operator== works:" << endl;

    // // MovieFactory method tests
    // if (test_createMovie())
    //     cout << "MovieFactory::createMovie works" << endl;

    // // MovieLibrary method tests
    // if (test_insertMovie())
    //     cout << "MovieLibrary::insertMovie works" << endl;

    if (test_search2())
        cout << "MovieLibrary::search works (2)" << endl;

    // // Transaction method tests if (test_validAction())
    // cout << "Transaction::validAction works" << endl;
}