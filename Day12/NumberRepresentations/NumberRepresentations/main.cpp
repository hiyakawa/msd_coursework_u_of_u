//
//  main.cpp
//  NumberRepresentations
//
//  Created by Laura Zhang on 9/7/22.
//

#include "NumberRepresentations.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double point_one = 0.1;
    double point_two = 0.2;
    double point_three = 0.3;
    double point_one_plus_two = point_one + point_two;
    
    cout << setprecision(18) << point_one_plus_two << endl;     //print numbers to 18 digits of accuracy
    cout << setprecision(18) << point_three << endl;
    
    // assert(point_one + point_two == point_three);
    
    // test approxEquals()
    
    approxEquals(point_one_plus_two, point_three, )
    
    return 0;
}
