//
// Created by Sarah Ogent on 11/21/21.
//

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
    //constructors
    //getters and setters

    //default constructor
    Media();

    //constructor
    Media(char mediaType, string mediaTitle, int mediaRating, string mediaGenre, int mediaYearReleased);

    void setMediaType(char mediaType);
    void setMediaTitle(string mediaTitle);
    void setMediaRating(int mediaRating);
    void setMediaGenre(string mediaGenre);
    void setMediaYearReleased(int mediaYearReleased);

    char getMediaType();
    string getMediaTitle();
    int getMediaMediaRating();
    string getMediaGenre();
    int getMediaYearReleased();

    virtual void printMedia(ostream &o);

    virtual void printMediaAll();

};


#endif //PROGRAM4B_MEDIA_H
