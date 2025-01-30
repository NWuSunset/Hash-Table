#ifndef NODE_H
#define NODE_H

#include "Students.h"

class Node {
    public:
      Node(int data);
  Node(Student* student);
    
  Student* student; 
      Node* nextNode = nullptr;

  ~Node(); //destructor just in case
};



#endif //NODE_H
