//Book.h implementation

#include "book.h"

Book::Book() {
    isChecked = false;
}

Book::Book(string _isbn, string _title, string _author, int _copyright, Genre _g)
    :isbn{_isbn}, title{_title}, author{_author},
        copyright{_copyright}, g{_g}, isChecked{false} {
        
        if (!is_valid()){
            throw Invalid{};
        }
    }

string& Book::getISBN() {
    return isbn;
}

string& Book::getTitle() {
    return title;
}

string& Book::getAuthor() {
    return author;
}

int& Book::getCopyright() {
    return copyright;
}

Genre& Book::getGenre() {
    return g;
}

//SETTERS WITHOUT PARAMS

void Book::setISBN(){
    cout << "What is the book's ISBN#? (format: n-n-n-x, where n is an integer and x can be an integer or letter)\n>";
    getline(cin, isbn);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Book::setTitle(){
    cout << "What is the book's title?\n>";
    getline(cin, title);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Book::setAuthor(){
    cout << "Who is the author of the book?\n>";
    getline(cin, author);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Book::setCopyright(){
    cout << "What is the book's copyright?\n>";
    string tmp;
    getline(cin, tmp);
    copyright = stoi(tmp);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Book::setGenre(){
    cout << "What is the book's genere? (fiction, non-fiction, horror, scifi, fantasy)\n>";
    string tmp_str;
    getline(cin, tmp_str);
    int tmp_int;
    if(tmp_str == "fiction"){
        tmp_int = 0;
    }
    else if(tmp_str == "non-fiction"){
        tmp_int = 1;
    }
    else if(tmp_str == "horror"){
        tmp_int = 2;
    }
    else if(tmp_str == "scifi"){
        tmp_int = 3;
    }
    else if(tmp_str == "fantasy"){
        tmp_int = 4;
    }
    g = int_to_genre(tmp_int);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//SETTERS WITH PARAMS
void Book::setISBN(string& tmp){
    isbn = tmp;
}

void Book::setTitle(string& tmp){
    title = tmp;
}

void Book::setAuthor(string& tmp){
    author = tmp;
}

void Book::setCopyright(int tmp){
    copyright = tmp;
}

void Book::setGenre(string& tmp){
    
    int tmp_int;
    if(tmp == "fiction"){
        tmp_int = 0;
    }
    else if(tmp == "non-fiction"){
        tmp_int = 1;
    }
    else if(tmp == "horror"){
        tmp_int = 2;
    }
    else if(tmp == "scifi"){
        tmp_int = 3;
    }
    else if(tmp == "fantasy"){
        tmp_int = 4;
    }
    g = int_to_genre(tmp_int);

}

bool Book::isAvailable(){
    return isChecked;
}


bool Book::is_valid(){
    //basic validation checks


    //ISBN num format: n-n-n-x, where n is a digit, and x can be digit or letter
    {
        //check size
        if (isbn.length() < 0 || isbn.length() > 16){
            return false;
        }
        
        //tokenize string, check for valid digits
        stringstream ssin(isbn);
        string ss_token;
        int count = 0;
        bool intFlag = true;
        while(count < 3 && ssin.good()){
            getline(ssin, ss_token, '-');
            intFlag = is_number(ss_token);
            if (intFlag = false){
                return false;
            }
            ++count;
        }
        ssin.clear();
    }

    //author -- can't have digits
    for (int i = 0; i < sizeof(string)/sizeof(author); i++){
        if (isdigit(author[i])){
            return false;
        }
    }

    //copyright -- can't have letters
    string tmp_str = to_string(copyright);
    for (int i = 0; i < sizeof(string)/sizeof(tmp_str); i++){
        if (isalpha(tmp_str[i])){
            return false;
        }   
    }

    return true;
}

void Book::checkOut(){
    if (isChecked == false){
        isChecked = true;
    }
    else{
        isChecked = false;
    }
}

Genre int_to_genre(const int& x){

    if (x < int(Genre::fiction) || x > int(Genre::fantasy)){
        error("invalid genre");
    }
    return Genre(x);

}

bool compareByTitle(Book& a, Book& b){

    string tmpA = a.getAuthor();
    string tmpB = b.getAuthor();
    if (tmpA.compare(tmpB) == 0){
        return true;
    }

}

bool orderByAuthor(Book& a, Book& b){
    return a.getAuthor() < b.getAuthor();
}
