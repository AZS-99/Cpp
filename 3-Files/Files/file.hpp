//
//  file.hpp
//  Files
//
//  Created by Adam Saher on 2021-03-28.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>
#include <fstream>
#include <istream>

long count_chars (std::fstream& file);
unsigned count_lines(std::fstream& file);

#endif /* file_hpp */
