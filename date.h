/******************
 
  Date Class from Ch9 of Programming: Principles and Practice using C++ by Bjarne Stroustrup


******************/

#ifndef _DATE
#define _DATE

#include "std_lib_facilities.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {

public:    

    //error handling
    class Invalid {};

    //constructors/getters/setters/etc.
    Date();
    Date(int y, Month m, int d);

    int getDay(){
        return d;
    }
    Month getMonth(){
        return m;
    }
    int getYear(){
        return y;
    }

    void addDay(int n);
    void addMonth(int n);
    void addYear(int n);

    //overloaded operators
    inline friend bool operator==(const Date& a, const Date& b){
        if (a.y == b.y && a.m == b.m && a.d == b.d){
            return true;
        }
    }
    inline friend bool operator!=(const Date& a, const Date& b){
        if (a.y != b.y && a.m != b.m && a.d != b.d ){
            return true;
        }
    }
    inline friend ostream& operator<<(ostream& os, const Date& obj){
        os << '(' << obj.d << ',' << int(obj.m) << ',' << obj.y << ')';
        return os;
    }

private:

    int y;
    Month m;
    int d;

};


Month int_to_month(int x);
bool leapyear(int y);
bool is_date(int y, Month m, int d);
Date& default_date();

#endif
