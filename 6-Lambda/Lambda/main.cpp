//
//  main.cpp
//  Lambda
//
//  Created by Adam Saher on 2021-03-29.
//

#include <iostream>
#include <fstream>
#include "data_table.hpp"

int main(int argc, const char * argv[]) {
    std::fstream file(argv[1]);
    DataTable data_table(file);
    std::cout << "mean: " << data_table.mean() << std::endl;
    std::cout << "median: " << data_table.median() << std::endl;
    return 0;
}
