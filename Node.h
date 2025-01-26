//
// Created by Infer on 1/25/2025.
//

#ifndef NODE_H
#define NODE_H



class Node {
    public:
      Node();

    protected:
      int data{}; //the data for the hash table
      Node* nextNode = nullptr;
};



#endif //NODE_H
