#ifndef STUDENTS_H
#define STUDENTS_H


#include<cstring>

struct Student { //Structure of a student
  char firstName[20];
  char lastName[20];
    int id;
    float gpa;
};

class Hash; //Forward declaration of class hash (so we don't create circular dependencies. (CHECK if this CAN BE OPTIMIZED LATER

//Function (might move this to main for ease of use)
void generateRandom(int toGenerate, Hash* hashTable); //static since it can be used without an instance of Students







#endif //STUDENTS_H
