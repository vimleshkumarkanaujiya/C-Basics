#include <iostream>
#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            if (currentNode->children.find(c) == currentNode->children.end()) {
                currentNode->children[c] = new TrieNode();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->isEndOfWord = true;
    }

    // Function to search for a word in the Trie
    bool search(const std::string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            if (currentNode->children.find(c) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[c];
        }
        return currentNode->isEndOfWord;
    }

    // Function to check if a prefix exists in the Trie
    bool startsWith(const std::string& prefix) {
        TrieNode* currentNode = root;
        for (char c : prefix) {
            if (currentNode->children.find(c) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[c];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("application");
    trie.insert("apply");
    trie.insert("banana");

    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << std::endl;  // Output: Found
    std::cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << std::endl;  // Output: Not Found

    std::cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << std::endl;  // Output: Yes
    std::cout << "Starts with 'ban': " << (trie.startsWith("ban") ? "Yes" : "No") << std::endl;  // Output: Yes
    std::cout << "Starts with 'ball': " << (trie.startsWith("ball") ? "Yes" : "No") << std::endl;  // Output: No

    return 0;
}
