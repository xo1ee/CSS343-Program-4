#include "MovieLib.h"

MovieLib::MovieLib() : numMovies(0)
{
    for (char code : genreCodes.codes)
        movies[code] = nullptr;
}

// ------------------------------------MovieLib::destructor------------------------------------
// Description
// destructor: deallocates Movie node memory stored, calls clearMovieLib()
// preconditions: Movie is correctly instatiated and all Movie objects will be deleted by
//                MovieFactory
// postconditions: does not deallocate any memory, this is done by MovieFactory
// --------------------------------------------------------------------------------------------
MovieLib::~MovieLib() { numMovies = 0; }

// ---------------------------------MovieLib::insertMovieHelper--------------------------------
// Description
// insertMovieHelper: helps insert a new movie into the MovieLib
// preconditions: *curr points to a node in the correct genre BST
// postconditions: returns true if a node was insertted successfully, false if not
//                 ie when the movie is already present or if a nullptr *curr is passed in
//                 adds to the stock and majorActors for classic movies, if adding a new
//                 version of the same title
// --------------------------------------------------------------------------------------------
bool MovieLib::insertMovieHelper(Movie *curr, Movie *newMovie)
{
    if (curr == nullptr)
        return false;

    if (*curr == *newMovie)
    {
        // cout << "\t ==" << endl;
        // cout << "CURR ";
        // curr->printData();
        // cout << "NEW ";
        // newMovie->printData();
        if (curr->genre == 'C' && newMovie->genre == 'C')
        {
            Classic *currClassic = static_cast<Classic *>(curr);
            Classic *newClassic = static_cast<Classic *>(newMovie);

            currClassic->addActor(newClassic->majorActor, newClassic->getStock());

            curr = currClassic;
            // cout << "COMBINED CLASSICS ";
            // curr->printData();
            return true;
        }
        return false;
    }
    else if (*newMovie < *curr)
    {
        // cout << "\t <" << endl;
        bool leftIsLeaf = !insertMovieHelper(curr->left, newMovie);
        if (leftIsLeaf)
        {
            curr->left = newMovie;
            numMovies++;
            return true;
        }
    }
    else
    {
        // cout << "\t >" << endl;
        bool rightIsLeaf = !insertMovieHelper(curr->right, newMovie);
        if (rightIsLeaf)
        {
            curr->right = newMovie;
            numMovies++;
            return true;
        }
    }
    return true;
}

// --------------------------------------MovieLib::insert--------------------------------------
// Description
// insert: insert a new movie into the MovieLib
// preconditions: input data string is formatted correctly with no mistakes
//                the genre BST may be empty
// postconditions: returns true if a node was inserted successfully, false if not
// --------------------------------------------------------------------------------------------
bool MovieLib::insert(string data)
{
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

// -----------------------------------MovieLib::searchHelper-----------------------------------
// Description
// searchHelper: traverses the tree of the input Movie *node and compares to Movie *searchFor
// preconditions: Movie *node is a node in one of the genre BSTs. assumes 2 input Movie
//                objects are of the same genre
// postconditions: returns the pointer to the movie if the movie being searched for is stored
//                 nullptr if not found
// --------------------------------------------------------------------------------------------
Movie *MovieLib::searchHelper(Movie *node, const Movie *searchFor) const
{
    if (node == nullptr) // if you reach a leaf, the node you're looking for doesn't exist
        return nullptr;

    cout << "IN SEARCH HELPER: ";
    node->printData();
    cout << "LOOKING FOR: ";
    searchFor->printData();

    if (*node == *searchFor)
    {
        if (node->genre == 'C' && searchFor->genre == 'C')
        {
            Classic *nodeClassic = dynamic_cast<Classic *>(node);
            const Classic *searchClassic = dynamic_cast<const Classic *>(searchFor);

            if (!nodeClassic->hasActor(searchClassic->majorActor))
                return nullptr;
        }
        return node;
    }

    if (*searchFor < *node)
        return searchHelper(node->left, searchFor);

    return searchHelper(node->right, searchFor);
}

// --------------------------------------MovieLib::search--------------------------------------
// Description
// search: returns the pointer to a movie in the MovieLib if it matches the input data string
// preconditions: assumes input data is valid
// postconditions: returns the pointer to the movie if it is stored
// --------------------------------------------------------------------------------------------
Movie *MovieLib::search(string data)
{
    char genre = data[0];
    data.erase(0, 2);

    Movie *searchFor = movieFac.createTemp(genre, data);
    if (searchFor == nullptr)
        return nullptr;

    cout << "Search for: ";
    searchFor->printData();

    Movie *found = searchHelper(movies[searchFor->genre], searchFor);

    if (found == nullptr)
        return nullptr;

    return found;
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
        int stockSpace = 0;
        if (genres.first == 'C')
            stockSpace = 4;

        cout << string(95, '-') << endl;

        cout << left << setw(6) << "Genre"
             << setw(8) << "Media"
             << setw(35) << "Title"
             << setw(20) << "Director";

        if (genres.first == 'C')
            cout << setw(8) << "Month";

        cout << setw(6) << "Year"
             << setw(4 + stockSpace) << "Stock"
             << endl;
        printHelper(genres.second);
        cout << endl;
    }
}