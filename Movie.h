//
// Created by Sarah Ogent on 11/21/21.
//

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
    vector<string>stars;

public:
    //default constructor
    Movie();

    //constructor
    Movie(char mediaType, string mediaTitle,
          int mediaRating, string mediaGenre,
          int mediaYearReleased,string movieDirector,
          int movieDuration, vector<string>movieStars);

    //setters
    void setMovieDirector(string movieDirector);
    void setMovieDuration(int movieDuration);
    void setMovieStars(vector<string> movieStars);

    //getters
    string getMovieDirector();
    int getMovieDuration();

    virtual void printMedia(ostream &o);
};



#endif //PROGRAM4B_MOVIE_H
