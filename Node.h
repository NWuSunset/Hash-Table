#ifndef NODE_H
#define NODE_H

#include "Students.h"

class Node {
    public:
      Node(int data);

    protected:
  Student* student; 
      Node* nextNode = nullptr;
};



#endif //NODE_H
