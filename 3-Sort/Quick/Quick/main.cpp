//
//  main.cpp
//  Quick
//
//  Created by Adam Saher on 2021-03-21.
//

#include <iostream>
#include "quick_sort.h"

int main(int argc, const char * argv[]) {
    int array[] = {16, 7, 10, 77, 11, 8, 9, 12, 0, 13, 14, 4, 55, 32};
    quick_sort(array, sizeof(array)/sizeof(int));
    
    for (auto& element: array)
        std::cout << element << ' ';
    std::cout << std::endl;
    
    return 0;
}
