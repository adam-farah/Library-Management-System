#ifndef BOOKARRAY_H
#define BOOKARRAY_H

#include <string>
#include "types.h"
#include "Book.h"

class BookArray
{
  class Node
  {
    friend class BookArray;
    Book* data;
    Node* next;
  };
  
  public:
    BookArray();
    ~BookArray();
    int     addBook(Book*);
    void    removeBook(Book*);
    int     getNumBooks(); // do we still need this? You typically don't keep track of size in linked list right?
    Book*   getBook(int);
    int     findBook(int, Book**);
    void    cleanUp();
  private:
    //Book*   books[MAX_COLL_SIZE];
    Node*   head;
    int     numBooks;
};

#endif
