#include "Book.h"
#include <vector>

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

//SETTERS
void Book::setBookAuthor(string bookAuthor){
    author=bookAuthor;
}
void Book::setBookPages(int bookPages){
    pages=bookPages;
}

//GETTERS
string Book::getBookAuthor(){
    return author;
}
int Book::getBookPages(){
    return pages;
}