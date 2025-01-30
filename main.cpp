#include <iostream>
#include <vector>
#include <cstring>
#include "Students.h"
#include "Hash.h"
using namespace std;



//Methods initizalized here
bool userSelection(vector<Student*> &);
void Add(vector<Student*> &);
void Print(vector<Student*> &);
void Delete(vector<Student*> &);
void setLowerCase(char cstring[]);
void checkInvalid();


//Change students to being stored in a hash table instead of a vector

int main() {

  vector<Student*> stuVec; //vector of student pointers

  //Just a student to start with (not needed, but why not)
  Student* bob = new Student; //Makes a student pointer 'bob' that points to a new Student object
  bob->firstName[0] = 'B'; //now use -> operator to get the structure member with a pointer
  bob->firstName[1] = 'o';
  bob->firstName[2] = 'b';
  bob->firstName[3] = '\0';
  bob->lastName[0] = 'B';
  bob->lastName[1] = 'e';
  bob->lastName[2] = 'n';
  bob->lastName[3] = '\0';
  bob->id = 1234;
  bob->gpa = 4.00;
  stuVec.push_back(bob); //Insert the student pointer into the vector


  Hash *hashTable = new Hash();
  generateRandom(10);
  hashTable->displayTable();
  
  //Keep looping till the user inputs quit command
  while (!userSelection(stuVec));

  return 0;
}


//Menu where user selects what they want to do.
bool userSelection(vector<Student*> &stuVec) {
  bool validIn = false;
  while (!validIn) {
    char input[7];
    char usrChoice;
    cout << "Create (c), Print out (p), or Delete (d) a student. Quit (q)" << endl;

    cin.get(input, 7);
    setLowerCase(input); //set the letters of the input to lowercase
    cin.ignore(); //prevent extra return

    //Checks which input the user did.
    if (strcmp(input, "create") == 0 || strcmp(input, "c") == 0) {
      validIn = true;
      Add(stuVec);
    } else if (strcmp(input, "print") == 0 || strcmp(input, "p") == 0) {
      validIn = true;
      Print(stuVec);
    } else if (strcmp(input, "delete") == 0 || strcmp(input, "d") == 0) {
      validIn = true;
      Delete(stuVec);
    } else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0) {
      return true; //bool returns true is we want to exit the program.
    } else {
      cout << "invalid input" << endl;
    }
    checkInvalid(); //checks for input that break the program.
  }
  return false; //default keep looping through program.
}

//Adds a new student pointer to the list/vector, user assigns student data.
void Add(vector<Student*> &stuVec) {
  Student* anon = new Student; //create a new student pointer
  cout << "Student first name: " << endl;
  cin.get(anon->firstName, 10);
  cin.get();
  cout << "Student last name: " << endl;
  cin.get(anon->lastName, 10);
  cin.get();
  cout << "Student id: " << endl;
  cin >> anon->id;
  cin.ignore();
  cout << "Student gpa: " << endl;
  cin >> anon->gpa;
  cin.ignore();
  stuVec.push_back(anon); //add it to the vector
}

//Prints out all of the currently stored student data.
void Print(vector<Student*> &stuVec) {
  if (stuVec.empty()) {
    cout << "There are no students" << endl;
  } else {
    cout << "NAME, ID, GPA" << endl;

    //The iterator 'it' is a pointer to Student*, and Student* points to the Student objects
    for (vector<Student*>::iterator it = stuVec.begin(); it != stuVec.end(); it++) {
    //print out the information for a student.
    cout.setf(ios::showpoint); //show zeros in the decimal places
    cout.precision(3); //to 2 decimal places (for the gpa)
    cout << (*it)->firstName << " " << (*it)->lastName << ", " << (*it)->id << ", " << (*it)->gpa << endl;
    }
  }
}

//User inputs the id of the student to remove from the list
void Delete(vector<Student*> &stuVec) {
  int idIn = 0;
  int idIndex = -1;
  bool isId = false;

  while (!isId) {
    cout << "Enter the id of the student you want to remove" << endl;
    cin >> idIn;
    //loop through the student list
    for (vector<Student*>::iterator it = stuVec.begin(); it != stuVec.end(); it++) {
      if ((*it)->id == idIn) { //if id match
	isId = true;
	idIndex = it - stuVec.begin(); //store the index of where that id is (so we can use it outside the loop)
	break; //exit the iterator
      }
    }
    if (!isId) {
      cout << "Invalid id, try again" << endl;
    }
    checkInvalid();
  }

  cout << "Are you sure you want to delete that student? (y/n)" << endl;
  char choice;
  cin >> choice;
  cin.ignore(); //Fix it from breaking cin.get() with an extra return
  if (choice == 'y') {
    delete(stuVec.at(idIndex)); //delete the student pointer
    stuVec.erase(stuVec.begin() + idIndex); //delete it from the vector
  }
}

//Pass in an array by reference, to change all contents to lowercase
 void setLowerCase(char cstring[]) {
   for (int i = 0; i != strlen(cstring); i++) { //loop until string end
     cstring[i] = tolower(cstring[i]); //set the char here to lowercase
   }
 }

//Used to check/fix if an invalid input breaks the program (causing infinite print loop)
void checkInvalid() {
  while (cin.fail()) {
    cin.clear();
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.ignore(100, '\n');
    cout << "You entered an invalid input. Try again" << endl;
  }
}
