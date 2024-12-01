#pragma once
#include "Movie.h"

class Drama : public Movie
{
protected:
    int stock;

public:
    Drama();
    Drama(int, string, string, int);

    ~Drama();

    /// @brief compares Movie data to order
    /// @param reference to other Movie
    /// @return true if the other Movie data is greater, false if else
    bool operator<(const Movie &) const override;

    /// @brief compares if Movies are the same
    /// @param reference to other Movie
    /// @return true if the other Movie is the same, false if it is different
    bool operator==(const Movie &) const override;
};