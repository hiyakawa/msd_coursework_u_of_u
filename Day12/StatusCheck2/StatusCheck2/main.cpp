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
    
    // Part 3 a
    // Q: What is the difference between an array and a structure?
    // A: Stuctures hold member variables.
    // Q: What is the difference between an array and a vector?
    // A: Vectors have member functions like push_back().
    
    // Part 3 b
    Dog my_dog = {"Milou", 5, false};
    
    // Part 3 c
    vector<Dog> dogs = {};
    
    // Part 4
    cout << parseFile("/Users/laurazhang/myLocalGithubRepo/Day12/star_wars.txt") << endl;
    
    return 0;
}
