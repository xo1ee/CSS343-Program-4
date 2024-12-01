// ----------------------------------------------------- Drama.h ------------------------------------------------------
// Phohanh Tran CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/1/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - defines the functions and attributes used by the Drama parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Movie.h"

class Drama : public Movie
{
protected:
    int stock;

public:
    Drama(); // default constructor

    // sets genre, stock, director, title, and releaseYear to input values
    Drama(int, string, string, int);

    ~Drama(); // default destructor

    /// @brief compares Movie data to order
    /// @param reference to other Movie
    /// @return true if the other Movie data is greater, false if else
    bool operator<(const Movie &) const override;

    /// @brief compares if Movies are the same
    /// @param reference to other Movie
    /// @return true if the other Movie is the same, false if it is different
    bool operator==(const Movie &) const override;
};