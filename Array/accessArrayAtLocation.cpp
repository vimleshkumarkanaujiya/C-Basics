#include <iostream>
using namespace std;

int main(){

// Initialise an array of elements of a given size.  
int data[6] = {1, 2, 3, 4, 5, 6};
  
// Print the element by accesing the locaton of given array 
std::cout << *(data+3);
  
return 0;
}
