//
//  main.cpp
//  3-Array
//
//  Created by Adam Saher on 2021-05-14.
//

#include <iostream>
#include "array.h"

int main(int argc, const char * argv[]) {
    int array[] = {1, 2, 3, 6, 7};
    std::cout << all_elements_unique(array, sizeof(array)/sizeof(int)) << std::endl;
    
    
    return 0;
}
