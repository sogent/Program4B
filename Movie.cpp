//
// Created by Sarah Ogent on 11/21/21.
//

#include "Movie.h"
using namespace std;
#include <iostream>

//default constructor
Movie::Movie():Media(){
    director=" ";
    duration=0;
}

//constructor
Movie::Movie(char mediaType, string mediaTitle, int mediaRating, string mediaGenre, int mediaYearReleased,
             string movieDirector, int movieDuration, vector<string> movieStars){

    type=mediaType;
    title=mediaTitle;
    rating=mediaRating;
    genre=mediaGenre;
    yearReleased=mediaYearReleased;
    director=movieDirector;
    duration=movieDuration;
    stars=movieStars;

}

//setters
void Movie::setMovieDirector(string movieDirector){
    director=movieDirector;
}
void Movie::setMovieDuration(int movieDuration){
    duration=movieDuration;
}
void Movie::setMovieStars(vector<string> movieStars){
    stars=movieStars;
}

//getters
string Movie::getMovieDirector(){
    return director;
}
int Movie::getMovieDuration(){
    return duration;
}

void Movie::printMedia(ostream &o){
    o <<"Movie: "<<title<<endl;
}
