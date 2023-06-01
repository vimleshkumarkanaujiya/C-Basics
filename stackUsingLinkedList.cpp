#include <iostream>

using namespace std;

class Stack {
private:
  int *array;
  int size;
  int top;

public:
  Stack(int size) {
    this->size = size;
    array = new int[size];
    top = -1;
  }

  void push(int element) {
    top++;
    array[top] = element;
  }

  int pop() {
    int element = array[top];
    top--;
    return element;
  }

  bool isEmpty() {
    return top == -1;
  }
};

int main() {
  Stack stack(10);

  stack.push(1);
  stack.push(2);
  stack.push(3);

  cout << stack.pop() << endl;
  cout << stack.pop() << endl;
  cout << stack.pop() << endl;

  return 0;
}
