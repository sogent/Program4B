//
// Created by Sarah Ogent on 11/21/21.
//

#ifndef PROGRAM4B_BOOK_H
#define PROGRAM4B_BOOK_H
#pragma once
#include "Media.h"
#include <iostream>
using namespace std;


class Book: public Media {
private:
    string author;
    int pages;
public:
    //default constructor
    //constructor
    //setters and getters
    Book();

    Book(char mediaType, string mediaTitle,
         int mediaRating, string mediaGenre,
         int mediaYearReleased, string bookAuthor,
         int bookPages);


    void setBookAuthor(string bookAuthor);

    void setBookPages(int bookPages);

    string getBookAuthor();

    int getBookPages();

    virtual void printMedia(ostream &o);

    void printBookAll();




};


#endif //PROGRAM4B_BOOK_H
