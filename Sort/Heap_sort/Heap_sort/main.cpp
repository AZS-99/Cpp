//
//  main.cpp
//  Heap_sort
//
//  Created by Adam Saher on 30/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "Heap_sort.h"

int main(int argc, const char * argv[]) {
    int arr[] = {3, 4, 7, 9, 6, 10, 11, 20, 1};
    heap_sort(arr, sizeof(arr)/sizeof(arr[0]));
    
    for (unsigned i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    int arr2[100000];
    for(unsigned int i=0;i<100000;i++){
        arr2[i]=rand();
    }
    
    heap_sort(arr2, 100000);
    for(unsigned int i =0 ;i < 100000-1;i++){
        if(arr2[i] > arr2[i+1]){
            std::cout << "arr[" << i << "] = " << arr2[i] << std::endl;
            std::cout << "arr[" << i+1 << "] = " << arr2[i+1] << std::endl;
            std::cout << "bug" << std::endl;
        }
    }
    
    return 0;
}
