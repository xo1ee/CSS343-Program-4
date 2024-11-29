#include <iostream>
#include <vector>
#include <cassert>
#include "Movie.h"
#include "Transaction.h"

using namespace std;

bool test_hasStock()
{
    Movie movie;

    // movie.printData();

    return true;
}

bool test_validAction()
{
    Transaction transac;

    const int ascii_a = 97;
    const int ascii_A = 65;

    const vector<int> expected = {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    vector<int> actual;

    for (int letter = ascii_a; letter < ascii_a + 25; letter++)
    {
        // cout << (char)letter << ": " << transac.validAction(letter) << endl;
        actual.push_back(transac.validAction(letter));
    }
    assert(expected.size() == actual.size());
    assert(expected == actual);

    actual.clear();
    assert(actual.empty());

    for (int letter = ascii_A; letter < ascii_A + 25; letter++)
    {
        // cout << (char)letter << ": " << transac.validAction(letter) << endl;
        actual.push_back(transac.validAction(letter));
    }
    assert(expected.size() == actual.size());
    assert(expected == actual);

    return true;
}

int main()
{
    if (test_hasStock())
        cout << "Movie::hasStock works:" << endl;

    if (test_validAction())
        cout << "Transaction::validAction works" << endl;
}