//
// Created by Sarah Ogent on 11/21/21.
//


#include "MediaLibrary.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Media.h"
#include "Book.h"
#include "Movie.h"
#include "Song.h"

using namespace std;

void readData(istream &inFile, ostream &outFile, vector<Media*> &mediaLibrary) {
    cout << "\n\n\nLoading Data File...\n\n\n";

    //variables for base class
    string line, tempStr, testChar, title, genre;
    int rating, yearReleased;
    //variables for Book class
    string author;
    int pages;

    //variables for Movie class
    string director;
    int movieDuration;
    vector<string> stars;

    //variables for Song class
    string artist;
    int songDuration;


    vector<string> row;
    char userChoice = ' ';

    while (inFile.good()) {
        getline(inFile, line);
        testChar = line.substr(0, 1);

        if (testChar == "Q")
            break;

        //read data in string vector
        row.clear();
        stringstream inSS(line);
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }

        //parse data for Book type
        if (testChar == "B") {
            try {
                title = row[1];
                author=row[2];
                rating = stoi(row[3]);
                genre = row[4];
                pages=stoi(row[5]);
                yearReleased = stoi(row[6]);
            } catch (invalid_argument &error) {
                string msg = "\nERROR: " + line.substr(0, line.length() - 2);
                outFile << msg << "\nPrevious record has an " << error.what() << " error\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
            char type='B';
            Book *tempBook=new Book;
            tempBook->setMediaType(type);
            tempBook->setMediaTitle(title);
            tempBook->setMediaRating(rating);
            tempBook->setMediaGenre(genre);
            tempBook->setMediaYearReleased(yearReleased);
            tempBook->setBookAuthor(author);
            tempBook->setBookPages(pages);

            //bookLibrary.push_back(tempBook);
            mediaLibrary.push_back(tempBook);
            mediaCount[1]++;

        }



        //parse data for Movie type
        if (testChar == "M") {
            try {
                title = row[1];
                director=row[2];
                rating = stoi(row[3]);
                genre = row[4];
                movieDuration=stoi(row[5]);
                yearReleased = stoi(row[6]);
                for(int i=7;i<row.size();++i){
                    stars.push_back(row[i]);
                }

            } catch (invalid_argument &error) {
                string msg = "\nERROR: " + line.substr(0, line.length() - 2);
                outFile << msg << "\nPrevious record has an " << error.what() << " error\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
            char type='M';
            Movie *tempMovie=new Movie;
            tempMovie->setMediaType(type);
            tempMovie->setMediaTitle(title);
            tempMovie->setMediaRating(rating);
            tempMovie->setMediaGenre(genre);
            tempMovie->setMediaYearReleased(yearReleased);
            tempMovie->setMovieDirector(director);
            tempMovie->setMovieDuration(movieDuration);
            tempMovie->setMovieStars(stars);


            //movieLibrary.push_back(tempMovie);
            mediaLibrary.push_back(tempMovie);
            mediaCount[1]++;

        }



        //parse data for Song type
        if (testChar == "S") {
            try {
                title = row[1];
                artist=row[2];
                rating = stoi(row[3]);
                genre = row[4];
                songDuration=stoi(row[5]);
                yearReleased = stoi(row[6]);
            } catch (invalid_argument &error) {
                string msg = "\nERROR: " + line.substr(0, line.length() - 2);
                outFile << msg << "\nPrevious record has an " << error.what() << " error\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
            char type='S';
            Song* tempSong=new Song;
            tempSong->setMediaType(type);
            tempSong->setMediaTitle(title);
            tempSong->setMediaRating(rating);
            tempSong->setMediaGenre(genre);
            tempSong->setMediaYearReleased(yearReleased);
            tempSong->setSongArtist(artist);
            tempSong->setSongDuration(songDuration);


            //songLibrary.push_back(tempSong);
            mediaLibrary.push_back(tempSong);
            mediaCount[1]++;

        }

    }

}


void printBookList(vector<Media*> &myMediaLibrary){
    cout<<setw(37)<<right<<"YOUR BOOK LIST"<<endl;

}

void printMovieList(vector<Media*> &myMediaLibrary){
    cout<<setw(37)<<right<<"YOUR MOVIE LIST"<<endl;
/*
    cout<<"#"<<setw(18)<<"TITLE"<<setw(34)<<"YEAR"<<setw(10)<<"RATING"<<endl;
    for(int i=0;i<myMovieLibrary.size();++i){
        cout << setw(4)<<left<<i+1<<setw(45)<<left<< myMovieLibrary.at(i).getMediaTitle()<<setw(2)<<left;
        cout <<myMovieLibrary.at(i).getMediaYearReleased()<<setw(7)<<right;
        cout << myMovieLibrary.at(i).getMediaMediaRating();
        cout << endl;
    }
    cout<<endl;
    */
}

void printSongList(vector<Media*> &myMediaLibrary){
    cout<<setw(37)<<right<<"YOUR MUSIC LIST"<<endl;

}

void printList(vector<Media*> &myMediaLibrary){
    cout<<"#"<<setw(18)<<"TITLE"<<setw(34)<<"YEAR"<<setw(10)<<"RATING"<<endl;
    for(int i=0;i<myMediaLibrary.size();++i) {

        cout << setw(4)<<left<<i+1<<setw(45)<<left;
        myMediaLibrary.at(i)->printMediaAll();
    }
    cout<<endl;
}



void printMenuOptions() {
    //create vector of media data
    vector<Media*> myMediaLibrary;


    //open input and output files
    ifstream inFile;
    ofstream outFile;

    try{
        inFile.exceptions(ifstream::failbit);
        inFile.open("/Users/sogent/Downloads/mediaList.txt");
        outFile.exceptions(ifstream::failbit);
        outFile.open("mediaReport.txt");


    }catch(ifstream::failure& fail){
        cout<<"Could not open input file"<<endl;
        cout<<fail.what()<<endl;
        exit(1);
    }


    //read data into myMediaLibrary
    readData(inFile, outFile, myMediaLibrary);

    bool run = true;
    while (run) {
        try {
            cout << setw(18) << right << "MENU CHOICES" << endl;
            cout << "M - Print Movie List" << endl;
            cout << "B - Print Book List" << endl;
            cout << "S - Print Song List" << endl;
            cout << "F - Find the Movie the Star is in" << endl;
            cout << "G - Print Stars for a Given Movie" << endl;
            cout << "T - Print Media Counts" << endl;
            cout << "Q - Quit" << endl;
            cout << endl;
            cout << "Enter your choice: ";
            char userInput;
            char userInput1;

            cin >> userInput1;
            userInput = toupper(userInput1);

            cout << "You have entered: " << userInput << endl;
            cout << endl;
            cin.ignore();

            if (userInput == 'M') {
                //print movie list



            }else if(userInput=='B'){
                //print book list



            } else if (userInput == 'S') {
                //print song list


            }else if(userInput == 'A'){
                //print all media
                printList(myMediaLibrary);

            } else if (userInput == 'F') {
                //find the movie the star is in


            } else if(userInput=='G'){
                //print stars for a given movie

            } else if(userInput=='T') {
                //print media counts

            }else if (userInput == 'Q') {
                run = false;


            } else {
                throw runtime_error("Invalid input, please try again");
            }


        } catch (runtime_error &inputError) {
            cout << inputError.what() << endl;
            cout << endl;
        }
    }
}
