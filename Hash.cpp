#include "Hash.h"
#include <iostream>

using namespace std;
Hash::Hash() = default;

void Hash::insertItem(const int key, Student* student, const bool isRehashing) {
    //key is student ID (just makes it easier to keep track of)
    if (!isRehashing && idExists(key)) {
        cout << "ID already exists. Cannot insert student." << endl;
        return;
    }

    const int index = hashFunction(key); //index is the returned hash
    int collisions = 0;
    //if we move onto incrementing collisions, the head would already exist (so there would be one collision)
    if (table[index] == nullptr) {
        //if the head node is null
        table[index] = new Node(student);
    } else {
        Node* curr = table[index];

        collisions++; //Collision for the first node

        while (curr->nextNode != nullptr) {
            //Go to next node in the linked list
            curr = curr->nextNode;
            collisions++; //if there is another node in the linked list, increment collision value
        }
        //Insert new node to end of linked list
        curr->nextNode = new Node(student);
    }

    idArray[idCount++] = key; //Add ID to the id Array for tracking

    
    //If there are more than 3 collision (4 things in a single linked List chain)
    if (collisions >= 3) {
        rehash(); //rehash the table and creating double the slots
    }
}

//delete item based on inserted key (Student ID)
void Hash::deleteItem(const int key) {
    const int index = hashFunction(key); //find the index where the key could exist
    Node* curr = table[index];
    Node* prev = nullptr;

    while (curr != nullptr && curr->student->id != key) {
        prev = curr;
        curr = curr->nextNode;
    }

    if (curr == nullptr) {
        cout << "ID not found" << endl;
        return;
    }

    if (prev == nullptr) {
        //In the case that the node to delete is the head node
        table[index] = curr->nextNode; //Update the head node to the next position
    } else {
        //If isn't the head
        prev->nextNode = curr->nextNode; //skip over the node to be deleted (reorder the linked list)
    }

    delete curr; //delete found node

    //Update the number of ids
    for (int i = 0; i < idCount; i++) {
        if (idArray[i] == key) {
            //Find the key that was deleted
            idArray[i] = idArray[--idCount];
            //set that to the last element in the array (and de-increment the id count, basically removing that id from the array)
            i = idCount; // exit for loop
        }
    } 
}

int Hash::hashFunction(const int key) const {
    return (key % tableSize);
    //Simple hash function to spread out the table (key mod tableSize). Keys will spread differently depending on table size
}

//Double the size of the table, then rehash everything
void Hash::rehash() {
    cout << "REHASH" << endl;
    const int oldSize = tableSize;
    tableSize *= 2; //double table size
    Node** oldTable = table; //Save old table
    table = new Node*[tableSize]{}; //Table is now an empty table of double the original size

    //Go through the old values
    for (int i = 0; i < oldSize; i++) {
        //Loop through their keys (student ids) and insert each into the new table
        Node* curr = oldTable[i];
        while (curr != nullptr) {
            insertItem(curr->student->id, curr->student, true);
            curr = curr->nextNode; //I forgot to move up in the linked list...
        }
    }
    delete[] oldTable; //free up memory
} //!!CHECK IF THE nodes next is still pointing to the old table that was deleted.

void Hash::displayTable() const {
    //Debugging function, displays Indexes along with keys (student ids)
    for (int i = 0; i < tableSize; i++) {
        cout << i;
        //Loop through all the linked list values
        const Node* curr = table[i];
        //const ensures the pointer itself can be modified, but the values of the Node it's pointing to can (so curr = curr->nextNode works).
        while (curr != nullptr) {
            //print out the linked list values
            cout << "-->" << curr->student->id;
            curr = curr->nextNode;
        }
        cout << endl;
    }
}

bool Hash::idExists(const int id) const {
   for (int i = 0; i < idCount; i++) {
     if (idArray[i] == id) {
            return true;
     }
   } 
   return false;
}
