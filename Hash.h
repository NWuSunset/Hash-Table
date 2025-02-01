

#ifndef HASH_H
#define HASH_H

#include "Node.h"
//Hash where each position is a linked list
//Hash function attemps to spread data out evenly in the table
//If a collision happens then the key (or student) will just go to the next node in the linked list at the same position in the table
//If there become more than 3 collisions, (4 nodes in a table slot) create a table that has (at least) double the number of slots as the original table, then rehash the data into the new table
class Hash {
  public:
  Hash();
  //adds a key to hash table (keys are the students, which get converted using the hash function)
  void insertItem(int key, Student* student); 
  void deleteItem(int key);

  int hashFunction(int key) const; //hashes the key (maps key to 'undecodable' int)
  void rehash();
  
  void displayTable() const; //display values

  protected:
  Node** table = new Node*[100]{}; //100 table spots (Of nodes) ({} makes all table values null)
  int tableSize = 100;
};



#endif //HASH_H
