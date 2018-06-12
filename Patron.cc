#include "Patron.h"

Patron::Patron(string fn, string ln) 
{ 
  fname = fn;
  lname = ln;
}

string Patron::getFname() { return fname; }
string Patron::getLname() { return lname; }

int Patron::addCheckedOutBook(Book* book)
{
  return checkedOutBooks.addBook(book);
}


void Patron::removeBook(Book* book)
{
  checkedOutBooks.removeBook(book);
}


int Patron::findBook(int bookId, Book** book)
{
  return checkedOutBooks.findBook(bookId, book);
}
