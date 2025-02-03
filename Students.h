#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
#include <cstring>

using namespace std;


struct Student {
    //Structure of a student
    char firstName[20];
    char lastName[20];
    int id;
    float gpa;

  //Prints all the student data
  void printData() {
    cout.setf(ios::showpoint); //show zeros in the decimal places
    cout.precision(3); //to 2 decimal places (for the gpa)

    char* first = firstName;
    char* last = lastName; 

    cout << first;
    cout << endl;
    cout << last; 
    cout << endl;	 
    cout << id << endl;
    cout << gpa << endl;
    cout << endl;
  }
};

//Forward declaration of class hash (so we don't create circular dependencies.)
class Hash;


//Takes in number of students to generate, generates that amount of students, with random(ish) data. 
void generateRandom(int toGenerate, Hash* hashTable); 


#endif //STUDENTS_H
