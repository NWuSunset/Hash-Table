#include "Node.h"
Node::Node(int data) {
  student->id = data;
}

Node::Node(Student* student) {
  this->student = student;
}

Node::~Node() {
  delete student;
}
