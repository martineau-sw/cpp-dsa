#include <iostream>
#include <iomanip>

#include "LinkedList.h"
#include "Node.h"

int main() {
  using martineausw::dsa::LinkedList;

  LinkedList<int> llist {5}; 

  llist.prepend(4);
  llist.append(6);
  
  for (int i {}; i < 10; ++i) {
    llist.append(i);
  }

  std::cout << "length: " << llist.length << '\n';
  for (int i {}; i < llist.length; ++i) 
    std::cout << "  " << i << ": " << llist.at(i) << '\n';

  llist.at(13);

  return 0;
}