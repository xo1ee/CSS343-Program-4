#pragma once
#include "Movie.h"

class Comedy : public Movie
{
protected:
    int stock;

public:
    Comedy();
    Comedy(int, string, string, string);

    ~Comedy();

    /// @brief compares Movie data to order
    /// @param reference to other Movie
    /// @return true if the other Movie data is greater, false if else
    bool operator<(const Movie &) const override;

    /// @brief compares if Movies are the same
    /// @param reference to other Movie
    /// @return true if the other Movie is the same, false if it is different
    bool operator==(const Movie &) const override;

    const char genre; // set to 'F'
    const string director;
    const string title;
    const string releaseYear;
};