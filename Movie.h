#ifndef PROGRAM4B_MOVIE_H
#define PROGRAM4B_MOVIE_H

#include "Media.h"
#include <iostream>
#include <vector>
using namespace std;

class Movie: public Media {
private:
    string director;
    int duration;

public:
    vector<string>stars;

    //default constructor
    Movie();

    //constructor
    Movie(char mediaType, string mediaTitle,
          int mediaRating, string mediaGenre,
          int mediaYearReleased,string movieDirector,
          int movieDuration, vector<string>movieStars);

    //SETTERS
    /*
 * Pre-condition:
 * movieDirector must be string
 * Post-condition:
 * data member 'director' is set to the value of the input argument
 */
    void setMovieDirector(string movieDirector);

    /*
 * Pre-condition:
 * movieDuration must be int
 * Post-condition:
 * data member 'duration' is set to the value of the input argument
 */
    void setMovieDuration(int movieDuration);

    /*
 * Pre-condition:
 * movieStars must be vector of strings
 * Post-condition:
 * data member 'stars' is set to the value of the input argument
 */
    void setMovieStars(vector<string> &movieStars);


    //GETTERS
    /*
 * Pre-condition:
 * data member 'director' must be set to string value
 * Post-condition:
 * value of data member 'director' is retrieved
 */
    string getMovieDirector();

    /*
* Pre-condition:
* data member 'duration' must be set to int value
* Post-condition:
* value of data member 'duration' is retrieved
*/
    int getMovieDuration();

    /*
* Pre-condition:
* data member 'stars' must have vector elements set to string value
* Post-condition:
* value of data member 'stars' is retrieved
*/
    void getMovieStars();


};



#endif //PROGRAM4B_MOVIE_H
