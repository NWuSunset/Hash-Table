#include <iostream>
#include <cstring>
#include <limits>
#include "Students.h"
#include "Hash.h"
using namespace std;

//Methods initialized here
bool userSelection(Hash* hashTable);
void Add(Hash* hashTable);
void Print(const Hash* hashTable);
void Delete(Hash* hashTable);
void checkInvalid();

template <typename T>
T validInput();

int main() {
    Hash* hashTable = new Hash(); //Initial hash table
    generateRandom(100, hashTable);
    hashTable->displayTable();

    //Keep looping till the user inputs quit command
    while (!userSelection(hashTable)) {
    }

    return 0;
}


//Menu where user selects what they want to do.
bool userSelection(Hash* hashTable) {
    char input[8];
    cout << "Do you want to ADD, PRINT, DELETE, or QUIT" << endl;;
    cin.getline(input, 8);

    //in case more than 8 characters are entered (so it won't break the program)
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //Getting the user input selection
    if (strcasecmp(input, "ADD") == 0) {
        Add(hashTable);
    } else if (strcasecmp(input, "PRINT") == 0) {
        Print(hashTable);
    } else if (strcasecmp(input, "DELETE") == 0) {
        Delete(hashTable);
    } else if (strcasecmp(input, "QUIT") == 0) {
        return true;
    }
    return false;
}

//Adds a new student pointer to the list/vector, user assigns student data.
void Add(Hash* hashTable) {
    //individual variables for clarity
    char firstName[20];
    char lastName[20];
    Student* student = new Student;

    cout << "First Name: " << endl;
    cin.getline(firstName, 20);
    strcpy(student->firstName, firstName);
    cout << "Last Name: " << endl;
    cin.getline(lastName, 20);
    strcpy(student->lastName, lastName);
    cout << "id: " << endl;
    const int id = validInput<int>();
    student->id = id;
    cout << "gpa: " << endl;
    const float gpa = validInput<float>();
    student->gpa = gpa;
    cin.ignore();

    cout << "Adding Student..." << endl; //just for fun
    hashTable->insertItem(student->id, student, false);
}

//Prints out all the currently stored student data.
void Print(const Hash* hashTable) {
    hashTable->displayTable();
}

//User inputs the id of the student to remove from the list
void Delete(Hash* hashTable) {
    cout << "Enter the student id you wish to delete: " << endl;
    const int id = validInput<int>();

    cout << "Deleting student..." << endl;
    hashTable->deleteItem(id);
    cin.ignore();
}

template <typename T>
T validInput() {
    //Template makes it able to take any data type (so I don't have to write code for different types...)
    T value;
    while (!(cin >> value)) {
        cout << "Invalid input. please enter a valid number" << endl;
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    }
    return value;
}
