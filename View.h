#ifndef VIEW_H
#define VIEW_H

#include "Library.h"
#include "Book.h"

class View
{
  public:
    View();
    void mainMenu(int&);
    void adminMenu(int&);
    void patronMenu(int&);
    void viewCollection(Library&);
    void printAll(Library&);
    void printError(const string&);
    void getPatronName(string&, string&);
    void promptIdForCheckOut(int&);
    void promptIdForCheckIn(int&);
  private:
    void printCollection(Library&);
    void printPatrons(Library&);
    void printBookInfo(Book*);
};

#endif

