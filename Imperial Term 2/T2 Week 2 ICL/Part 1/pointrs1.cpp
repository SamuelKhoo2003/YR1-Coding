#include <iostream>
 
int main(){
    int a;
    int* pi; 
    // this declares pi as a pointer to int
    // which means that pi can be used to store the address
    // of a memory location of type int
 
    pi = &a;
 
    std::cout << &a << std::endl;
    std::cout << pi << std::endl;
 
    // the two values printed will be the same
}

// "pi" is the pointer, where it can be used to store the address of a