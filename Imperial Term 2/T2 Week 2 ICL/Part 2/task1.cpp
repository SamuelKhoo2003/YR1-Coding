#include <iostream>
 
struct IntListNode{
    int val;
    IntListNode* next;
};
 
// each node of the list has two fields:
// val to hold a value in the node
// next to point to the next node (or to NULL)
 
int main(){
    IntListNode* l;
    // (this is a lowercase L not a 1)
    l = NULL; 
    // empty list
    // has no nodes, just points to NULL
 
    // we add a new node at the beginning of the list:
 
    IntListNode* tmp;
 
    tmp = new IntListNode;
    (*tmp).val = 2;
    // we dereference the pointer to the node with *
    // then access the val field of the node with .val
 
    (*tmp).next = l;
 
 
    l = tmp;
 
    // now l points to the node containing 
    // which in turn points to NULL 
 
    // we add another one:
 
    tmp = new IntListNode;
    (*tmp).val = 3;
    (*tmp).next = l;
 
    l = tmp;
 
    // now list l points to the node containing 3
    // which in turn points to the node containing 2
    // which in turn points to NULL
 
    // we can go through the list 
    // printing the content of each node 
    // and stop when the NULL termination is found
 
    IntListNode* lit;
    lit = l;
 
    while(lit != NULL){
        std::cout << (*lit).val << std::endl;
        lit = (*lit).next;
    }
 
    // finally we deallocate the list
 
    lit = l;
 
    while(lit != NULL){
        tmp = (*lit).next;
        delete lit;
        lit = tmp;
    }
}