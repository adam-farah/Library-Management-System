#include "Library.h"

Library::Library(){

  //books   = new BookArray; //don't get why we need to create new, we didn't need to do that for the assignment
  //patrons = new PatronArray;

}
 

int Library::getNumBooks()   { return books.getNumBooks();   }
int Library::getNumPatrons() { return patrons.size(); }

Book* Library::getBook(int index) 
{ 
  return books.getBook(index); 
}

Patron* Library::getPatron(int index) 
{ 
  int i = 0;
  for(itr=patrons.begin(); itr!=patrons.end(); ++itr)
  {
    if(i == index)
      return *itr;
      i++;
  }
}

int Library::addBook(Book* book)
{
  return books.addBook(book);
}

int Library::addPatron(Patron* patron)
{
  patrons.push_back(patron);
  return C_OK;
}

int Library::findPatron(string fn, string ln, Patron** patron)
{
  for (itr=patrons.begin(); itr!=patrons.end(); ++itr) {
    if ((*itr)->getFname() == fn && (*itr)->getLname() == ln) {
      *patron = *itr;
      return C_OK;
    }
  }
  *patron =  0;
  return C_NOK;
}


int Library::findBook(int bookId, Book** book)
{

  return books.findBook(bookId, book);

}


int Library::checkBookOut(Patron* patron, Book* book)
{
  book->setStatus(CHECKED_OUT);
  return patron->addCheckedOutBook(book);
}


void Library::checkBookIn(Patron* patron, Book* book)
{
  book->setStatus(CHECKED_IN);
  patron->removeBook(book);
}


Library::~Library()
{

  books.cleanUp();
  
  for(itr=patrons.begin(); itr!=patrons.end(); ++itr)
  {
    delete *itr;
  }
  

}


