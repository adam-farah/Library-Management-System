#include "BookArray.h"


BookArray::BookArray()
  : head(0), numBooks(0){}
  

BookArray::~BookArray()
{
  Node* currNode = head;
  Node* nextNode = NULL;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}


int BookArray::getNumBooks()   {return numBooks;}


Book* BookArray::getBook(int index) 
{ 
  if (index < 0 || index >= numBooks)
    return 0;
    
  Node* currNode = head;
  int i = 0;
    
  while(i < index)
  {
    currNode = currNode->next;
    i++;
  }

  return currNode->data; 
}


int BookArray::addBook(Book* book)
{

  if (numBooks >= MAX_COLL_SIZE - 1) {
    return C_NOK;
  }

  Node* newBookNode;
  Node* currNode = head;
  Node* prevNode = NULL;

  newBookNode = new Node;
  newBookNode->data = book;
  newBookNode->next = NULL;
  

  while (currNode != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {	// add to beginning
    head = newBookNode;
  } 
  else {
  prevNode->next = newBookNode;
  }
  //no need to set newBookNode's next to currNode(which will be NULL after traversing to the end) cus 
  // you're always adding to the end and you do initialize newBookNode's next to NULL above
  
  numBooks++;

  return C_OK;
}


void BookArray::removeBook(Book* book)
{

  Node* currNode = head;
  Node* prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == book->getId()) 
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode;
}


int BookArray::findBook(int bookId, Book** book)
{

  for ( Node* currNode = head;
        currNode != NULL; 
        currNode = currNode->next) {
        
    if(currNode->data->getId() == bookId){
      *book = currNode->data;
      return C_OK;
    }
  }

  return C_NOK;
}


void BookArray::cleanUp()
{

  Node* currNode = head;
  Node* nextNode = NULL;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }

}






