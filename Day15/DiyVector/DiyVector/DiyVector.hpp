//
//  DiyVector.hpp
//  DiyVector
//
//  Created by Laura Zhang on 9/13/22.
//

#ifndef DiyVector_hpp
#define DiyVector_hpp

#include <cstddef>

// Part 1: As a struct
struct MyVector {
private:
    int* data;
    int capacity, size;
    
public:
    MyVector makeVector(int initialCapacity);
    void freeVector(MyVector myVector);
    void pushBack(MyVector myVector, int new_element);
    void popBack(MyVector myVector);
    int get(MyVector myVector, std::size_t index) const;
    void set(MyVector myVector, std::size_t index, int newValue);
    void growVector(MyVector myVector);
};

#endif /* DiyVector_hpp */
