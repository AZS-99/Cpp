//
//  main.cpp
//  tmp
//
//  Created by Adam Saher on 12/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "Quick_sort.h"


int main(int argc, const char * argv[]) {
    int simple_array[] = {2, 6, 11, 4, 1, 8, 10, 9, 3, 5};
    char char_arr[] = {'a', 't', 'b'};
    quick_sort(simple_array, 10);
    quick_sort(char_arr, 3);
    
    
    for (unsigned i = 0; i < sizeof(simple_array)/sizeof(int); ++i)
        std::cout << simple_array[i] << ", ";
    std::cout << std::endl << "======================" << std::endl;
    
    for (unsigned i = 0; i < sizeof(char_arr)/sizeof(int); ++i)
        std::cout << char_arr[i] << ", ";
    std::cout << std::endl << "======================" << std::endl;
    
    int arr[100000];
    for(unsigned int i=0;i<100000;i++){
        arr[i]=rand();
    }
    quick_sort(arr, 100000);
    for(unsigned int i =0 ;i < 100000-1;i++){
        if(arr[i] > arr[i+1]){
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
            std::cout << "arr[" << i+1 << "] = " << arr[i+1] << std::endl;
            std::cout << "bug" << std::endl;
        }
    }
    return 0;
}
