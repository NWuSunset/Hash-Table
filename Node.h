#ifndef NODE_H
#define NODE_H

#include "Students.h"

class Node {
    public:
        explicit Node(Student* student); //Explicit prevents invalid node creation to int or node. (implicit conversion by compiler)
    
      Student* student = nullptr;
      Node* nextNode = nullptr;

  ~Node(); //destructor just in case
};



#endif //NODE_H
