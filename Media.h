#ifndef PROGRAM4B_MEDIA_H
#define PROGRAM4B_MEDIA_H
#include <iostream>
#pragma once
using namespace std;

class Media{
protected:
    char type;
    string title;
    int rating;
    string genre;
    int yearReleased;

public:

    //default constructor
    Media();

    //constructor
    Media(char mediaType, string mediaTitle, int mediaRating, string mediaGenre, int mediaYearReleased);

    //SETTERS
    /*
* Pre-condition:
* mediaType must be char
* Post-condition:
* data member 'type' is set to the value of the input argument
*/
    void setMediaType(char mediaType);

    /*
* Pre-condition:
* mediaTitle must be string
* Post-condition:
* data member 'title' is set to the value of the input argument
*/
    void setMediaTitle(string mediaTitle);

    /*
* Pre-condition:
* mediaRating must be int
* Post-condition:
* data member 'rating' is set to the value of the input argument
*/
    void setMediaRating(int mediaRating);

    /*
* Pre-condition:
* mediaGenre must be string
* Post-condition:
* data member 'genre' is set to the value of the input argument
*/
    void setMediaGenre(string mediaGenre);

    /*
* Pre-condition:
* mediaYearReleased must be int
* Post-condition:
* data member 'yearReleased' is set to the value of the input argument
*/
    void setMediaYearReleased(int mediaYearReleased);


    //GETTERS
    /*
* Pre-condition:
* data member 'type' must be set to char value
* Post-condition:
* value of data member 'type' is retrieved
*/
    char getMediaType();

    /*
* Pre-condition:
* data member 'title' must be set to string value
* Post-condition:
* value of data member 'title' is retrieved
*/
    string getMediaTitle();

    /*
* Pre-condition:
* data member 'rating' must be set to int value
* Post-condition:
* value of data member 'rating' is retrieved
*/
    int getMediaMediaRating();

    /*
* Pre-condition:
* data member 'genre' must be set to string value
* Post-condition:
* value of data member 'genre' is retrieved
*/
    string getMediaGenre();

    /*
* Pre-condition:
* data member 'yearReleased' must be set to string value
* Post-condition:
* value of data member 'yearReleased' is retrieved
*/
    int getMediaYearReleased();


    /*
* Pre-condition:
* data members title, yearReleased and genre must be set to respective data type values
* Post-condition:
* values of data members title, yearReleased and genre are printed
*/
    virtual void printMediaAll();

};


#endif //PROGRAM4B_MEDIA_H
