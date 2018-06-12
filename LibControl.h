#ifndef LIB_CONTROL_H
#define LIB_CONTROL_H

#include "types.h"
#include "Library.h"
#include "View.h"
#include <fstream>

class View;

class LibControl
{
  public:
    LibControl(); //constructor (ctor), don't add to UML
    ~LibControl();
    void launch();
    void addPatron();
    void checkBookOut(Patron*, Book*);
  private:
    Library lib;
    View    view;
    void    initLib();
    ofstream logFile;
};

#endif

