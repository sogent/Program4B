//
// Created by Sarah Ogent on 11/21/21.
//

#ifndef PROGRAM4B_MEDIALIBRARY_H
#define PROGRAM4B_MEDIALIBRARY_H
#include "Media.h"
#include <vector>
#include "Book.h"
#include "Movie.h"
#include "Song.h"
#pragma once

//vector of pointers

void readData(istream &inFile, ostream &outFile, vector<Media*> &mediaLibrary);

static int mediaCount[4] = {0, 0, 0, 0};

void printMenuOptions();

void printBookList(vector<Media*> &myMediaLibrary);

void printMovieList(vector<Media*> &myMediaLibrary);

void printSongList(vector<Media*> &myMediaLibrary);

void printList(vector<Media*> &myMediaLibrary);

void printTotals(vector<Media*> &myMediaLibrary);

void listMovieStars(vector<Media*> &myMediaLibrary);

void findMovie(vector<Media*> &myMediaLibrary);




#endif //PROGRAM4B_MEDIALIBRARY_H
