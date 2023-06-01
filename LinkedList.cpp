#include <iostream>

// Node class representing a single node in the linked list
class Node {
  public: int data;
  Node * next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

// LinkedList class representing the linked list
class LinkedList {
  private: Node * head;

  public: LinkedList() {
      head = nullptr;
    }

    ~LinkedList() {
      // Destructor to deallocate memory when the linked list is destroyed
      Node * current = head;
      while (current != nullptr) {
        Node * temp = current;
        current = current -> next;
        delete temp;
      }
    }

  void insert(int value) {
    Node * newNode = new Node(value);
    if (head == nullptr) {
      // Insertion into an empty list
      head = newNode;
    } else {
      // Insertion at the end of the list
      Node * current = head;
      while (current -> next != nullptr) {
        current = current -> next;
      }
      current -> next = newNode;
    }
  }

  void remove(int value) {
    if (head == nullptr) {
      // Empty list
      return;
    }

    if (head -> data == value) {
      // Removal of the first element
      Node * temp = head;
      head = head -> next;
      delete temp;
    } else {
      // Removal of a non-first element
      Node * current = head;
      while (current -> next != nullptr && current -> next -> data != value) {
        current = current -> next;
      }

      if (current -> next != nullptr) {
        Node * temp = current -> next;
        current -> next = current -> next -> next;
        delete temp;
      }
    }
  }

  void display() {
    Node * current = head;
    while (current != nullptr) {
      std::cout << current -> data << " ";
      current = current -> next;
    }
    std::cout << std::endl;
  }
};

int main() {
  LinkedList myList;

  myList.insert(5);
  myList.insert(10);
  myList.insert(15);

  myList.display(); // Output: 5 10 15

  myList.remove(10);

  myList.display(); // Output: 5 15

  return 0;
}
