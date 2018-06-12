#ifndef PATRON_H
#define PATRON_H

#include <string>
#include "Book.h"
#include "types.h"
#include "BookArray.h"

class Patron
{
  public:
    Patron(string="", string="");
    string getFname();
    string getLname();
    int    addCheckedOutBook(Book*);
    void   removeBook(Book*);//remove func that calls checkedOutBooks.remove
    int    findBook(int, Book**);  //findBook func that calls checkedOutBooks.findBook
  private:
    string fname;
    string lname;
    BookArray checkedOutBooks;
    
};

#endif

