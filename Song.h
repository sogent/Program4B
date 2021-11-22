//
// Created by Sarah Ogent on 11/21/21.
//

#ifndef PROGRAM4B_SONG_H
#define PROGRAM4B_SONG_H

#include "Media.h"


class Song: public Media{
private:
    string artist;
    int duration;

public:
    //default constructor
    Song();

    //constructor
    Song(char mediaType, string mediaTitle,
         int mediaRating, string mediaGenre,
         int mediaYearReleased, string songArtist,
         int songDuration);

    //setters
    void setSongArtist(string songArtist);
    void setSongDuration(int songDuration);

    //getters
    string getSongArtist();
    int getSongDuration();

    virtual void printMedia(ostream &o);
};


#endif //PROGRAM4B_SONG_H
