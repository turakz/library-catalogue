#include "library.h"
#include <iomanip>
#include <stdio.h>
#include <cstdlib>

void clearScreen();
void printMenu();
void createLibrary();

int main(){

    Library libSys;
    bool libFlag = true;
    do {

        printMenu();
        char input = getchar();
        switch(input) {
        
            case '0':
                //load library
                libSys.choice = false;
                libSys.addBook();
                break;

            case '1':
                //add patron
                clearScreen();
                libSys.addPatron();
                break;

            case '2':
                //remove patron
                clearScreen();
                libSys.removePatron();
                break;

            case '3':
                //add book
                clearScreen();
                libSys.addBook();
                break;

            case '4':
                //remove book
                clearScreen();
                libSys.removeBook();
                break;

            case '5':
                //patron details
                clearScreen();
                libSys.printPatrons();
                break;

            case '6':
                //book details
                clearScreen();
                libSys.printBooks();
                break;

            case '7':
                //check out book
                clearScreen();
                libSys.makeTransaction();
                break;

            case '8':
                //return book
                clearScreen();
                libSys.returnBook();
                break;

            case '9':
                //exit
                clearScreen();
                cout << "Have a nice day!" << endl;
                libFlag = false;
                break;

            default:

                break;
        
        }

    
    } while(libFlag);
    
    keep_window_open();
    return 0;
}

void clearScreen() {

#ifdef WINDOWS
    
    system("CLS");

#else

    system("clear");
    
#endif

}

void printMenu(){

    vector<string> menu = {
   
        "Load Library",
        "Add Patron",
        "Remove Patron",
        "Add Book",
        "Remove Book",
        "Patron Details",
        "Book Details",
        "Check-out Book",
        "Return Book",
        "Exit"
    
    };

    clearScreen();
    cout << "Library Menu" << endl;
    cout << endl;
    for (int i = 0; i < menu.size(); i++){
        cout << i << ". " << menu[i] << "\n";
    }

    cout << endl;
    cout << "Type option and press enter: ";
    cout << endl;


}


