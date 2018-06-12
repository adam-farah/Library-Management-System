#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "types.h"
#include "Book.h"
#include "Patron.h"
#include "BookArray.h"
#include <list>
#include "Patron.h"

class Library
{
  public:
    Library();
    ~Library();
    int     addBook(Book*);
    int     addPatron(Patron*);
    int     getNumBooks();
    int     getNumPatrons();
    Book*   getBook(int);
    Patron* getPatron(int);
    int     findPatron(string, string, Patron**);
    int     findBook(int, Book**);
    int     checkBookStatus(Book*);
    int     checkBookOut(Patron*, Book*);
    void    checkBookIn(Patron*, Book*);
  private:
    //Book*   books[MAX_COLL_SIZE];
    //Patron* patrons[MAX_COLL_SIZE];

    //PatronArray patrons;
    list<Patron*> patrons;
    list<Patron*>::iterator itr;
    BookArray   books;
};

#endif

