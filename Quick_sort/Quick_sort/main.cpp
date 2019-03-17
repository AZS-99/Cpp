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
    
    unsigned pivot_index = size/2;
    int* pivot = arr + pivot_index;
    int* left = arr;
    int* right = arr + size - 1;
    
    while(left != pivot || right != pivot) {
        while (*left < *pivot) ++left;
        while (*right > *pivot) --right;
        std::cout << "left: " << *left << ", right:" << *right << ", pivot: " << *pivot << std::endl;
        
        std::swap(*left, *right);
        ++left;
        --right;
        std::cout << "left: " << *left << ", right:" << *right << ", pivot: " << *pivot << std::endl;
        std::cout << (left == pivot ? "left = pivot" : "left != pivot") << std::endl;
        std::cout << "======================" << std::endl;
    }
    
    
    quick_sort(arr, pivot_index);
    quick_sort(pivot + 1, size - pivot_index - 1);
}


int main(int argc, const char * argv[]) {
    int simple_array[] = {2, 6, 1, 4, 8, 10, 9, 3, 5};
    quick_sort(simple_array, sizeof(simple_array)/sizeof(int));
    for (unsigned i = 0; i < sizeof(simple_array)/sizeof(int);++ i)
        std::cout << simple_array[i] << ", ";
    std::cout << std::endl << "======================" << std::endl;
    int arr[10000];
    for(unsigned int i=0;i<10000;i++){
        arr[i]=rand();
    }
//    quick_sort(arr, 10000);
//    for(unsigned int i =0 ;i < 10000-1;i++){
//        if(arr[i] > arr[i+1]){
//            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
//            std::cout << "arr[" << i+1 << "] = " << arr[i+1] << std::endl;
//            std::cout << "bug" << std::endl;
//        }
//    }
    return 0;
}
