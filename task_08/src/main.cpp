#include <iostream>
#include <string>

using std::cout, std::endl;

#include "hash_table.hpp"

int main() {
  HashTable<int> ht(10);

  ht.Insert(1, 1);
  ht.Insert(2, 2);
  ht.Insert(3, 3);

  cout << "Value of '2': " << ht.GetValue(2) << endl;

  ht.RemoveByKey(3);

  try {
    cout << "Value of 'cherry': " << ht.GetValue(3) << endl;
  } catch (const std::out_of_range& e) {
    cout << e.what() << endl;
  }

  HashTable<std::string> ht2(10);
  ht2.Insert(1, "one");
  ht2.Insert(2, "two");
  ht2.Insert(3, "three");
  cout << "Value of '2': " << ht2.GetValue(2) << endl;

  return 0;
}
