#include <iostream>

const int MAX_SIZE = 100;

class Queue {
  private: int arr[MAX_SIZE];
  int front;
  int rear;

  public: Queue() {
    front = -1; // Initialize front as -1 to indicate an empty queue
    rear = -1; // Initialize rear as -1 to indicate an empty queue
  }

  bool isEmpty() {
    return front == -1 && rear == -1;
  }

  bool isFull() {
    return rear == MAX_SIZE - 1;
  }

  void enqueue(int value) {
    if (isFull()) {
      std::cout << "Queue Overflow: Cannot enqueue element, queue is full." << std::endl;
      return;
    } else if (isEmpty()) {
      front = 0; // When adding the first element, update front to 0
    }
    arr[++rear] = value;
    std::cout << "Enqueued " << value << " into the queue." << std::endl;
  }

  void dequeue() {
    if (isEmpty()) {
      std::cout << "Queue Underflow: Cannot dequeue element, queue is empty." << std::endl;
      return;
    } else if (front == rear) {
      // When dequeuing the last element, reset front and rear to -1 to indicate an empty queue
      front = -1;
      rear = -1;
    } else {
      std::cout << "Dequeued " << arr[front++] << " from the queue." << std::endl;
    }
  }

  int peek() {
    if (isEmpty()) {
      std::cout << "Queue is empty." << std::endl;
      return -1;
    }
    return arr[front];
  }
};

int main() {
  Queue myQueue;

  myQueue.enqueue(5);
  myQueue.enqueue(10);
  myQueue.enqueue(15);

  std::cout << "Front element: " << myQueue.peek() << std::endl; // Output: 5

  myQueue.dequeue();
  myQueue.dequeue();

  std::cout << "Front element: " << myQueue.peek() << std::endl; // Output: 15

  myQueue.dequeue();
  myQueue.dequeue(); // Trying to dequeue from an empty queue

  return 0;
}
