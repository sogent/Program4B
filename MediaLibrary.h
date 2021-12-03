#ifndef PROGRAM4B_MEDIALIBRARY_H
#define PROGRAM4B_MEDIALIBRARY_H
#include "Media.h"
#include <vector>
#include "Book.h"
#include "Movie.h"
#include "Song.h"
#pragma once

static int mediaCount[4] = {0, 0, 0, 0};

/*
* Pre-condition:
* file being read must be csv format
* Post-condition:
* data from file is traversed then placed into a vector of class pointers
*/
void readData(istream &inFile, ostream &outFile, vector<Media*> &mediaLibrary);


/*
* Pre-condition:
* 'readData' function must be working properly
* Post-condition:
* certain data of Media classes is output depending on which menu option user chooses
*/
void printMenuOptions();

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data, specifically of 'Book' class is output
*/
void printBookList(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data, specifically of 'Movie' class is output
*/
void printMovieList(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data, specifically of 'Song' class is output
*/
void printSongList(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* all media data from Book, Song and Movie classes are output
*/
void printList(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* readData must first be called, which inputs data into myMediaLibrary vector
* Post-condition:
* totals of data objects from classes Movie, Song and Book are output
* along with overall total of media objects
*/
void printTotals(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data from class 'Movie,' specifically particular stars of a movie are output
*/
void listMovieStars(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data from class 'Movie,' specifically movies in which a particular star is cast is/are output
*/
void findMovie(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* argument provided must be string
* Post-condition:
* original string argument is returned, stripped of trailing spaces
*/
///NOTE:Cited from Peteris on StackOverflow
string remove_spaces(const string& s);




#endif //PROGRAM4B_MEDIALIBRARY_H
