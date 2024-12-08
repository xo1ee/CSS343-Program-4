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
#include "map"
#include "Movie.h"

class Classic : public Movie
{
private:
    map<string, int> actors;
    string majorActor;

public:
    Classic(); // default constructor

    // sets genre, stock, director, title, major actor,
    // releaseMonth and releaseYear to input values
    Classic(int, string, string, string, int, int);

    // sets releaseMonth, releaseYear and major actor
    // to input values
    Classic(string, int, int);

    ~Classic(); // destructor, empty

    void addStock(string); // adds to movie stock

    void removeStock(string); // removes from movie stock

    bool actorHasStock(const string) const; // returns true if an actor has stock

    void setActor(const string); // sets the majorActor as a different stored actor

    string getActor() const; // returns the majorActor

    // prints movie data in form: genre, stock, Release date, Major actor
    void printData() const override;

    // adds new actor to vector of actors for different versions of the same
    // movie
    void addActor(const string, const int);

    // returns true if a Movie version with the passed in actor string is
    // stored
    bool hasActor(const string) const;

    /// @brief compares Movie data to order
    /// @param reference to other Movie
    /// @return true if the other Movie data is greater, false if else
    bool operator<(const Movie &) const override;

    /// @brief compares if Movies are the same
    /// @param reference to other Movie
    /// @return true if the other Movie is the same, false if it is different
    bool operator==(const Movie &) const override;

    const int releaseMonth;
};