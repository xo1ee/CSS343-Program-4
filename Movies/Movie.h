// ----------------------------------------------------- Movie.h ------------------------------------------------------
// Phohanh Tran CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/1/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - defines the functions and attributes used by the Movie parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Movie
{
protected:
    int stock;

public:
    // default attribute values: mediaType = 'D',
    // genre = '-', stock = 0, director = "" ,
    // title = "", releaseYear = 0
    Movie();

    // default attribute values: mediaType = 'D', stock = 0, director = "" ,
    // title = "", releaseYear = 0
    // sets genre value as input
    Movie(char);

    // default attribute values: mediaType = 'D'
    // set genre, stock, director, title, releaseYear, release year as input
    Movie(char, int, string, string, int);

    string toLowerString(const string) const; // lower-cases a string

    virtual ~Movie(); // default destructor, virtual for subclasses with different implmenetations

    bool hasStock() const; // checks if movie has stock

    virtual void addStock(); // adds to movie stock

    virtual void removeStock(); // removes from movie stock

    int getStock() const; // returns movie stock

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

    // /// @brief compares if the parses input movie data and compares it to see if it's
    // /// the same as what's stored
    // /// @param string of movie data
    // /// @return true if the other Movie stores the same data, false if not
    // virtual bool sameData(string) const = 0;

    const char genre;     // set to '-', unless parameterized constructor used
    const char mediaType; // set to 'D' for all Movie classes
    const string director;
    const string title;
    const int releaseYear;

    Movie *left;
    Movie *right;
};