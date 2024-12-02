#pragma once

#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

class MovieLib
{
private:
    int numMovies;

public:
    MovieLib();

    ~MovieLib();

    bool search(Movie &);

    int getNumMovies();
};