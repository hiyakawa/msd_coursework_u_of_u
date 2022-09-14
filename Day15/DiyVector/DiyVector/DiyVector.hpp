//
//  DiyVector.hpp
//  DiyVector
//
//  Created by Laura Zhang on 9/13/22.
//

#ifndef DiyVector_hpp
#define DiyVector_hpp

#include <cstddef>

class MyVector {
private:
    int* _data;
    size_t _capacity, _size;
    
public:
    MyVector();
    MyVector(size_t initialCapacity);
    
    int get(size_t index) const;
    void set(size_t index, int newValue);
    
    void pushBack(const int& newElement);
    void popBack();
    
    void growVector();
    void freeVector();
    
    size_t getSize();
    size_t getCapacity();
};

enum Cases {
    IndexBeyondRange = -1,
};

#endif /* DiyVector_hpp */
