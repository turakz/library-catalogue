/*********************
 
 Library Class for drill from Ch9 of Programming: Principles and Practice Using C++ by Bjarne Stroustrup

 Written by Zachary Turak (c)
 
 
 ********************/


#ifndef _LIBRARY
#define _LIBRARY

#include "std_lib_facilities.h"
#include "book.h"
#include "patron.h"
#include "date.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Transaction{

    Book b;
    Patron p;
    Date d;

};

class Library{

public:

    //error handling
    class Invalid{};

    //constructors/getters/setters/etc.
    Library();

    Book getBook(string s);
    Patron getPatron(string s);
    //Date getDate(Date& obj);

    void addBook();
    void addPatron();
    void removeBook();
    void removePatron();
    //void setDate(Date& obj);
    void makeTransaction();
    void setCheckout(Transaction& t);
    void setCheckoutFee(Transaction& t);
    void returnBook();
    Transaction& getTransaction(int n);


    //testing
    void printBooks(){

        for (int i = 0; i < books.size(); i++){
            cout << books[i] << "\n";
        }
        char tmpChar;
        cout << "Press enter to continue..." << '\n';
        cin.get(tmpChar);
        cin.ignore();
    }

    void printPatrons(){
    
        for (int i = 0; i < patrons.size(); i++) {
            cout << patrons[i] << "\n";
        }
        char tmpChar;
        cout << "Press enter to continue..." << '\n';
        cin.get(tmpChar);
        cin.ignore();
    }

    bool choice = true;


private:

    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;

};

#endif
