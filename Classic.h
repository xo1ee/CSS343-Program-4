// ---------------------------------------------------- Classic.h -----------------------------------------------------
// Phohanh Tran CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/1/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - defines the functions and attributes used by the Classic parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions. 
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Movie.h"

class Classic : public Movie
{
protected:
    int stock;

public:
    Classic(); // default constructor

    // sets genre, stock, director, title, major actor,
    // releaseMonth and releaseYear to input values
    Classic(int, string, string, string, int, int);

    ~Classic(); // destructor, empty

    // prints movie data in form: genre, stock, Release date, Major actor,
    void printData() const override;

    /// @brief compares Movie data to order
    /// @param reference to other Movie
    /// @return true if the other Movie data is greater, false if else
    bool operator<(const Movie &) const override;

    /// @brief compares if Movies are the same
    /// @param reference to other Movie
    /// @return true if the other Movie is the same, false if it is different
    bool operator==(const Movie &) const override;

    const string majorActor;
    const int releaseMonth;
};