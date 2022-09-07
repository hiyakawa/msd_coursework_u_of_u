//
//  main.cpp
//  StatusCheck2
//
//  Created by Laura Zhang on 9/7/22.
//

#include "StatusCheck2.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // Part 2
    // A: Show how you would compile them (on the command line) to create myProg:
    // my_lib.h, my_lib.cpp
    // main.cpp
    // Q:
    // $ clang++ -c my_lib.cpp
    // $ clang++ -c main.cpp
    // $ clang++ -o myProg main.o my_lib.o
    // $ ./myProg
    
    // Part 3 a
    // Q: What is the difference between an array and a structure?
    // A: Stuctures can hold different types of data. Arrays contain data in the same type.
    // Q: What is the difference between an array and a vector?
    // A: Vectors do not have indexes but arrays have.
    
    // Part 3 b
    Dog my_dog = {"Milou", 5, false};
    
    // Part 3 c
    vector<Dog> dogs = {};
    
    // Part 4
    cout << parseFile("/Users/laurazhang/myLocalGithubRepo/Day12/star_wars.txt") << endl;
    
    return 0;
}
