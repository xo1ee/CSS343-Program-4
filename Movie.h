#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
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

    string toLowerString(const string &) const; // lower-cases a string

    bool hasStock() const; // checks if movie has stock

    void addStock(); // adds to movie stock

    void removeStock(); // removes from movie stock

    virtual void printData() const; // prints movie data: Genre, Stock, Director, Title, Release year

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

    const char genre; // set to '-'
    const string director;
    const string title;
    const string releaseYear;
};