//
//  file.cpp
//  Files
//
//  Created by Adam Saher on 2021-03-28.
//

#include "file.hpp"

long count_chars (std::fstream& file) {
    auto original_pos = std::ios::cur; //save the current position of the cursur
    file.seekg(0, std::ios::end); //Seekg places the cursur at the position specified at the second argument + n chars (first argument)
    long count = file.tellg();    //tellg returns the position of the cursur
    file.seekg(0, original_pos); //return the cursur to the where it was when before implementing the fn.
    return count;
}


unsigned count_lines(std::fstream& file) {
    unsigned i = 0u;
    std::string line;
    while (getline(file, line)) ++i; //Getline fn returns the whole line that comes after the curser, then moves the cursur to the next.
    return i;
}



/*
    NOTES:
    the signature of getline is:
            getline(file, string_holder, delimiter = '\n')
 */
