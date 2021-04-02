//
//  main.cpp
//  Files
//
//  Created by Adam Saher on 2021-03-28.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "file.hpp"

int main(int argc, const char * argv[]) {
    std::fstream file1(argv[1]); //fstream takes a string (filename) as an argument, which is stored in argv[1] in this case (check ReadMe)
    if (!file1)
        std::cout << "Failed to open file" << std::endl;
    std::string line;
    
    float x, y;
    
    auto i = 0u;
    std::stringstream ss;
    while (getline(file1, line)) {
        std::cout << line << std::endl;
        ss << line;   //Enter the line to ss in order to be processed.
        ss >> x >> y; //Stringstream converts the string into the type of the variable we are passing the value to.
        std::cout << "X + 1: " << x + 1 << ", Y + 2: " << y + 2 << std::endl;
        ++i;
    }

    std::cout << "No. of lines: " << i << std::endl;
    
    file1.clear();
    //After reaching EOF, the fstream sets flags to prevent further handling. You need to clear those flags to continue using the fstream.
    
    
    std::cout << "No of chars: " << count_chars(file1) << std::endl;
    file1.close();
    
    return 0;
}
