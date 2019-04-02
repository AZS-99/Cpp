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
    bool one_side_sorted = false;
    
    //There are values on the left of the pivot that are greater that *pivot, and vice-versa with the right side
    //Keep swapping those values from the left and the right till at least one side is in order
     while (!one_side_sorted) {
        while (left < pivot && *left < *pivot) ++left;
        while (right > pivot && *right > *pivot) --right;
        
        if (!(left == pivot || right == pivot))
            std::swap(*left, *right);
        else
            one_side_sorted = true;
    }
    
    //If all values on the left that are greater than *pivot have been swapped, but still there are unsorted values on right side
    if (left == pivot && right > pivot) {
        //if right happens to be the pointer just next to pivot, it'll be swapped to the latter's left; != is not enough check
        while (right > pivot) {
            std::swap(*(pivot + 1), *right);
            std::swap(*pivot, *(pivot + 1));
            ++pivot;
            ++pivot_index;
            while (right > pivot && *right > *pivot) --right;
        }
    }
    
    else if (right == pivot && left < pivot) {
        while (left < pivot) {
            std::swap(*(pivot - 1), *left);
            std::swap(*pivot, *(pivot - 1));
            --pivot;
            --pivot_index;
            while (left != pivot && *left < *pivot) ++left;
        }
    }
    
    quick_sort(arr, pivot_index);
    quick_sort(pivot + 1, size - pivot_index - 1);
}


int main(int argc, const char * argv[]) {
    int simple_array[] = {2, 6, 11, 4, 1, 8, 10, 9, 3, 5};
    quick_sort(simple_array, 10);
    std::cout<< "Sorted!" << std::endl;
    for (unsigned i = 0; i < sizeof(simple_array)/sizeof(int);++ i)
        std::cout << simple_array[i] << ", ";
    std::cout << std::endl << "======================" << std::endl;
    int arr[10000];
    for(unsigned int i=0;i<10000;i++){
        arr[i]=rand();
    }
    quick_sort(arr, 10000);
    for(unsigned int i =0 ;i < 10000-1;i++){
        if(arr[i] > arr[i+1]){
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
            std::cout << "arr[" << i+1 << "] = " << arr[i+1] << std::endl;
            std::cout << "bug" << std::endl;
        }
        else
            std::cout << "Correct!" << std::endl;
    }
    return 0;
}
