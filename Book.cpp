//
// Created by Sarah Ogent on 11/21/21.
//

#include "Book.h"

//default constructor
Book::Book(){
    author= " ";
    pages=0;
}

//constructor
Book::Book(char mediaType, string mediaTitle,
           int mediaRating, string mediaGenre,
           int mediaYearReleased, string bookAuthor, int bookPages){
    type=mediaType;
    title=mediaTitle;
    rating=mediaRating;
    genre=mediaGenre;
    yearReleased=mediaYearReleased;
    author=bookAuthor;
    pages=bookPages;
}

//setters
void Book::setBookAuthor(string bookAuthor){
    author=bookAuthor;
}
void Book::setBookPages(int bookPages){
    pages=bookPages;
}

//getters
string Book::getBookAuthor(){
    return author;
}
int Book::getBookPages(){
    return pages;
}

void Book::printMedia(ostream &o){
    o <<"Book: "<<title<< ": "<< author <<": "<<endl;
}

