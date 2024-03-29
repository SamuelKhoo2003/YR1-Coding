#include <iostream>
#include <vector>
 
int main(){
    std::vector<int> sequence;
    int tmp = 1;
    // initialised to anything other than 0 to enter the loop the first time
 
    std::cout << "please enter a sequence terminated by 0" << std::endl;
    while(tmp != 0){ // while the number in input is not 0...
        std::cin >> tmp; // we read a number
        sequence.push_back(tmp); // we store the number in the vector
    }
 
    std::cout << "you entered the following sequence" << std::endl;
 
    // in order to print the vector we need 
    // to print it one element at a time
    // so we need to index it
 
    // i is the variable we use in this loop for the indexing of the vector
    // it starts at 0 and increases by 1 at each iteration
    // when the index reaches the size of the vector we leave the loop
    // valid indices are 0 to (sequenze.size() - 1)
 
    for(int i = 0; i < sequence.size(); i++){
 
        std::cout << sequence[i] << std::endl;
    }
 
    std::cout << "in reverse order:" << std::endl;
 
    // this time the first value for i is 
    // the index of the last element 
    // which is at index (sequence.size() - 1)
    // i decreases by i at each iteration
    // when it reaches value 0 we need to stay in the loop
    // because 0 is still a valid index
 
    for(int i = sequence.size() - 1; i >= 0; i--){
        std::cout << sequence[i] << std::endl;
    }
 
}