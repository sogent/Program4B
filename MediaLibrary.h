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

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data from all media classes will be printed according to rating provided by user
*/
void printAboveRating(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data from 'Book' class will be printed, specifically the author of a book according to title of book provided
* by user
*/
void listBookAuthor(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data from all media classes will be printed, specifically the genre of all media types
*/
void printGenreList(vector <Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data from 'Song' class will be printed, specifically all the artists of the entire song library along with their
* song duration time
* by user
*/
void printSongArtistList(vector<Media*> &myMediaLibrary);

/*
* Pre-condition:
* is a sub-function of printMenuOptions, therefore printMenuOptions must be called first
* Post-condition:
* media data from 'Song' class will be printed, specifically the song(s) composed by an artist according to title of song
* provided by user
*/
void findSong(vector <Media*> &myMediaLibrary);


#endif //PROGRAM4B_MEDIALIBRARY_H
