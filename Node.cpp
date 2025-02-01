#include "Node.h"

Node::Node(Student* student) {
  this->student = student;
}

Node::~Node() {
  delete student;
}
