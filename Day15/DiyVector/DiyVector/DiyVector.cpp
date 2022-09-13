//
//  DiyVector.cpp
//  DiyVector
//
//  Created by Laura Zhang on 9/13/22.
//

#include "DiyVector.hpp"

#include <iostream>

// Part 1: As a struct
// return a vector with the given capacity and a size of 0
MyVector MyVector::makeVector(int initialCapacity) {
    MyVector myVector;
    myVector.data = new int [0];
    myVector.size = 0;
    myVector.capacity = initialCapacity;
    
    return myVector;
}

// deallocate any heap memory used by the MyVector object
void MyVector::freeVector(MyVector MyVec) {
    
}

void MyVector::pushBack(MyVector myVector, int new_element) {
    
}

void MyVector::popBack(MyVector myVector) {
    
}

// return the appropriate value in the vector
int MyVector::get(const MyVector& myVec, std::size_t index) {
    
}

void MyVector::set(MyVector myVec, std::size_t index, int newValue) {
    
}

void MyVector::growVector(MyVector myVec) {
    
}
