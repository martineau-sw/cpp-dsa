#include <iostream>
#include <iomanip>

#include "LinkedList.h"
#include "Node.h"

int main() {
  using martineausw::dsa::LinkedList;

  LinkedList<int> llist {5}; 

  std::cout << llist.head->value;

  llist.append(6);

  std::cout << llist.head->next->value;

  int key = 6;
  auto found = llist.find(6);

  std::cout << std::boolalpha;
  std::cout << key << " is in list: " << (found.value == key) << std::endl;

  return 0;
}