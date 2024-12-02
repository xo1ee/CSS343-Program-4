#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

using namespace std;

struct GenreCodes
{
    unordered_set<char> codes = {'F', 'D', 'C'};
};

class MovieFactory
{
private:
    GenreCodes genrecodes;         // valid Movie genre codes
    vector<Movie *> createdMovies; // stores all Movie objects created

public:
    MovieFactory();  // default constructor
    ~MovieFactory(); // default destructor deletes all Movie objects

    Movie *createMovie(const string); // creates movie with input data
};