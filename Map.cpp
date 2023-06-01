#include <iostream>

#include <map>

int main() {
  std::map < std::string, int > myMap;

  // Inserting key-value pairs into the map
  myMap["Alice"] = 25;
  myMap["Bob"] = 30;
  myMap["Charlie"] = 35;

  // Accessing values using keys
  std::cout << "Age of Bob: " << myMap["Bob"] << std::endl; // Output: 30

  // Modifying values using keys
  myMap["Alice"] = 26;
  std::cout << "Updated age of Alice: " << myMap["Alice"] << std::endl; // Output: 26

  // Checking if a key exists in the map
  if (myMap.count("Charlie") > 0) {
    std::cout << "Charlie is in the map." << std::endl;
  }

  // Iterating over the key-value pairs in the map
  std::cout << "Key-Value pairs in the map:" << std::endl;
  for (const auto & pair: myMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}
