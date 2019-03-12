//
//  main.cpp
//  tmp
//
//  Created by Adam Saher on 12/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include <cstdlib>


void quick_sort(int* arr, int size) {
    if (size < 2)
        return;
    
    if (size == 2) {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }
    
    unsigned pivot_index = size/2;
    int* pivot = arr + pivot_index;
    
    unsigned i = 0;
    for(i = 0; arr + i != pivot; ++i)
        if (arr[i] > *pivot)
            std::swap(arr[i], *pivot);
    
    while(++i < size)
        if (arr[i] < *pivot)
            std::swap(arr[i], *pivot);
    
    quick_sort(arr, pivot_index);
    quick_sort(pivot + 1, size - pivot_index - 1);
}


int main(int argc, const char * argv[]) {
    int simple_array[] = {2, 6, 1, 4, 8, 10, 9, 3, 5};
    quick_sort(simple_array, sizeof(simple_array)/sizeof(int));
    for (unsigned i = 0; i < sizeof(simple_array)/sizeof(int);++ i)
        std::cout << simple_array[i] << ", ";
    std::cout << "======================" << std::endl;
    int arr[10000];
    for(unsigned int i=0;i<10000;i++){
        arr[i]=rand();
    }
    quick_sort(arr, 10000);
    /*    for(unsigned i = 0; i < 10000; ++i){
     std::cout << arr[i] << ", ";
     if(i%30 == 29)
     std::cout << std::endl;
     }*/
    for(unsigned int i =0 ;i < 10000-1;i++){
        if(arr[i] > arr[i+1]){
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
            std::cout << "arr[" << i+1 << "] = " << arr[i+1] << std::endl;
            std::cout << "bug" << std::endl;
        }
    }
    return 0;
}
