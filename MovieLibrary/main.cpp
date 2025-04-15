#include <iostream>
#include "Movies.h"

// Function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

/******************************************************************
 * helper function 
 * increment_watched expects a reference to a Movies object 
 * and the name of the movie to increment the watched count
 *
 * If the watched count was incremented successfully it
*  displays a success message
*  otherwise the watched count could not be incremented
*  because the name of the movie was not found
 * ***************************************************************/

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}

/******************************************************************
* helper function
*  add_movie expects a reference to a Movies object 
 * and the name of the movie, the rating and the watched count
 *
 * If the movie was successfully added to the movies object it
*  displays a success message
*  otherwise the movie was not added 
*  because the name of the movie was already in movies
 * ***************************************************************/
void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}


void display_menu(){

    printf("================================\n");
    printf("        Movie Manager           \n");
    printf("================================\n");
    printf("A - Add a movie\n");
    printf("I - Increment watch count\n");
    printf("D - Display all movies\n");
    printf("Q - Quit\n");
    printf("================================\n");
    printf("Enter your choice: ");

}

int main() {

    Movies my_movies;

    char choice;
    do {

        display_menu();
        std::cin >> choice;
        choice = std::toupper(choice);

        switch(choice) {
            case 'A':
            {
                std::string movie_name;
                std::string rating;
                int watch_count = 0;
                printf("Enter movie name: ");
                std::cin >> movie_name;
                printf("Enter the rating: ");
                std::cin >> rating;
                printf("Enter the no.of.times watched: "); 
                std::cin >> watch_count;
                add_movie(my_movies,movie_name,rating,watch_count);
                break;
            }
            case 'I':
                {
                    std::string movie_name;
                    printf("Enter movie name: ");
                    std::cin >> movie_name;
                    increment_watched(my_movies,movie_name);
                    break;
                }
            case 'D':
                my_movies.display();
                break;
            case 'Q':
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }

    } while(choice != 'Q');

	return 0;
}

/* Try with some examples like:

    Add these movies 

    "Big", "PG-13",2
    "Star Wars", "PG",5
    "Cinderella", "PG",7


    Increment these movies

    "Big" , "Ice Age"
    Try incrementing "XXX" which does not exist in list

*/
 


