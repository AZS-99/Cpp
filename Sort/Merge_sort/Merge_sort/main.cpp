//
//  main.cpp
//  Merge_sort
//
//  Created by Adam Saher on 15/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "Merge.h"

int main(int argc, const char * argv[]) {
    int array[] = {5, 3, 2, 1, 9, 10};
    merge_sort(array, sizeof(array)/sizeof(array[0]));
    
    std::cout << "Array after merge sort: ";
    for (unsigned i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
        std::cout << array[i] << " ";
    return 0;
}
