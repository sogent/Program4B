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
    Book();

    //constructor
    Book(char mediaType, string mediaTitle,
         int mediaRating, string mediaGenre,
         int mediaYearReleased, string bookAuthor,
         int bookPages);


    //SETTERS
    /*
* Pre-condition:
* bookAuthor must be string
* Post-condition:
* data member 'author' is set to the value of the input argument
*/
    void setBookAuthor(string bookAuthor);

    /*
* Pre-condition:
* bookPages must be int
* Post-condition:
* data member 'pages' is set to the value of the input argument
*/
    void setBookPages(int bookPages);


    //GETTERS
    /*
* Pre-condition:
* data member 'author' must be set to string value
* Post-condition:
* value of data member 'author' is retrieved
*/
    string getBookAuthor();


    /*
* Pre-condition:
* data member 'pages' must be set to int value
* Post-condition:
* value of data member 'pages' is retrieved
*/
    int getBookPages();

};


#endif //PROGRAM4B_BOOK_H
