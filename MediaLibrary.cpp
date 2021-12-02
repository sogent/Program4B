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
                //exit(1);
                continue;
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


            mediaLibrary.push_back(tempBook);
            mediaCount[1]++;
            mediaCount[3]++;
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
                //exit(1);
                continue;
            }
            char type='M';
            Movie *tempMovie= new Movie;
            tempMovie->setMediaType(type);
            tempMovie->setMediaTitle(title);
            tempMovie->setMediaRating(rating);
            tempMovie->setMediaGenre(genre);
            tempMovie->setMediaYearReleased(yearReleased);
            tempMovie->setMovieDirector(director);
            tempMovie->setMovieDuration(movieDuration);
            tempMovie->setMovieStars(stars);

            cout<<"****"<<endl;
            for(int j=0;j<tempMovie->stars.size();++j){
                //cout<<tempMovie->stars.at(j)<<endl;

            }

            stars.clear();

            mediaLibrary.push_back(tempMovie);



            for(int i=0;i<mediaLibrary.size();++i){
                //if(myMediaLibrary[i]->getMediaTitle()==userInput) {
                if(mediaLibrary[i]->getMediaType()=='M'){

                   // cout << dynamic_cast<Movie*>(mediaLibrary.at(i))->getMovieStars().at(0) << endl;

                }
            }
            //}
            cout<<endl;


            mediaCount[0]++;
            mediaCount[3]++;
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
                //exit(1);
                continue;
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


            mediaLibrary.push_back(tempSong);
            mediaCount[2]++;
            mediaCount[3]++;
        }
    }

}


void printBookList(vector<Media*> &myMediaLibrary){

    cout<<setw(37)<<right<<"YOUR BOOK LIST"<<endl;
    cout<<"#"<<setw(18)<<"TITLE"<<setw(34)<<"YEAR"<<setw(10)<<"RATING"<<endl;

    for(int i=0;i<myMediaLibrary.size();++i) {
        if(myMediaLibrary[i]->getMediaType()=='B'){
            cout << setw(6)<<left<<i+1<<setw(43)<<left;
            cout<<myMediaLibrary[i]->getMediaTitle();
            cout<<setw(10)<<left<<myMediaLibrary[i]->getMediaYearReleased();
            cout<<setw(10)<<left<<myMediaLibrary[i]->getMediaMediaRating();

            //cout<<dynamic_cast<Book*>(myMediaLibrary.at(i))->getBookAuthor()<<endl;
            //cout<<dynamic_cast<Book*>(myMediaLibrary.at(i))->getBookPages()<<endl;
            cout<<endl;
        }

    }
    cout<<endl;

}

void printMovieList(vector<Media*> &myMediaLibrary){
    cout<<setw(37)<<right<<"YOUR MOVIE LIST"<<endl;
    cout<<"#"<<setw(18)<<"TITLE"<<setw(34)<<"YEAR"<<setw(10)<<"RATING"<<endl;

    for(int i=0;i<myMediaLibrary.size();++i) {
        if(myMediaLibrary[i]->getMediaType()=='M'){
            cout << setw(6)<<left<<i+1<<setw(43)<<left;
            cout<<myMediaLibrary[i]->getMediaTitle();
            cout<<setw(10)<<left<<myMediaLibrary[i]->getMediaYearReleased();
            cout<<setw(10)<<left<<myMediaLibrary[i]->getMediaMediaRating();

            //cout<<dynamic_cast<Book*>(myMediaLibrary.at(i))->getBookAuthor()<<endl;
            //cout<<dynamic_cast<Book*>(myMediaLibrary.at(i))->getBookPages()<<endl;
            cout<<endl;
        }

    }
    cout<<endl;
}

void printSongList(vector<Media*> &myMediaLibrary){
    cout<<setw(37)<<right<<"YOUR SONG LIST"<<endl;
    cout<<"#"<<setw(18)<<"TITLE"<<setw(34)<<"YEAR"<<setw(10)<<"RATING"<<endl;

    for(int i=0;i<myMediaLibrary.size();++i) {
        if(myMediaLibrary[i]->getMediaType()=='S'){
            cout << setw(6)<<left<<i+1<<setw(43)<<left;
            cout<<myMediaLibrary[i]->getMediaTitle();
            cout<<setw(10)<<left<<myMediaLibrary[i]->getMediaYearReleased();
            cout<<setw(10)<<left<<myMediaLibrary[i]->getMediaMediaRating();

            //cout<<dynamic_cast<Book*>(myMediaLibrary.at(i))->getBookAuthor()<<endl;
            //cout<<dynamic_cast<Book*>(myMediaLibrary.at(i))->getBookPages()<<endl;
            cout<<endl;
        }

    }
    cout<<endl;


}

void printList(vector<Media*> &myMediaLibrary){
    cout<<"#"<<setw(18)<<"TITLE"<<setw(34)<<"YEAR"<<setw(10)<<"RATING"<<endl;

    for(int i=0;i<myMediaLibrary.size();++i) {
        cout << setw(4)<<left<<i+1<<setw(45)<<left;
        myMediaLibrary.at(i)->printMediaAll();
        cout<<endl;
    }
    cout<<endl;
}


void printTotals(vector<Media*> &myMediaLibrary){
    cout<<"YOUR MEDIA LIBRARY"<<endl;
    cout<<setw(5)<<left<<"#"<<"TYPE"<<endl;

        cout<<setw(5)<<left<<mediaCount[0]<<"Movies"<<endl;
        cout<<setw(5)<<left<<mediaCount[1]<<"Books"<<endl;
        cout<<setw(5)<<left<<mediaCount[2]<<"Songs"<<endl;
        cout<<setw(5)<<left<<mediaCount[3]<<"Items"<<endl;
        cout<<endl;
}


void listMovieStars(vector<Media*> &myMediaLibrary){
    string userInput;
    cout<<"Enter the Movie's title: ";
    try {
        getline(cin, userInput);

        vector<int> foundIndex;
        int matchCount=0;
        int movieListSize=0;
        for(int i=0;i<myMediaLibrary.size();++i){
            if(myMediaLibrary[i]->getMediaType()=='M'){
                movieListSize+=1;
                int found=userInput.find(myMediaLibrary[i]->getMediaTitle());
                if(found==-1){
                    matchCount+=1;
                }
                //if the string is not found, then it will return a -1
                //since each movie is being traversed, it will
                //output a total equivalent to the number of movies

                foundIndex.push_back(found);
            }
        }

        if(matchCount==movieListSize){
            throw runtime_error("is not found in your movie library");
        }

        cout<<endl;
        cout << "THE STARS OF THE MOVIE \"" << userInput << "\" ARE:" << endl;
        cout << "{";
        cout << setfill('=') << setw(50);
        cout << "}" << endl;
        cout << setfill(' ');

        for (int i = 0; i < myMediaLibrary.size(); ++i) {
            if (myMediaLibrary[i]->getMediaTitle() == userInput) {
                if (myMediaLibrary[i]->getMediaType() == 'M') {

                    dynamic_cast<Movie *>(myMediaLibrary.at(i))->getMovieStars();
                }
            }
        }

        cout << "{";
        cout << setfill('=') << setw(50);
        cout << "}" << endl;
        cout << setfill(' ');
        cout << endl;

    }catch(runtime_error &inputError){
        cout<<endl;
        cout<<"Sorry, but the movie: \""<<userInput<<"\" "<<inputError.what()<<endl;
        cout<<endl;
    }


}


void findMovie(vector<Media*> &myMediaLibrary){
    string userInput;
    cout<<"Enter the Star's name: ";
    try{
        getline(cin, userInput);

        int matchCount=0;
        int movieListCount=0;
        for(int i=0;i<myMediaLibrary.size();++i){
            if(myMediaLibrary[i]->getMediaType()=='M'){
                movieListCount+=1;
                int found=userInput.find(dynamic_cast<Movie*>(myMediaLibrary.at(i))->stars.at(0));

                if(found==-1){
                    matchCount+=1;
                }

                //if the string is not found, then it will return a -1
                //since each movie is being traversed, it will
                //output a total equivalent to the number of movies

            }
        }

        if(matchCount>=movieListCount){
            throw runtime_error("is not found in any movies in your movie library");
        }


        cout << endl;
        cout << "{";
        cout << setfill('=') << setw(50);
        cout << "}" << endl;
        cout << setfill(' ');
        cout << userInput << " appears in the following movie(s):" << endl;

        for(int i=0;i<myMediaLibrary.size();++i){
            if(myMediaLibrary[i]->getMediaType()=='M'){
                if(userInput == dynamic_cast<Movie*>(myMediaLibrary.at(i))->stars.at(0)){
                    //cout<<dynamic_cast<Movie*>(myMediaLibrary.at(i))->getMediaTitle()<<endl;
                    cout<<myMediaLibrary.at(i)->getMediaTitle()<<endl;

                }
            }
        }


        cout << "{";
        cout << setfill('=') << setw(50);
        cout << "}" << endl;
        cout << setfill(' ');
        cout << endl;

    }catch(runtime_error &inputError){
        cout<<"Sorry, but the star: \'"<<userInput<<"\" "<<inputError.what()<<endl;
        cout<<endl;
    }


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
            cout << "A - Print All Media" << endl;
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
                printMovieList(myMediaLibrary);



            }else if(userInput=='B'){
                //print book list
                printBookList(myMediaLibrary);


            } else if (userInput == 'S') {
                //print song list
                printSongList(myMediaLibrary);


            }else if(userInput == 'A'){
                //print all media
                printList(myMediaLibrary);

            } else if (userInput == 'F') {
                //find the movie the star is in
                findMovie(myMediaLibrary);


            } else if(userInput=='G'){
                //print stars for a given movie
                listMovieStars(myMediaLibrary);

            } else if(userInput=='T') {
                //print media counts
                printTotals(myMediaLibrary);

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
