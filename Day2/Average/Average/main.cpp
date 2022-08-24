//
//  main.cpp
//  Average
//
//  Created by Reshma Raghavan on 8/23/22.
//  Group members: Laura Zhang and Reshma Raghavan
//  This is a program to calculate the average of a number of values
//  in this case, it is used to calculate the average of grades

#include <iostream>

int main(int argc, const char * argv[])
{
    int assignmentScore1; int assignmentScore2; int assignmentScore3;
    int assignmentScore4; int assignmentScore5;
    std::cout << "Enter five assignment scores: " << std::endl;
    
    std::cin >> assignmentScore1;
    std::cin >> assignmentScore2;
    std::cin >> assignmentScore3;
    std::cin >> assignmentScore4;
    std::cin >> assignmentScore5;

    int totalScore = assignmentScore1 + assignmentScore2 + assignmentScore3 + assignmentScore4 + assignmentScore5;
    
    float scoreAverage = totalScore / 5.0;
    
    std::cout << "The average score of the five assignments is " << scoreAverage << std::endl;
    
    return 0;
}
