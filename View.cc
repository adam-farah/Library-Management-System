#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

#include "View.h"

View::View()
{

}

void View::mainMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   WELCOME TO THE LIBRARY SYSTEM \n\n\n\n";
  cout<< "        Here are your options:\n\n";
  cout<< "          1. Administrator Menu\n\n";
  cout<< "          2. Patron Menu\n\n";
  cout<< "          3. View Entire Collection\n\n";
  cout<< "          0. Exit\n\n";
  cout<< "        Enter one of the choices above:  ";
  getline(cin, str);

  while (str != "1" && str != "2" && str != "3"
      && str != "0") {
    cout<< "        Enter one of the choices above:  ";
    getline(cin, str);
  }
  stringstream ss(str);
  ss >> choice;
}

void View::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   ADMINISTRATOR MENU \n\n";
  cout<< "        Here are your options:\n\n";
  cout<< "          1. Add a Patron \n";
  cout<< "          0. Exit\n\n";
  cout<< "        Enter one of the choices above:  ";
  getline(cin, str);

  while (str != "1" && str != "0") { 
    cout<< "        Enter one of the choices above:  ";
    getline(cin, str);
  }
  stringstream ss(str);
  ss >> choice;
}

void View::patronMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   PATRON MENU \n\n";
  cout<< "        Here are your options:\n\n";
  cout<< "          1. Check out a book\n";
  cout<< "          2. Check in a book\n";
  cout<< "          0. Exit\n\n";
  cout<< "        Enter one of the choices above:  ";
  getline(cin, str);

  while (str != "1" && str != "2" && str != "0") { 
    cout<< "        Enter one of the choices above:  ";
    getline(cin, str);
  }
  stringstream ss(str);
  ss >> choice;
}


void View::viewCollection(Library& lib)
{
  printCollection(lib);
  cout<< "\nPress <ENTER> to continue...";
  cin.get();
}

void View::printAll(Library& lib)
{
  printCollection(lib);
  printPatrons(lib);
}

void View::printCollection(Library& lib)
{
  cout << endl << setw(40)<< "COLLECTION" <<endl;;
  cout << setw(40)<< "----------"<<endl<<endl;

  for (int i=0; i<lib.getNumBooks(); ++i) {
    if (lib.getBook(i) == NULL)
      continue;
    printBookInfo(lib.getBook(i));
  }
}

void View::printBookInfo(Book* book)
{
  cout<< "    "<<setw(4)<<book->getId()<<setw(40)<<book->getTitle()<<setw(20)<<book->getAuthor();

  switch(book->getStatus()) {
    case CHECKED_IN:
      cout<< "  "<<setw(12)<< "Checked in";
      break;
    case CHECKED_OUT:
      cout<< "  "<<setw(12)<< "Checked out";
      break;
    case UNDER_REPAIR:
      cout<< "  "<<setw(12)<< "Under repair";
      break;
    case LOST:
      cout<< "  "<<setw(12)<< "Lost";
      break;
  }
  cout << endl;
}


void View::printPatrons(Library& lib)
{
  string str;

  cout<< endl<<endl<<setw(40)<<"PATRONS"<<endl;;
  cout << setw(40)<< "-------"<<endl<<endl;

  for (int i=0; i<lib.getNumPatrons(); ++i) {
    Patron* p = lib.getPatron(i);
    if (p == NULL)
      continue;
    str = p->getFname() + " " + p->getLname();
    cout << setw(40) << str << endl;
  }
  cout<< endl;
}

void View::printError(const string& err)
{
  cout << err << endl;
  cin.get();
}

void View::getPatronName(string& fn, string& ln)
{
  string str;

  cout<< endl<<"        Enter patron name ([first] [last]:  ";
  getline(cin, str);
  stringstream ss(str);
  ss >> fn >> ln;
}


void View::promptIdForCheckOut(int& num)
{

  string str;

  cout<< "\n        Please enter the id of the book to be checked out: "; 
  getline(cin, str);
  stringstream ss(str);
  ss >> num;
  

}


void View::promptIdForCheckIn(int& num)
{

  string str;

  cout<< "\n        Please enter the id of the book to be checked in: "; 
  getline(cin, str);
  stringstream ss(str);
  ss >> num;
  

}






