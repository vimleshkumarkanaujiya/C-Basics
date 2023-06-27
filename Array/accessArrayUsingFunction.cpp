#include <iostream>

using namespace std;

void printArray(int * data, int len) {

  for (int i = 0; i < len; i++) {

    cout << data[i] << endl;

  }

}

int main() {

  int data[6] = {
    1,
    2,
    3,
    4,
    5,
    6
  };

  printArray(data, 6);

  return 0;

}
