#include <iostream>
#include <iomanip>

#include "LinkedList.h"
#include "Node.h"

int main() {
  using martineausw::dsa::LinkedList;

  LinkedList<int> llist {1}; 

  auto print_llist = [&] () { 
    std::cout << "length: " << llist.get_length() << '\n';
    for (int i {}; i < llist.get_length(); ++i) 
      std::cout << "  " << i << ": " << llist.at(i) << '\n';
  };

  llist.prepend(0);
  llist.append(3);
  llist.append(4);

  llist.insert(2, 2);
  llist.remove_first();
  llist.remove_last();
  llist.remove(1);
  std::cout << std::boolalpha;
  std::cout << "contains 3? " << llist.contains(3) << '\n';

  print_llist();

  return 0;
}