//
//  NumberRepresentations.cpp
//  NumberRepresentations
//
//  Created by Laura Zhang on 9/7/22.
//

#include "NumberRepresentations.hpp"

#include <cmath>

using namespace std;

bool approxEquals(double a, double b, double tolerance) {
    double difference = abs(a - b);
    return (difference <= tolerance);
}
