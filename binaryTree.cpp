#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    // Private helper function for inserting a node recursively
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }
        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        }
        else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }
        return current;
    }

    // Private helper function for searching a node recursively
    bool searchRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return false;
        }
        if (value == current->data) {
            return true;
        }
        if (value < current->data) {
            return searchRecursive(current->left, value);
        }
        else {
            return searchRecursive(current->right, value);
        }
    }

    // Private helper function for printing the tree in-order
    void printInOrderRecursive(TreeNode* current) {
        if (current != nullptr) {
            printInOrderRecursive(current->left);
            std::cout << current->data << " ";
            printInOrderRecursive(current->right);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    // Public function to insert a value into the binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Public function to search for a value in the binary tree
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Public function to print the binary tree in-order
    void printInOrder() {
        printInOrderRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.printInOrder(); // Output: 2 3 4 5 6 7 8

    std::cout << "Search 6: " << (tree.search(6) ? "Found" : "Not Found") << std::endl; // Output: Found
    std::cout << "Search 9: " << (tree.search(9) ? "Found" : "Not Found") << std::endl; // Output: Not Found

    return 0;
}
