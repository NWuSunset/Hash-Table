#include "Students.h"
#include <fstream>
#include <iostream>

#include "Hash.h"

using namespace std;

void generateRandom(int toGenerate, Hash* hashTable) {

  //Generates random students
    ifstream firstFile("firstNames.txt");
    ifstream lastFile("lastNames.txt");

    char firstNames[40][20];
    char lastNames[40][20];
    char name[20];

    int firstCount = 0; //So we know the range of random names we have
    while (firstFile.getline(name, sizeof(name))) { //go through the firstName file
      //copy the name to the firstNames array (limiting name size just in case)
      strncpy(firstNames[firstCount], name, sizeof(firstNames[firstCount]) - 1);
        firstNames[firstCount][sizeof(firstNames[firstCount]) - 1] = '\0'; //insert null character to the end of the name
        firstCount++;
    }

    //same for last names
    int lastCount = 0;
    while (lastFile.getline(name, sizeof(name))) {
        strncpy(lastNames[lastCount], name, sizeof(lastNames[firstCount]) - 1);
        lastNames[lastCount][sizeof(lastNames[lastCount]) - 1] = '\0';
        lastCount++;
    }

    firstFile.close();
    lastFile.close();

    srand(time(nullptr)); //seed for random number (use random library for better randomness if needed)

    for (int i = 0; i < toGenerate; i++) {
        Student* newStudent = new Student; //create a new student
        strncpy(newStudent->firstName, firstNames[rand() % firstCount], sizeof(newStudent->firstName) - 1);
        newStudent->firstName[sizeof(newStudent->firstName) - 1] = '\0';

        strncpy(newStudent->lastName, lastNames[rand() % lastCount], sizeof(newStudent->lastName) - 1);
        newStudent->lastName[sizeof(newStudent->lastName) - 1] = '\0';

        //newStudent->id = rand() % 10000; //create incrimenting IDs?
	//if ()
	
	newStudent->id = 3000 + i;
        newStudent->gpa = static_cast<float>(rand() % 5); // gpa between 0 and 4.00 (convert rand into a float)

	//cout << newStudent->firstName << endl;
	//cout << newStudent->id << endl;
        hashTable->insertItem(newStudent->id,newStudent);
    }
}
