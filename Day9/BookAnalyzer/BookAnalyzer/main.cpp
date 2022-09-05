//
//  main.cpp
//  BookAnalyzer
//
//  Created by Laura Zhang on 9/1/22.
//

#include "BookAnalyzer.h"

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    const char* file_name = argv[1];
    // "/Users/laurazhang/myLocalGithubRepo/Day9/BookAnalyzer/BookAnalyzer/books/pg47127.txt"
    
    string err_message = "";
    
    switch (parseFile(file_name, "The")) {
        case WrongFileName:
            err_message = "This file does not exist!";
            return error_message(file_name, err_message, WrongFileName);
            
        case OpenFailed:
            err_message = "File open failed!";
            return error_message(file_name, err_message, OpenFailed);
            
        case Success:
            return Success;
    }
}
