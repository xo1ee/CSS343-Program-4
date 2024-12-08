// ---------------------------------------------------- Classic.h -----------------------------------------------------
// Phohanh Tran CSS343 Section A
// Creation Date: 11/29/2024
// Date of Last Modification: 12/1/2024
// --------------------------------------------------------------------------------------------------------------------
// Purpose - defines implementation for the functions and attributes used by the Movie parent class
// --------------------------------------------------------------------------------------------------------------------
// No special specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#include "Classic.h"

// --------------------------------------Classic::Classic--------------------------------------
// Description
// default constructor: sets Classic values as default
// preconditions: Movie class and parameterized constructor is defined correctly
// postconditions: constructs a Drama object with all default values and a Movie parent
//                 with genre 'C'
// --------------------------------------------------------------------------------------------
Classic::Classic() : Movie('C'), actors(), majorActor(""), releaseMonth(0) {}

// ------------------Classic::Classic(int, string, string, string, int, int)-------------------
// Description
// paramaterized constructor: sets Classic genre, stock, director, title, major actor,
//                            releaseMonth and releaseYear to input values
// preconditions: inputs are different than Movie parent class and other Movie sub classes
//                input are valid, Movie parameterized constructor is defined correctly
// postconditions: constructs a Classic object and Movie parent with passed in values
// --------------------------------------------------------------------------------------------
Classic::Classic(int stock, string director, string title,
                 string majorActor, int releaseMonth, int releaseYear) : Movie('C', stock, director,
                                                                               title, releaseYear),
                                                                         majorActor(majorActor),
                                                                         releaseMonth(releaseMonth)
{
    actors[majorActor] = stock;
}

// ------------------Classic::Classic(int, string, string, string, int, int)-------------------
// Description
// paramaterized constructor: sets major actor,
//                            releaseMonth and releaseYear to input values
// preconditions: inputs are different than Movie parent class and other Movie sub classes
//                input are valid, Movie parameterized constructor is defined correctly
// postconditions: constructs a Classic object and Movie parent with passed in values
//                 used to create a temporary Movie for search comparisons
// --------------------------------------------------------------------------------------------
Classic::Classic(string majorActor,
                 int releaseMonth, int releaseYear) : Movie('C', 0, "",
                                                            "", releaseYear),
                                                      majorActor(majorActor),
                                                      releaseMonth(releaseMonth)
{
    actors[majorActor] = 0;
}

// --------------------------------------Classic::~Classic--------------------------------------
// Description
// destructor: destructs Classic object
// preconditions: Classic subclass does not initialize memory
// postconditions: destructs Classic object
// --------------------------------------------------------------------------------------------
Classic::~Classic() {}

// ---------------------------------------Classic::addStock--------------------------------------
// Description
// addStock: adds to the movie stock
// preconditions: Classic is correctly instatiated
// postconditions: adds to movie stock, should be called when Return::doReturn is called
// --------------------------------------------------------------------------------------------
void Classic::addStock(string actor)
{
    if (actors.find(actor) == actors.end())
        throw invalid_argument(actor + " invalid actor.");
    actors[actor]++;
    stock++;
}

// --------------------------------------Classic::removeStock-------------------------------------
// Description
// removeStock: removes from the movie stock
// preconditions: Classic is correctly instatiated and does not have empty stock
// postconditions: removes from movie stock, should be called when Return::doBorrow is called
// ---------------------------------------------------------------------------------------------
void Classic::removeStock(string actor)
{
    if (actors.find(actor) == actors.end())
        throw invalid_argument(actor + " invalid actor");
    if (stock < 0 || actors[actor] < 0)
        throw invalid_argument("Movie stock is negative");

    if (stock == 0 || actors[actor] < 0)
        throw invalid_argument("Movie is not in stock");

    actors[actor]--;
    stock--;
}

// --------------------------------------Classic::actorHasStock-------------------------------------
// Description
// actorHasStock: returns true if the version of the movie with the input actor has stock
// preconditions: Classic is correctly instatiated and may have empty stock
// postconditions: returns true if the stock for an actor is more than 0, used by Borrow()
//                 throws an error for invalid actors
// ---------------------------------------------------------------------------------------------
bool Classic::actorHasStock(const string actor) const
{
    auto it = actors.find(actor);
    if (it != actors.end())
        return it->second > 0;

    throw invalid_argument(actor + " invalid actor");
    return false;
}
// --------------------------------------Classic::setActor-------------------------------------
// Description
// setActor: sets the majorActor to a different actor that is stored
// preconditions: Classic is correctly instatiated and may have empty stock
// postconditions: sets the majorActor to a different actor that is stored, but not if it
//                 not already stored
// ---------------------------------------------------------------------------------------------
void Classic::setActor(const string actor)
{
    auto it = actors.find(actor);
    if (it != actors.end())
    {
        majorActor = actor;
        return;
    }

    throw invalid_argument(actor + " invalid actor");
}

// --------------------------------------Classic::getActor-------------------------------------
// Description
// getActor: returns the majorActor
// preconditions: Classic is correctly instatiated
// postconditions: returns the majorActor
// ---------------------------------------------------------------------------------------------
string Classic::getActor() const { return majorActor; }

// --------------------------------------Classic::printData--------------------------------------
// Description
// printData: prints Classic Movie data in form: genre, stock, Release date, Major actor, Title,
//            and director
// preconditions: Classic is correctly instatiated
// postconditions: makes no changes to Classic
// ---------------------------------------------------------------------------------------------
void Classic::printData() const
{
    cout << setw(6) << genre
         << setw(8) << mediaType
         << setw(35) << title
         << setw(20) << director
         << setw(8) << releaseMonth
         << setw(8) << releaseYear
         << setw(4) << stock << endl; // Figure out how to do a combined stock for this

    for (const auto &actor : actors)
    {
        int spacing = 0;
        if (actor.first.size() < 17)
            spacing = 17 - actor.first.size();
        if (actor.first.size() > 17)
            spacing = actor.first.size() - 17;

        cout << setw(53 + spacing) << ""
             << actor.first << " "
             << string(15, '-') << " "
             << actor.second
             << endl
             << endl;
    }
}

// --------------------------------------Classic::addActor--------------------------------------
// Description
// addActor: adds an actor and stock count for the version of the current movie with
//           each actor
// preconditions: Classic is correctly instatiated, Classic data may have different
//                capitalizations
// postconditions: adds to the map of actors
// ---------------------------------------------------------------------------------------------
void Classic::addActor(const string newActor, const int newStock)
{
    actors[newActor] = newStock;
    stock += newStock;
}

// --------------------------------------Classic::hasActor--------------------------------------
// Description
// hasActor: returns true if a version of the current movie has the input otherActor
// preconditions: Classic is correctly instatiated, Classic data may have different
//                capitalizations
// postconditions: returns true if the passed in actor is stored
// ---------------------------------------------------------------------------------------------
bool Classic::hasActor(const string otherActor) const
{
    for (const auto &actor : actors)
        if (actor.first == otherActor)
            return true;
    return false;
}

// --------------------------------------Classic::operator<--------------------------------------
// Description
// operator<: compares the ordering data of the input and current Classic by release date, then
//            alphabetical value of major Actor
// preconditions: Classic is correctly instatiated, Classic data may have different
//                capitalizations
// postconditions: returns true if the input Classic is greater, makes no changes to either
//                 Classic
// ---------------------------------------------------------------------------------------------
bool Classic::operator<(const Movie &other) const
{
    const Classic *otherC = dynamic_cast<const Classic *>(&other);

    if (this->releaseYear < otherC->releaseYear)
        return true;

    if (this->releaseYear == otherC->releaseYear &&
        this->releaseMonth < otherC->releaseMonth)
        return true;

    if (this->releaseYear == otherC->releaseYear &&
        this->releaseMonth == otherC->releaseMonth &&
        this->majorActor < otherC->majorActor)
        return true;
    return false;
}

// --------------------------------------Classic::operator==-------------------------------------
// Description
// operator==: checks the input movie has the exact same genre, director, title and releaseYear
//            as the current Classic
// preconditions: Both Classic objects are correctly instantiated, Classic data may have different
//                capitalizations
// postconditions: returns true if the input Classic is the same, makes no changes to either
//                 Classic. compares current Movie with a temporary comparison Movie
// ---------------------------------------------------------------------------------------------
bool Classic::operator==(const Movie &other) const
{
    const Classic *otherC = dynamic_cast<const Classic *>(&other);

    return (this->releaseMonth == otherC->releaseMonth) &&
           (this->releaseYear == otherC->releaseYear);
}