#include "date.h"

Month int_to_month(int x){

    if (x < int(Month::jan) || int(Month::dec) < x){
        error("int_to_month() - bad month");
    }
    return Month(x);
}

Date& default_date(){

    static Date dd{2001, Month::jan, 1};
    return dd;

}

Date::Date()
    :y{default_date().getYear()},
    m{default_date().getMonth()},
    d{default_date().getDay()} {
    
    }

Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}{
        if (!is_date(yy, mm, dd)){
            throw Invalid{};
        }
    }

void Date::addDay(int n){
    d+=n;
}

void Date::addMonth(int n){
    int tmp = int(m);
    tmp += n;
    int(m) = tmp;
}

void Date::addYear(int n){

    if (m == Month::feb && d == 29 && !leapyear(y+n)){
        m = Month::mar;
        d = 1;
    }

    y+=n;
}

bool is_date(int y, Month m, int d){

    //assume y is valid

    if (d <= 0){
        return false;
    }
    if (m < Month::jan || Month::dec < m){
        return false;
    }

    int days_in_month = 31;

    switch(m){
    
        case Month::feb:
            days_in_month = (leapyear(y)) ? 29 : 28;
            break;

        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
            days_in_month = 30;
            break;    

    }

    if (days_in_month < d){
        return false;
    }

    return true;

}

bool leapyear(int y){
    if (y%4 != 0){
        return false;
    }
    else if (y % 100 != 0){
        return true;   
    }
    else if (y % 400 != 0){
        return false;
    }
    else{
        return true;
    }
}


enum class Day{
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

Day day_of_week(int d){
    
    Day dd = Day(d);
    return dd;
}
