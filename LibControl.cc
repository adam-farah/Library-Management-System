#include <iostream>
#include <sstream>
using namespace std;
#include "LibControl.h"

LibControl::LibControl() 
{ 
  initLib();
  
  logFile.open("log.txt");
}

LibControl::~LibControl()
{
  logFile.close();
}

void LibControl::launch() 
{ 
  int mainChoice   = -1;
  int adminChoice  = -1;
  int patronChoice = -1;
  Patron* p;
  Book*   b; //pass the address of this b in the findBook func asap to remove declare error
  string  fn, ln;
  int     rc, bookId;

  while (mainChoice != 0) {
    view.mainMenu(mainChoice);

    switch(mainChoice) {
      case 1:	// 1. Admin menu
        while (adminChoice != 0) {
          view.adminMenu(adminChoice);
          switch(adminChoice) {
            case 1:	// 1. Add patron
              addPatron(); 
              break;
            default: 	// 0. Exit admin menu
              break;
          }
        }
        adminChoice = -1;
        break;
      case 2:   // 2. Patron menu
        view.getPatronName(fn, ln);
        rc = lib.findPatron(fn, ln, &p);
        if (rc != C_OK) {
          logFile << "Error: " << "Could not find patron " << fn << " " << ln << endl;
          view.printError("Could not find patron...");
          break;
        }
        while (patronChoice != 0) { //apart from the first time before user enters any input, where else does this line ever check if patronChoice is 0
          view.patronMenu(patronChoice);
          switch(patronChoice) {
            case 1:
              view.promptIdForCheckOut(bookId);
              rc = lib.findBook(bookId, &b);
              if (rc != C_OK) {
                view.printError("Could not find book...");
                break;
              }
              checkBookOut(p, b);
              break;
            case 2:
              view.promptIdForCheckIn(bookId);
              rc = p->findBook(bookId, &b);
              if (rc != C_OK) {
                view.printError("Could not find book...");
                break;
              }
              lib.checkBookIn(p, b);
              break;
            default:    // 0. Exit patron menu
              break;
          }
        }
        patronChoice = -1;
        break;
      case 3:	// 3. View collection
        view.viewCollection(lib); 
        break;
      default: 	// 0. Exit main menu
        break;
    }
  }
  view.printAll(lib);
}

void LibControl::addPatron() 
{
  Patron *patron;
  string fn, ln;
  int    rc;

  view.getPatronName(fn, ln);

  patron = new Patron(fn, ln);

  rc = lib.addPatron(patron);
  if (rc != C_OK) {
    logFile << "Error: " << patron->getFname() << " " << patron->getLname() << " could not be added to the library" << endl;
    view.printError("\nCould not add patron to library, press <ENTER> to continue...");
  }
  else
  {
    logFile << "Patron " << patron->getFname() << " " << patron->getLname() << " was added to the library" << endl;
  }
}

void LibControl::checkBookOut(Patron* patron, Book* book)
{
  int status; 
  int rc;
  
  status = book->getStatus();
  
  if(status == CHECKED_IN)
  {
    rc = lib.checkBookOut(patron, book);
    if(rc != C_OK){
      logFile << "Error: " << patron->getFname() << " " << patron->getLname() << " could not be check book out" << endl;
      view.printError("Sorry book storage limit has been reached");
    }
    else
    {
      logFile << patron->getFname() << " " << patron->getLname() << " checked out book " << book->getId()<< endl;
    }
  }
  else if(status == CHECKED_OUT){
    logFile << "Error: " << patron->getFname() << " " << patron->getLname() << " tried to check out a " "\"Checked out\" book" << endl;
    view.printError("Sorry, this book has already been checked out");
  }
  else if(status == UNDER_REPAIR){
      logFile << "Error: " << patron->getFname() << " " << patron->getLname() << " tried to check out a book " "\"Under repair\"" << endl;
    view.printError("Sorry, this book is under repair");
  }
  else if(status == LOST){
    logFile << "Error: " << patron->getFname() << " " << patron->getLname() << " tried to check out a " "\"Lost\" book" << endl;
    view.printError("Sorry, this book is lost");
  }

}


void LibControl::initLib()
{
  Book*   newBook;
  Patron* newPatron;

  newBook = new Book("Ender's Game", "Orson Scott Card", 1985);
  lib.addBook(newBook);

  newBook = new Book("Dune", "Frank Herbert", 1965);
  newBook->setStatus(LOST);
  lib.addBook(newBook);

  newBook = new Book("Foundation", "fIsaac Asimov", 1951);
  lib.addBook(newBook);

  newBook = new Book("Hitch Hiker's Guide to the Galaxy", "Douglas Adams", 1979);
  lib.addBook(newBook);

  newBook = new Book("1984", "George Orwell", 1949);
  lib.addBook(newBook);

  newBook = new Book("Stranger in a Strange Land", "Robert A. Heinlein", 1961);
  newBook->setStatus(UNDER_REPAIR);
  lib.addBook(newBook);

  newBook = new Book("Farenheit 451", "Ray Bradbury", 1954);
  newBook->setStatus(LOST);
  lib.addBook(newBook);

  newBook = new Book("2001:  A Space Odyssey", "Arthur C. Clarke", 1968);
  lib.addBook(newBook);

  newBook = new Book("I, Robot", "Isaac Asimov", 1950);
  lib.addBook(newBook);

  newBook = new Book("Starship Troopers", "Robert A. Heinlein", 1959);
  lib.addBook(newBook);

  newBook = new Book("Do Androids Dream of Electric Sheep?", "Philip K. Dick", 1968);
  lib.addBook(newBook);

  newBook = new Book("Neuromancer", "William Gibson", 1984);
  newBook->setStatus(LOST);
  lib.addBook(newBook);

  newBook = new Book("Ringworld", "Larry Niven", 1970);
  lib.addBook(newBook);

  newBook = new Book("Rendezvous with Rama", "Arthur C. Clarke", 1973);
  newBook->setStatus(UNDER_REPAIR);
  lib.addBook(newBook);

  newBook = new Book("Hyperion", "Dan Simmons", 1989);
  lib.addBook(newBook);


  newPatron = new Patron("Jack", "Shephard");
  lib.addPatron(newPatron);

  newPatron = new Patron("Kate", "Austen");
  lib.addPatron(newPatron);

  newPatron = new Patron("Hugo", "Reyes");
  lib.addPatron(newPatron);

  newPatron = new Patron("James", "Ford");
  lib.addPatron(newPatron);

  newPatron = new Patron("Sayid", "Jarrah");
  lib.addPatron(newPatron);

  newPatron = new Patron("Sun-Hwa", "Kwon");
  lib.addPatron(newPatron);

  newPatron = new Patron("Jin-Soo", "Kwon");
  lib.addPatron(newPatron);

  newPatron = new Patron("John", "Locke");
  lib.addPatron(newPatron);

  newPatron = new Patron("Juliet", "Burke");
  lib.addPatron(newPatron);

  newPatron = new Patron("Benjamin", "Linus");
  lib.addPatron(newPatron);
}

