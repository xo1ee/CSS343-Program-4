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

    bool insertMovieHelper(Movie *, Movie *);

    Movie *searchHelper(Movie *, const Movie *searchFor) const;

    void printHelper(Movie *) const;

public:
    MovieLib();

    ~MovieLib();

    bool insert(string);

    bool isEmpty() const;

    Movie *search(string);

    int getNumMovies() const;

    void print() const;
};