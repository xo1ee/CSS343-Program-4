#include "MovieFactory.h"

// ----------------------------------MovieFactory::MovieFactory---------------------------------
// Description
// constructor: empty
// preconditions: MovieFactory has attributes: genreCodes and createdMovies
//                no need to explicitly iniitalize either
// postconditions: initializes genreCodes object and empty createdMovies vector
// ---------------------------------------------------------------------------------------------
MovieFactory::MovieFactory() {}

// ---------------------------------MovieFactory::~MovieFactory---------------------------------
// Description
// destructor: deletes all Movie pointers created in the MovieFactory
// preconditions: assumes all Movie objects are created using Movie Factory
// postconditions: deletes the memory used to store all movies
// ---------------------------------------------------------------------------------------------
MovieFactory::~MovieFactory()
{
    deleteTemp();
    for (Movie *movie : createdMovies)
        delete movie;
}

// ----------------------------------MovieFactory::createMovie----------------------------------
// Description
// createMovie: prints Classic Movie data in form: genre, stock, Release date, Major actor, Title,
//            and director
// preconditions: takes string containing Movie data, assumes data is correctly formatted,
//                but the movie genre code may not be valid
// postconditions: creates a Movie based on the input string of data, stores it in the
//                 createdMovies vector, then returns the pointer to the movie or nullptr
//                 if the input data was not valid
// ---------------------------------------------------------------------------------------------
Movie *MovieFactory::createMovie(const string line)
{
    stringstream ss(line);
    char genre;
    char comma; // char used to catch comma "," characters when parsing input
    int stock;
    string director;
    string directorName;
    string title;
    int releaseYear;

    ss >> genre;

    if (genreCodes.codes.count(toupper(genre)) == 0)
        return nullptr;

    ss >> comma >> stock >> comma;

    getline(ss, director, ',');
    director.erase(0, 1);

    getline(ss, title, ',');
    title.erase(0, 1);

    // cout << "\tOutput: [" << genre << "] [" << stock << "] [" // print output for debug, formatted
    //      << director << "] [" << title << "] " << endl;       // to see unintended whitespace

    Movie *newMovie = nullptr;

    switch (genre)
    {
    case 'F':
    {
        ss >> releaseYear;
        newMovie = new Comedy(stock, director, title, releaseYear);
        break;
    }
    case 'D':
    {
        ss >> releaseYear;
        newMovie = new Drama(stock, director, title, releaseYear);
        break;
    }
    case 'C':
    {
        string majorActor;
        ss >> majorActor;

        string temp;
        ss >> temp;

        while (!isdigit(temp[0]))
        {
            majorActor += " " + temp;
            ss >> temp;
        }

        int releaseMonth = stoi(temp);
        ss >> releaseYear;

        newMovie = new Classic(stock, director, title, majorActor, releaseMonth, releaseYear);
        break;
    }
    }

    if (newMovie != nullptr)
        createdMovies.push_back(newMovie);

    return newMovie;
}

// -----------------------------------MovieFactory::createTemp----------------------------------
// Description
// createTemp: prints Classic Movie data in form: genre, stock, Release date, Major actor, Title,
//            and director
// preconditions: takes string containing Movie data, assumes data is correctly formatted,
//                but the movie genre code may not be valid
// postconditions: creates a Movie based on the input string of data, stores it in the
//                 createdMovies vector, then returns the pointer to the movie or nullptr
//                 if the input data was not valid
// ---------------------------------------------------------------------------------------------
Movie *MovieFactory::createTemp(const char genre, const string data)
{
    stringstream ss(data);
    Movie *newMovie = nullptr;

    switch (genre)
    {
    case ('F'):
    {
        string title;
        int releaseYear;
        getline(ss, title, ',');
        ss >> releaseYear;

        // cout << "CREATED COMEDY ";
        // cout << "[" << title << "] [" << releaseYear << "]" << endl;
        newMovie = new Comedy(title, releaseYear);
        break;
    }
    case ('D'):
    {
        string director, title;
        getline(ss, director, ',');
        getline(ss, title, ',');
        title.erase(0, 1);

        // cout << "CREATED DRAMA ";
        // cout << "[" << director << "] [" << title << "]" << endl;
        newMovie = new Drama(director, title);
        break;
    }
    case ('C'):
    {
        int releaseMonth, releaseYear;
        string majorActor = "";
        ss >> releaseMonth >> releaseYear;

        string temp;
        ss >> temp;
        majorActor += temp;

        while (ss >> temp)
            majorActor += " " + temp;

        // cout << "CREATED CLASSIC ";
        // cout << "\t [" << releaseMonth << "] [" << releaseYear << "] [" << majorActor << "]" << endl;
        newMovie = new Classic(majorActor, releaseMonth, releaseYear);
        break;
    }
    };

    if (newMovie == nullptr)
        return nullptr;

    tempMovies.push_back(newMovie);
    return newMovie;
}

// ----------------------------------MovieFactory::createMovie----------------------------------
// Description
// createMovie: prints Classic Movie data in form: genre, stock, Release date, Major actor, Title,
//            and director
// preconditions: tempMovies may be empty
// postconditions: creates a Movie based on the input string of data, stores it in the
//                 createdMovies vector, then returns the pointer to the movie or nullptr
//                 if the input data was not valid
// ---------------------------------------------------------------------------------------------
void MovieFactory::deleteTemp()
{
    if (tempMovies.empty())
        return;
    for (Movie *movie : tempMovies)
        delete movie;
}

void MovieFactory::displayMovies() const
{
    for (Movie *movie : createdMovies)
        movie->printData();
}