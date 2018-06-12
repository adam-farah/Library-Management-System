#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

#include "types.h"

class Book
{
  public:
    Book();
    Book(string, string, int);
    void setStatus(BookStatusType);
    BookStatusType getStatus();
    int    getId();
    string getTitle();
    string getAuthor();
  private:
    static int     nextId;
    int            id;
    string         title;
    string         author;
    int            year;
    BookStatusType status;
};

#endif

