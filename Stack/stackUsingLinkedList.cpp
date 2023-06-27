#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

class Stack {
private:
  Node *top;

public:
  Stack() {
    top = NULL;
  }

  void push(int element) {
    Node *newNode = new Node(element);
    newNode->next = top;
    top = newNode;
  }

  int pop() {
    int element = top->data;
    top = top->next;
    return element;
  }

  bool isEmpty() {
    return top == NULL;
  }
};

int main() {
  Stack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;

  return 0;
}
