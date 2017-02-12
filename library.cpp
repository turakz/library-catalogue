#include "library.h"

Library::Library(){}

Book Library::getBook(string s){

    //gets book based on book title 
    for(int i = 0; i < books.size(); i++){
        if (s == books[i].getTitle()){
            return books[i];
        }
    }

}

Patron Library::getPatron(string s){

    for(int i = 0; i < patrons.size(); i++){
        if (s == patrons[i].getName()){
            return patrons[i];
        }
    }

}

void Library::addBook(){

    if (choice){
        cin.clear();
        cin.ignore();
        Book newBook;
        newBook.setTitle();
        newBook.setAuthor();
        newBook.setISBN();
        newBook.setCopyright();
        newBook.setGenre();
    
        if (!newBook.is_valid()){
            error("addBook()");
            throw Invalid{};
        }
        else{
            books.push_back(newBook);
        }
    }
    else{
        ifstream input("catalogue.txt");
        if(!input){
            error("addBook(): failed to open input file - catalogue.txt");
        }

        string data;
        int tmpCOPY, count;

        while(!input.eof()){
            count = 0;
            Book newBook;
            while(count < 5){

                if (input.eof()){
                    break;
                }

                getline(input, data); 
                if(count == 0){
                    newBook.setTitle(data);
                    ++count;
                }
                else if(count == 1){
                    newBook.setAuthor(data);
                    ++count;
                }
                else if (count == 2){
                    newBook.setISBN(data);
                    ++count;
                }
                else if (count == 3){
                    int n = stoi(data);
                    newBook.setCopyright(n);
                    ++count;
                }
                else if (count == 4){
                    newBook.setGenre(data);
                    ++count;
                }

            }

            if (input.eof()){
                break;
            }

            if (!newBook.is_valid()){
                error("addBook() -- input invalid");
                throw Invalid{};
            }
            else{
                books.push_back(newBook);
            }

        }
        choice = true;
    }

    sort(books.begin(), books.end(), orderByAuthor);
}

void Library::addPatron(){

    cin.clear();
    cin.ignore();
    Patron newPatron;
    newPatron.setName();
    newPatron.setId();
    newPatron.setFee();

    patrons.push_back(newPatron);
    sort(patrons.begin(), patrons.end(), orderByName);

}

void Library::removeBook(){

    cout << "What book would you like to remove?\n>";
    string tmp;
    getline(cin, tmp);
    for(int i = 0; i < books.size(); i++){
        if (tmp == books[i].getTitle()){
            books.erase(books.begin() + i);
        }
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void Library::removePatron(){
    
    cout << "Who is the patron you would like to remove?\n>";
    string tmp;
    getline(cin, tmp);
    for (int i = 0; i < patrons.size(); i++){
        if (tmp == patrons[i].getName()){
            patrons.erase(patrons.begin() + i);
        }
    } 
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void Library::setCheckout(Transaction& t){

    for (int i = 0; i < books.size(); i++) {
        if (t.b.getTitle() == books[i].getTitle()){
            books[i].checkOut();
        }
    }

}

void Library::setCheckoutFee(Transaction& t){

    for (int i = 0; i < patrons.size(); i++){
        if (t.p.getName() == patrons[i].getName()){
            patrons[i].setFee();
        }
    }

}

Transaction& Library::getTransaction(int n){
    
    return transactions[n];

}

void Library::returnBook(){
   
    cin.ignore();
    cout << "Who is returning the book?\n>";
    string tmp_name;
    getline(cin, tmp_name);
    cout << "What is book's title?\n>";
    string tmp_title;
    getline(cin, tmp_title);
    int index = 0;
    for (int i = 0; i < transactions.size(); i++){
        if (tmp_name == transactions[i].p.getName()){
            index = i;
            break;
        }
    }

    Transaction t = getTransaction(index);
    setCheckout(t);
    setCheckoutFee(t);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void Library::makeTransaction(){

    cin.ignore();
    Transaction t;
    cout << "What is your name?\n>";
    string tmp;
    getline(cin, tmp);
    t.p = getPatron(tmp);
    cout << "What book would you like to check out?\n>";
    getline(cin, tmp);
    t.b = getBook(tmp);
    setCheckout(t);
    setCheckoutFee(t);
    cout << "Enter today's date (format: year month day ie: 1989 3 7) as integers\n>";
    int y, m, _d;
    cin >> y >> m >> _d;
    Month mm = Month(m);
    Date d(y, mm, _d);
    t.d = d;
    cin.ignore();
    transactions.push_back(t);

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

