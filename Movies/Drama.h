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

    // /// @brief compares if the parses input movie data and compares it to see if it's
    // /// the same as what's stored
    // /// @param string of movie data
    // /// @return true if the other Movie stores the same data, false if not
    // bool sameData(const string) const;
};