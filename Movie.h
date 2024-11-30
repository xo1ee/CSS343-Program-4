#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <string>

using namespace std;

class Movie
{
protected:
    int stock;

public:
    Movie(); // default attribute values: stock = '-', director = "Director" ,
             // title = "Title", releaseYear = "0000"

    Movie(int, string, string, string);

    virtual ~Movie();

    bool hasStock() const; // checks if movie has stock

    void addStock(); // adds to movie stock

    void removeStock(); // removes from movie stock

    virtual void printData() const; // prints movie data: Genre, Media Type,
                                    // Title, Director, Release year, Stock

    /// abstract function version
    /// @brief compares Movie data to order
    /// @param reference to other Movie
    /// @return true if the other Movie data is greater, false if else
    virtual bool operator<(const Movie &) const = 0;

    /// abstract function version
    /// @brief compares if Movies are the same
    /// @param reference to other Movie
    /// @return true if the other Movie is the same, false if it is different
    virtual bool operator==(const Movie &) const = 0;

    const char genre;     // set to '-'
    const char mediaType; // set to 'D' for all Movie classes
    const string director;
    const string title;
    const string releaseYear;
};