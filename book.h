/*************
 
  Book Class for ch9 drill from Programming: Principles and Practice using C++ by Bjarne Stroustrup
 
  Drill done by Zachary Turak (c)


 *************/

#ifndef _BOOK
#define _BOOK

#include "std_lib_facilities.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

//enum class for genres
enum class Genre{
    fiction, nonfiction, horror, scifi, fantasy  
};

class Book {

public:

    //error handling
    class Invalid {}; 
    

    //constructors/getters/setters/etc.
    Book();
    Book(string _isbn, string _title, string _author, int _copyright, Genre g);

    string& getISBN();
    string& getTitle();
    string& getAuthor();
    Genre& getGenre();
    int& getCopyright();
    bool isAvailable();

    //setters without params
    void setISBN();
    void setTitle();
    void setAuthor();
    void setCopyright();
    void setGenre();

    //setters with params
    void setISBN(string& str);
    void setTitle(string& str);
    void setAuthor(string& str);
    void setCopyright(int n);
    void setGenre(string& str);

    void checkOut();
    
    //overloaded operators
    inline friend ostream& operator<<(ostream& output, Book& obj){

        string canCheck;
        if (obj.isAvailable()){
            canCheck = "No";
        }
        else{
            canCheck = "Yes";
        }
        string tmp_str;

        if (obj.g == Genre::fiction){
            tmp_str = "Fiction";
        }
        else if (obj.g == Genre::nonfiction){
            tmp_str = "Non-fiction";
        }
        else if (obj.g == Genre::horror){
            tmp_str = "Horror";
        }
        else if (obj.g == Genre::scifi){
            tmp_str = "Sci-fi";
        }
        else if (obj.g == Genre::fantasy){
            tmp_str = "Fantasy";
        }

        output << "Title: " << obj.title << '\n'
            << "Author: " << obj.author << '\n'
            << "ISBN: " << obj.isbn << '\n'
            << "Genre: " << tmp_str << '\n'
            << "Available: " << canCheck << '\n';
        return output;
    }

    inline friend bool operator==(const Book& a, const Book& b){
        if (a.isbn.compare(b.isbn) == 0){
            return true;
        }
    }

    inline friend bool operator!=(const Book& a, const Book& b){
        if (a.isbn.compare(b.isbn) != 0){
            return true;
        }
    }

    //return true if book properties are valid
    bool is_valid();

private:

    string isbn, title, author; 
    int copyright;
    Genre g;
    bool isChecked;
    

};

//helper functions
inline bool is_number(const string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)){
        ++it;
    }

    return !s.empty() && it == s.end();
}

Genre int_to_genre(const int& x);

bool compareByTitle(Book& a, Book& b);
bool orderByAuthor(Book& a, Book& b);

#endif
