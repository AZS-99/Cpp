//
//  main.cpp
//  Heap_sort
//
//  Created by Adam Saher on 30/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>

bool is_even(unsigned num) {
    return num % 2 == 0;
}

template <typename T>
void heapify(T* arr, unsigned size) {
    unsigned j;
    bool bubbled;
    for (unsigned i = size - 1; i > 0; --i) {
        j = i;
        bubbled = false;
        while (j > 0 && !bubbled) {
            //if right node
            if (is_even(j)) {
                if (arr[j] > arr[(j - 2) / 2]) {
                    std::swap(arr[j], arr[(j - 2) / 2]);
                    j = (j - 2) / 2;
                }
                else
                    bubbled = true;
            }
            //if left node
            else {
                if (arr[j] > arr[(j - 1) / 2]) {
                    std::swap(arr[j], arr[(j - 1) / 2]);
                    j = (j - 1) / 2;
                }
                else
                    bubbled = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {3, 4, 7, 0, 5, 20, 30, 10, 2, 50, 40};
    heapify(arr, sizeof(arr)/sizeof(arr[0]));
    
    for (unsigned i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
