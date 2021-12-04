#include "Media.h"
#include <iostream>
#include <iomanip>
using namespace std;

//default constructor
Media::Media(){
    type=' ';
    title=" ";
    rating=0;
    genre=" ";
    yearReleased=0;
}

//constructor
Media::Media(char mediaType, string mediaTitle, int mediaRating, string mediaGenre, int mediaYearReleased){
    type=mediaType;
    title=mediaTitle;
    rating=mediaRating;
    genre=mediaGenre;
    yearReleased=mediaYearReleased;
}


//SETTERS
void Media::setMediaType(char mediaType){
    type=mediaType;
}
void Media::setMediaTitle(string mediaTitle){
    title=mediaTitle;
}
void Media::setMediaRating(int mediaRating){
    rating=mediaRating;
}
void Media::setMediaGenre(string mediaGenre){
    genre=mediaGenre;
}
void Media::setMediaYearReleased(int mediaYearReleased){
    yearReleased=mediaYearReleased;
}


//GETTERS
char Media::getMediaType(){
    return type;
}
string Media::getMediaTitle(){
    return title;
}
int Media::getMediaRating(){
    return rating;
}
string Media::getMediaGenre() {
    return genre;
}
int Media::getMediaYearReleased(){
    return yearReleased;
}

void Media::printMediaAll() {
    cout<< title<<setw(2)<<left;
    cout <<yearReleased<<setw(7)<<right;
    cout << rating;
}

