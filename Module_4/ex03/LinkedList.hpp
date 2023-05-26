#include "AMateria.hpp"

struct Node {
  AMateria* materia;
  Node* next;
};

class LinkedList {
 private:
  Node* head;

 public:
  LinkedList();
  LinkedList(const LinkedList& rhs);
  ~LinkedList();

  LinkedList& operator=(const LinkedList& rhs);

  void add_node(AMateria *materia);
};