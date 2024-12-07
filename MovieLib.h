#pragma once
#include <unordered_map>
#include "Movies/MovieFactory.h"
#include "Movies/Movie.h"
#include "Movies/Comedy.h"
#include "Movies/Drama.h"
#include "Movies/Classic.h"

using namespace std;

class MovieLib
{
private:
    MovieFactory movieFac;
    GenreCodes genreCodes;
    int numMovies;
    unordered_map<char, Movie *> movies;

public:
    MovieLib();

    ~MovieLib();

    bool insertMovieHelper(Movie *, Movie *);

    bool insert(string);

    bool isEmpty() const;

    bool search(const Movie &) const;

    int getNumMovies() const;

    void printHelper(Movie *) const;

    void print() const;
};