#include "Hash.h"

Hash::Hash() = defualt();

//!! Change data to student when applicable

void Hash::insertItem(int key) {
  int index = hashFunction(key); //index is the returned hash
  int collisions = 1; //if we move onto incrimenting collisions, the head would already exist (so there would be one collision)
  if (table[index] == nullptr) { //if the head node is null
    table[index] = new Node(key);
  } else {
    Node* curr = table[index];
    
    while (curr->nextNode != nullptr) {
      //Go to next node in the linked list
      curr = curr->nextNode;
      collisions++; //if there is another node in the linked list, incriment collision value
    }
    //Insert new node to end of linked list
    curr->nextNode = new Node(key);
  }

  //If there are more than 3 collision (4 things in a single linked List)
  if (collisions > 3) {
    rehash() //rehash the table and creating double the slots
  }
}

//delete item based on inserted key (Student ID)
void Hash::deleteItem(int key) {
  int index = hashFunction(key); //find the index where the key could exist

  Node* curr = table[index] 
  //Find the location of that specific key
    while (curr->nextNode != nullptr) {
      if (curr->nextNode->student->id == key) { //if we find the key to delete
	delete curr->nextNode;
	return;
      }
      curr = curr->nextNode;
    }
  //if null and have not found that key
  cout << "That doesn't exist in the table" << endl;
}

int Hash::hashFunction(int key) {
  return (key % tableSize); //Simple hash function to spread out the table (key mod tableSize)
}

void Hash::rehash() {
  cout << "ReHASH" << endl;
}

void Hash::displayTable() {
  for (int i = 0; i < tableSize; i++) {
    //Loop through all of the linked list values
    Node* curr = table[i];
    while (curr != nullptr) {
      cout <<
      curr = curr->nextNode;
    }
  }
}
