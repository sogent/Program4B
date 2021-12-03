//
// Created by Sarah Ogent on 11/21/21.
//

#include "Song.h"
using namespace std;
//default constructor
Song::Song():Media(){
    artist=" ";
    duration=0;
}

//constructor
Song::Song(char mediaType, string mediaTitle,int mediaRating, string mediaGenre,int mediaYearReleased, string songArtist,
           int songDuration)
        :Media(mediaType, mediaTitle, mediaRating,mediaGenre, mediaYearReleased){

    artist=songArtist;
    duration=songDuration;
}

//SETTERS
void Song::setSongArtist(string songArtist){
    artist=songArtist;
}
void Song::setSongDuration(int songDuration){
    duration=songDuration;
}

//GETTERS
string Song::getSongArtist(){
    return artist;
}
int Song::getSongDuration(){
    return duration;
}
