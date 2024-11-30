#pragma once
#include <iostream>
#include <string>

using namespace std;

class Movie
{
private:
    const char genre;

protected:
    int stock;
    const string director;
    const string title;
    const string releaseYear;

public:
    Movie(); // default attribute values: stock = '-', director = "Director" ,
             // title = "Title", releaseYear = "0000"

    virtual ~Movie();

    bool hasStock() const; // checks if movie has stock

    void addStock(); // adds to movie stock

    void removeStock(); // removes from movie stock

    virtual void printData() const = 0; // prints movie data: Genre, Stock, Director, Title, Release year

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
};