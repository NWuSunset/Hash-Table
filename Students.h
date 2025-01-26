#ifndef STUDENTS_H
#define STUDENTS_H

#include<cstring>

struct Student { //Structure of a student
    char firstName[20];
    char lastName[20];
    int id;
    float gpa;
};

//Functions
void addStudent(Student* student);
void generateRandom(int toGenerate); //static since it can be used without an instance of Students






#endif //STUDENTS_H
