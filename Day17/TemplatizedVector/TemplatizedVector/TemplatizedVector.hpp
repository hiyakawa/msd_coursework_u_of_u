//
//  TemplatizedVector.hpp
//  TemplatizedVector
//
//  Created by Laura Zhang on 9/16/22.
//

#ifndef TemplatizedVector_hpp
#define TemplatizedVector_hpp

#include <cstddef>

template<typename T>
class MyVector {
private:
    T* _data;
    size_t _capacity, _size;
    
public:
    MyVector();

    MyVector(const MyVector& rhs);
    
    MyVector(const size_t& initialCapacity);
    
    ~MyVector();
    
    MyVector& operator=(const MyVector& rhs);
    
    int operator[](const size_t& index) const;
    int& operator[](const size_t& index);
    
    bool operator==(const MyVector& rhs) const;
    bool operator!=(const MyVector& rhs) const;
    
    bool operator<(const MyVector& rhs) const;
    bool operator<=(const MyVector& rhs) const;
    
    bool operator>(const MyVector& rhs) const;
    bool operator>=(const MyVector& rhs) const;
    
    int get(const size_t& index) const;
    void set(const size_t& index, const int& newValue);
    
    void pushBack(const int& newElement);
    void popBack();
    
    void growVector();
    
    size_t getSize() const;
    size_t getCapacity() const;
};

MyVector<T>::MyVector() {
    _size = 0;
    _capacity = 1;
    _data = new int [_capacity];
}

MyVector<T>::MyVector(const MyVector& rhs) {
    // avoid data leak during self assignment
    if (this != & rhs) {
        _size = rhs._size;
        _capacity = rhs._capacity;
        _data = new int [_capacity];
        
        for (size_t i = 0; i < _size; i++) {
            _data[i] = rhs._data[i];
        }
    }
}

MyVector<T>::MyVector(const size_t& initialCapacity) {
    _size = 0;
    _capacity = initialCapacity;
    _data = new int [0];
}

MyVector<T>::~MyVector() {
    delete [] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

enum Cases {
    IndexBeyondRange = -1,
};

#endif /* TemplatizedVector_hpp */
