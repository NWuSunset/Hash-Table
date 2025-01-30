#include "Hash.h"
#include <iostream>

using namespace std;
Hash::Hash() = default;

//!! Change data to student when applicable

void Hash::insertItem(int key, Student* student) { //key is student ID (just makes it easier to keep trakc of)
  int index = hashFunction(key); //index is the returned hash
  int collisions = 1; //if we move onto incrimenting collisions, the head would already exist (so there would be one collision)
  if (table[index] == nullptr) { //if the head node is null
    cout << table[index] << "INDEX" << endl;
    //cout << table[index] << student->firstName << " " << student->id << endl;
    table[index] = new Node(student);
  } else {
    Node* curr = table[index];
    
    while (curr->nextNode != nullptr) {
      //Go to next node in the linked list
      curr = curr->nextNode;
      collisions++; //if there is another node in the linked list, incriment collision value
    }
    //Insert new node to end of linked list
    curr->nextNode = new Node(student);
  }

  //If there are more than 3 collision (4 things in a single linked List)
  if (collisions > 3) {
    rehash(); //rehash the table and creating double the slots
  }
}

//delete item based on inserted key (Student ID)
void Hash::deleteItem(int key) {
  int index = hashFunction(key); //find the index where the key could exist

  Node* curr = table[index]; 
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
  cout << key%tableSize << "HEOIEHE" << endl;
  return (key % tableSize); //Simple hash function to spread out the table (key mod tableSize)
}

void Hash::rehash() {
  cout << "ReHASH" << endl;
}

void Hash::displayTable() {
  for (int i = 0; i < tableSize; i++) {
    cout << i;
    //Loop through all of the linked list values
    Node* curr = table[i];
    while (curr != nullptr) { //print out the linked list values
      cout << "-->" << curr->student->firstName;
      curr = curr->nextNode;
    }
    cout << endl;
  }
}
