//
//  TemplatizedVector.cpp
//  TemplatizedVector
//
//  Created by Laura Zhang on 9/16/22.
//

#include "TemplatizedVector.hpp"

#include <iostream>

// overload operator=
MyVector& MyVector::operator=(const MyVector& rhs) {
    // if the two arrays have the same address, skip the copying
    if (this == & rhs) {
        return * this;
    }
    
    // do a deep copy
    _size = rhs._size;
    _capacity = rhs._size;
    
    for (size_t i = 0; i < _size; i++) {
        _data[i] = rhs._data[i];
    }
    
    return * this;
}

// overload operator[] as a const method (get method)
int MyVector::operator[](const size_t& index) const {
    if (index < _size) {
        return _data[index];
    }
    
    else {
        std::cerr << "Index is beyond range!" << std::endl;
        exit(IndexBeyondRange);
    }
}

// overload operator[] (set method)
int& MyVector::operator[](const size_t& index) {
    if (index < _size) {
        return _data[index];
    }
    
    else {
        std::cerr << "Index is beyond range!" << std::endl;
        exit(IndexBeyondRange);
    }
}

// overload operator==
// must have the same size and the same values for at each position
bool MyVector::operator==(const MyVector& rhs) const {
    if (_size == rhs._size) {
        for (size_t i = 0; i < _size; i++) {
            if (_data[i] != rhs._data[i]) {
                return false;
            }
        }
    }
    
    else {
        return false;
    }
    
    return true;
}

// overload operator!=
bool MyVector::operator!=(const MyVector& rhs) const {
    return ! operator==(rhs);
}

// overload operator<
bool MyVector::operator<(const MyVector& rhs) const {
    if (_size == rhs._size) {
        for (size_t i = 0; i < _size; i++) {
            if (_data[i] > rhs._data[i]) {
                return false;
            }
            
            else if (_data[i] < rhs._data[i]) {
                return true;
            }
        }
    }
    
    return false;
}

// overload operator<=
bool MyVector::operator<=(const MyVector& rhs) const {
    return (operator==(rhs) || operator<(rhs));
}

// overload operator>
bool MyVector::operator>(const MyVector& rhs) const {
    return ! operator<=(rhs);
}

// overload operator>=
bool MyVector::operator>=(const MyVector& rhs) const {
    return ! operator<(rhs);
}

// return the appropriate value in the vector
int MyVector::get(const size_t& index) const {
    if (index < _size) {
        return _data[index];
    }
    
    else {
        std::cerr << "Index is beyond range!" << std::endl;
        return IndexBeyondRange;
    }
}

void MyVector::set(const size_t& index, const int& newValue) {
    _data[index] = newValue;
}

void MyVector::pushBack(const int& newElement) {
    // make sure the capacity is enough for inserting an element
    growVector();
    
    // insert the new element
    _data[_size] = newElement;
    _size ++;
}

void MyVector::popBack() {
    _size --;
}

void MyVector::growVector() {
    // allocate memory for a temporary array with twice the size
    if (_size >= _capacity) {
        int* temp_array = new int [_size * 2];
        
        // copy the contents to this temp array
        for (int i = 0; i < _size; i++) {
            temp_array[i] = _data[i];
        }
        
        _capacity *= 2;

        // free up the old chunk of memory
        delete [] _data;

        _data = temp_array;

        // set the pointer to the temp array to nullptr
        temp_array = nullptr;
    }
}

size_t MyVector::getSize() const {
    return _size;
}

size_t MyVector::getCapacity() const {
    return _capacity;
}
