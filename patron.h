/********************
 
  Patron Class from ch9 Programming: Principles and Practice using C++ by Bjarne Stroustrup

  Drill done by Zachary Turak (c)


 *******************/

#ifndef _PATRON
#define _PATRON

#include "std_lib_facilities.h"
#include "book.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Patron {

public:

    //error handling
    class Invalid {};
    
    //constructors/getters/setters/etc.
    Patron();
    Patron(string _id, string _name, double _fee);

    string getId();
    string getName();
    double getFee();

    void setId();
    void setName();
    void setFee();

    inline friend ostream& operator<<(ostream& output, Patron& obj){
        output << "Patron: " << obj.name << '\n'
            << "I.D.: " << obj.id << '\n'
            << "Fees Owed: " << obj.fee << '\n';
        return output;
    }

    bool does_Owe() {
        if (fee > 0) {
            return true;
        }
        else {
            return false;
        }
    }


private:

    string id, name;
    double fee;
        
    bool is_valid();

};

//helper functions

bool compareByName(Patron& a, Patron& b);
bool orderByName(Patron& a, Patron& b);

#endif

