#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;
public:
    Movies();             // Constructor
    ~Movies();          // Destructor
    /*************************************************************************
    add_movie expects the name of the move, rating and watched count

    *********************************************************************/
    bool add_movie(std::string name, std::string rating, int watched);
    
    /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    *********************************************************************/
    bool increment_watched(std::string name);
    
    /*************************************************************************
    display all the movie objects in the movies vector.

    *********************************************************************/
    void display() const;
};

#endif // _MOVIES_H_