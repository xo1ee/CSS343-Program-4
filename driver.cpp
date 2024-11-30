#include <iostream>
#include <vector>
#include <cassert>
#include "Movie.h"
#include "Comedy.h"
#include "Transaction.h"

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
    Comedy comedy;
    assert(comedy.hasStock() == false);

    const int stock = 0;
    const string director = "John Smith";
    const string title = "Movie 1";
    const string releaseYear = "2024";

    Comedy comedyNoStock(stock, director, title, releaseYear);
    assert(comedyNoStock.hasStock() == false);

    const int stock2 = 10;
    Comedy comedyHasStock(stock2, director, title, releaseYear);
    assert(comedyHasStock.hasStock() == true);

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
    cout << "Passed removeStock when stock = 0 Test" << endl;
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
    Comedy emptyComedy;

    assert(!emptyComedy.hasStock());
    emptyComedy.addStock();
    assert(emptyComedy.hasStock());

    const int stock = 0;
    const string director = "John Smith";
    const string title = "Movie 1";
    const string releaseYear = "2024";

    Comedy paramComedy(stock, director, title, releaseYear);

    assert(!paramComedy.hasStock());
    paramComedy.addStock();
    assert(paramComedy.hasStock());

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
    Comedy comedy;
    test_removeStock_whenStockIs0(comedy);

    const int stock = 10;
    const string director = "John Smith";
    const string title = "Movie 1";
    const string releaseYear = "2024";

    Comedy comedyHasStock(stock, director, title, releaseYear);
    assert(comedyHasStock.hasStock());
    for (int i = 0; i < stock; i++)
        comedyHasStock.removeStock();

    test_removeStock_whenStockIs0(comedyHasStock);
    cout << "\tComedy passed removeStock when stock = 0 Test" << endl;

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
    Comedy comedy;
    Comedy comedy2;

    assert((comedy < comedy2) == false);
    cout << "Equal Comedy passed" << endl;

    const int stock = 10;
    const string director = "John Smith";
    const string title = "Movie 1";
    const string releaseYear = "2024";
    Comedy paramComedy(stock, director, title, releaseYear);

    assert((paramComedy < comedy) == true);
    cout << "\tDifferent Comedy passed" << endl;

    const string releaseYear2 = "2025";
    Comedy paramComedy2(stock, director, title, releaseYear2);

    assert((paramComedy < paramComedy2) == true);
    cout << "\tComedy of same title different year passed" << endl;

    const string title3 = "Movie 2";
    Comedy paramComedy3(stock, director, title3, releaseYear2);

    assert((paramComedy2 < paramComedy3) == true);
    cout << "\tComedy of different title same year passed" << endl;

    Comedy paramComedy4(stock, director, title, releaseYear);
    assert((paramComedy < paramComedy4) == false);
    cout << "\tComedy with same data passed" << endl;

    const string titleLowered = "movie";
    Comedy paramComedy5(stock, director, titleLowered, releaseYear);

    const string titleCapped = "MOVIE";
    Comedy paramComedy6(stock, director, titleLowered, releaseYear);
    assert((paramComedy5 < paramComedy6) == false);
    cout << "\tComedy with differently-cased title passed" << endl;

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
    Comedy comedy;
    Comedy comedy2;

    assert(comedy == comedy2);
    cout << "\tEmpty comedy passed" << endl;

    const int stock = 10;
    const string director = "John Smith";
    const string title = "Movie 1";
    const string releaseYear = "2024";
    Comedy paramComedy(stock, director, title, releaseYear);
    Comedy paramComedy2(stock, director, title, releaseYear);
    assert(paramComedy == paramComedy2);
    cout << "\tComedy with params passed" << endl;

    assert(!(comedy == paramComedy2));
    cout << "\tComedy with different data passed" << endl;

    const string titleCapped = "MOVIE 1";
    Comedy paramComedyCapped(stock, director, titleCapped, releaseYear);
    assert(paramComedy == paramComedyCapped);

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
    if (test_hasStock())
        cout << "Movie::hasStock works:" << endl;

    if (test_addStock())
        cout << "Movie::addStock works:" << endl;

    if (test_removeStock())
        cout << "Movie::removeStock works:" << endl;

    if (test_greaterThan())
        cout << "Movie::operator< works:" << endl;

    if (test_equalTo())
        cout << "Movie::operator== works:" << endl;

    if (test_validAction())
        cout << "Transaction::validAction works" << endl;
}