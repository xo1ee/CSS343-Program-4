#include "MovieLib.h"

MovieLib::MovieLib() : numMovies(0) //, movieFac(movieFac)
{
    for (char code : genreCodes.codes)
        movies[code] = nullptr;
}

// ------------------------------------MovieLib::destructor------------------------------------
// Description
// destructor: deallocates Movie node memory stored, calls clearMovieLib()
// preconditions: Movie is correctly instatiated and all Movie objects will be deleted by
//                MovieFactory
// postconditions: deallocates Movie node memory
// --------------------------------------------------------------------------------------------
MovieLib::~MovieLib()
{
    // for (auto &genres : movies)
    //     clearMovieLib(genres.second);
    numMovies = 0;
}

bool MovieLib::insertMovieHelper(Movie *curr, Movie *newMovie)
{
    cout << "\t ENTER INSERT HELPER" << endl;
    if (curr == nullptr)
        return false;

    cout << "CURRENT ";
    curr->printData();

    if (*curr == *newMovie)
    {
        cout << "\t ==" << endl;
        newMovie->printData();
        return false;
    }

    if (*newMovie < *curr)
    {
        cout << "\t <" << endl;
        if (!insertMovieHelper(curr->left, newMovie))
        {
            curr->left = newMovie;
            numMovies++;
        }
        insertMovieHelper(curr->left, newMovie);
    }
    else
    {
        cout << "\t >" << endl;
        if (!insertMovieHelper(curr->right, newMovie))
        {
            curr->right = newMovie;
            numMovies++;
        }
        insertMovieHelper(curr->right, newMovie);
    }
    return true;
}

bool MovieLib::insert(string data)
{
    // MovieFactory movieFac;
    Movie *newMovie = movieFac.createMovie(data);
    if (newMovie == nullptr)
        return false;

    if (movies[newMovie->genre] == nullptr)
    {
        movies[newMovie->genre] = newMovie;
        return movies[newMovie->genre] != nullptr; // head may be nullptr if the data was invalid
    }

    return insertMovieHelper(movies[newMovie->genre], newMovie);
}

// -------------------------------------MovieLib::isEmpty-------------------------------------
// Description
// isEmpty: returns true or false if the MovieLib is empty
// preconditions: Movie is correctly instatiated, numMovies is accurate
// postconditions: returns true if the MovieLib does not contain movies, false if else
// --------------------------------------------------------------------------------------------
bool MovieLib::isEmpty() const { return numMovies == 0; }

bool MovieLib::search(const Movie &) const
{
    return true;
}

// -----------------------------------MovieLib::getNumMovies-----------------------------------
// Description
// getNumMovies: returns number of movies stored
// preconditions: Movie is correctly instatiated, numMovies is accurate
// postconditions: returns number of movies stored
// --------------------------------------------------------------------------------------------
int MovieLib::getNumMovies() const { return numMovies; }

// ------------------------------------MovieLib::printHelper-----------------------------------
// Description
// printHelper: helps print movie library contents
// preconditions: Movie is correctly instatiated and has a printData() function that prints the
//                movie data and pointers to a left and right node
// postconditions: makes no changes to the library
// --------------------------------------------------------------------------------------------
void MovieLib::printHelper(Movie *node) const
{
    if (node == nullptr)
        return;

    printHelper(node->left);
    node->printData();
    printHelper(node->right);
}

// --------------------------------------MovieLib::print---------------------------------------
// Description
// print: prints movie library contents
// preconditions: Movie is correctly instatiated
// postconditions: makes no changes to the library
// --------------------------------------------------------------------------------------------
void MovieLib::print() const
{
    for (auto &genres : movies)
    {
        cout << "-------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << left << setw(6) << "Genre"
             << setw(8) << "Media"
             << setw(35) << "Title"
             << setw(20) << "Director";

        // if (genres.first == 'C')
        // cout << setw(6) << "Month";

        cout << setw(6) << "Year"
             << setw(4) << "Stock"
             << endl;
        printHelper(genres.second);
        cout << endl;
    }
}