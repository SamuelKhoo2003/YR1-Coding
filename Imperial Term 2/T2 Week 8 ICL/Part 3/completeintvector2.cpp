#include <iostream>
 
class intvector{
 
public:
 
    // constructor
    intvector(){
        m_size = 0;
        // initially no elements, size is 0
 
        m_capacity = 1;
        p = new int[m_capacity];
        // we dynamically allocate 
        // an initial memory area
        // of size 1 (there is space
        // to add 1 element before
        // a reallocation is needed)
    }
 
    // like push_back in std::vector
    // same algorithm as 
    // "Reallocating dynamically allocated contiguous memory"
    // in section 11.5
    void push_back(int n){
        if (m_capacity <= m_size){
            m_capacity = m_capacity*2; 

            int* tmp_p; 
            tmp_p = new int[m_capacity]; 
            for(int i = 0; i < m_size; i++){
                tmp_p[i] = p[i];
            } 
            
            delete[]p; 

            p = tmp_p; 
 
        }

        p[m_size] = n; 
        m_size = m_size + 1; 
    }
 
    // like size() in std::vector
    int size() const {
        // TODO: implement this function
        return m_size; 
    }
 
    // like capacity() in std::vector
    int capacity() const {
        // TODO: implement this function
        return m_capacity; 
    }
 
    // return the element at index i
    // (consider how it is used in the main below)
    int at(int i) const {
        // TODO: implement this function
        if( i < 0 || i >= m_size){
            throw std::out_of_range("Index out of range"); 
        }
       return p[i]; 
    }
 
    // destructor: we need to write our own destructor
    // with a delete[] instruction that deallocates 
    // the dynamically allocated contiguous memory
 
    // we would have a memory leak otherwise because 
    // the default destructor wouldn't do this
 
    ~intvector(){
        delete[] p;
    }
 
    // copy constructor
    // (see explanation in exercise below)
 
    // we needed to use our own copy constructor as without it we wouldn't allocate new memory
    // in the case of iv1 and iv2 it would just make both use the same dynamically allocated memory area
    // this is the wrong implementation because it would cause undefined behaviour when iv1 and iv2 go out of scope and the destructor we implemented is called for them

private:
 
    int* p;
    int m_size;
    int m_capacity;
 
};
 
 
int main(){
    intvector iv1;
 
    for(int i = 0; i < 9; i++){
        iv1.push_back(i);
        // TODO: add printing instructions showing how the size and the capacity are updated
        std::cout << i << " was added" << std::endl; 
        std::cout << "size: " << iv1.size() << std::endl; 
        std::cout << "the capacity is: " << iv1.capacity() << "\n" << std::endl; 
    }

    
    std::cout << "printing iv1: " << std::endl;
 
    for(int i = 0; i < iv1.size(); i++){
        std::cout << iv1.at(i) << std::endl;
    }
 
    std::cout << std::endl;
 
    // calling the copy constructor
    intvector iv2(iv1);
 
    // calling the assignment operator
    intvector iv3 = iv1;
 
    iv1.push_back(9);
 
    std::cout << "printing iv1:" << std::endl;
 
    for(int i = 0; i < iv1.size(); i++){
        std::cout << iv1.at(i) << std::endl;
    }
 
    std::cout << std::endl;
 
    std::cout << "printing iv2:" << std::endl;
 
    for(int i = 0; i < iv2.size(); i++){
        std::cout << iv2.at(i) << std::endl;
    }
 
    std::cout << std::endl;
 
    std::cout << "printing iv3:" << std::endl;
 
    for(int i = 0; i < iv3.size(); i++){
        std::cout << iv3.at(i) << std::endl;
    }
 
    std::cout << std::endl;
 
}

