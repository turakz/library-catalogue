//Patron.h implementation

#include "patron.h"

Patron::Patron()
    :id{""}, name{""}, fee{0}{
    
    }


Patron::Patron(string _id, string _name, double _fee)
    :id{_id}, name{_name}, fee{_fee} {

        if (!is_valid()){
            throw Invalid();
        }
    }

string Patron::getId(){
    return id;
}

string Patron::getName(){
    return name;
}

double Patron::getFee(){
    return fee;
}

//SETTERS WITHOUT PARAMS

void Patron::setId(){
    cout << "Patron I.D.\n>";
    getline(cin, id, '\n');
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Patron::setName(){
    cout << "Patron name\n>";
    getline(cin, name, '\n');
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Patron::setFee(){
    
    string payment;
    double tmp_fee;

    if (does_Owe()){
        cout << name << " owes: " << fee << endl;
        cout << "How much are they paying?\n>";
        getline(cin, payment);
        tmp_fee = stod(payment);
        fee -= tmp_fee;
    }
    else {
        cout << "How much does " << name << " owe?\n>";
        getline(cin, payment);
        tmp_fee = stod(payment);
        if (fee == 0){
            fee = tmp_fee;
        }
        else if (fee > 0){
            fee += tmp_fee;
        }
    }
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

bool Patron::is_valid(){
    //basic validation checks

    //make sure name is not a number
    bool checkFlag = is_number(name);
    if (checkFlag){
        return false;
    }

    //make sure id is a number
    checkFlag = is_number(id);
    if (!checkFlag){
        return false;
    }

    //make sure fee input is +tve
    if (fee < 0){
        return false;
    }   

    return true;
}

bool compareByName(Patron& a, Patron& b){
    
    string tmpA = a.getName();
    string tmpB = b.getName();
    if (tmpA.compare(tmpB) == 0){
        return true;
    }
}

bool orderByName(Patron& a, Patron& b){
    return a.getName() < b.getName();
}
