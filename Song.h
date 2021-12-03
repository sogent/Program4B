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


    //SETTERS
    /*
* Pre-condition:
* songArtist must be string
* Post-condition:
* data member 'artist' is set to the value of the input argument
*/
    void setSongArtist(string songArtist);

    /*
* Pre-condition:
* songDuration must be int
* Post-condition:
* data member 'duration' is set to the value of the input argument
*/
    void setSongDuration(int songDuration);


    //GETTERS
    /*
* Pre-condition:
* data member 'artist' must be set to string value
* Post-condition:
* value of data member 'artist' is retrieved
*/
    string getSongArtist();

    /*
* Pre-condition:
* data member 'duration' must be set to int value
* Post-condition:
* value of data member 'duration' is retrieved
*/
    int getSongDuration();


};


#endif //PROGRAM4B_SONG_H
