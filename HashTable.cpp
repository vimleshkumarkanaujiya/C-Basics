#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myHashTable;

    // Inserting key-value pairs into the hash table
    myHashTable["Alice"] = 25;
    myHashTable["Bob"] = 30;
    myHashTable["Charlie"] = 35;

    // Accessing values using keys
    std::cout << "Age of Bob: " << myHashTable["Bob"] << std::endl; // Output: 30

    // Modifying values using keys
    myHashTable["Alice"] = 26;
    std::cout << "Updated age of Alice: " << myHashTable["Alice"] << std::endl; // Output: 26

    // Checking if a key exists in the hash table
    if (myHashTable.count("Charlie") > 0) {
        std::cout << "Charlie is in the hash table." << std::endl;
    }

    // Iterating over the key-value pairs in the hash table
    std::cout << "Key-Value pairs in the hash table:" << std::endl;
    for (const auto& pair : myHashTable) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
