#include <iostream>

const int MAX_SIZE = 100;

class Stack {
  private: int arr[MAX_SIZE];
  int top;

  public: Stack() {
    top = -1; // Initialize top as -1 to indicate an empty stack
  }

  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return top == MAX_SIZE - 1;
  }

  void push(int value) {
    if (isFull()) {
      std::cout << "Stack Overflow: Cannot push element, stack is full." << std::endl;
      return;
    }
    arr[++top] = value;
    std::cout << "Pushed " << value << " onto the stack." << std::endl;
  }

  void pop() {
    if (isEmpty()) {
      std::cout << "Stack Underflow: Cannot pop element, stack is empty." << std::endl;
      return;
    }
    int value = arr[top--];
    std::cout << "Popped " << value << " from the stack." << std::endl;
  }

  int peek() {
    if (isEmpty()) {
      std::cout << "Stack is empty." << std::endl;
      return -1;
    }
    return arr[top];
  }
};

int main() {
  Stack myStack;

  myStack.push(5);
  myStack.push(10);
  myStack.push(15);

  std::cout << "Top element: " << myStack.peek() << std::endl; // Output: 15

  myStack.pop();
  myStack.pop();

  std::cout << "Top element: " << myStack.peek() << std::endl; // Output: 5

  myStack.pop();
  myStack.pop(); // Trying to pop from an empty stack

  return 0;
}
