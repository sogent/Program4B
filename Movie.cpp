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

//SETTERS
void Movie::setMovieDirector(string movieDirector){
    director=movieDirector;
}
void Movie::setMovieDuration(int movieDuration){
    duration=movieDuration;
}
void Movie::setMovieStars(vector<string> &movieStars){
    stars=movieStars;
}

//GETTERS
string Movie::getMovieDirector(){
    return director;
}
int Movie::getMovieDuration(){
    return duration;
}

void Movie::getMovieStars(){
    for(int i=0;i<stars.size();++i){
        cout<<stars.at(i)<<endl;
    }
}

