//
//  Merge.h
//  Merge_sort
//
//  Created by Adam Saher on 15/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Merge_h
#define Merge_h


template <typename T>
void merge(T* array1, const unsigned& size1, T* array2, const unsigned& size2);


template <typename T>
void merge_sort(T* array, const unsigned& size) {
    if (size < 2)
        return;
    unsigned half_size = size/2;
    merge_sort(array, half_size);
    merge_sort(array + half_size, size - half_size);
    merge(array, half_size, array + half_size, size - half_size);
}



/**
 Take 2 SORTED arrays, and merge them into one sorted array.

 @param array1 A sorted array of size = size1
 @param size1 The size of array1
 @param array2 A sorted array of size = size2
 @param size2 The size of array2
 */
template <typename T> void merge(T* array1, const unsigned& size1, T* array2, const unsigned& size2) {
    auto pointer_1 = array1;
    auto pointer_2 = array2;
    
    T* tmp = new T[size1 + size2]();
    unsigned tmp_index = 0;
    
    while (pointer_1 < array2 && pointer_2 < array2 + size2) {

        if (*pointer_1 < *pointer_2) {
            tmp[tmp_index++] = *(pointer_1++);
        }
        else {
            tmp[tmp_index++] = *(pointer_2++);
        }
    }
    
    if (pointer_1 < array2) {
        while (pointer_1 < array2)
            tmp[tmp_index++] = *(pointer_1++);
    }
    else {
        while (pointer_2 < array2 + size2)
            tmp[tmp_index++] = *(pointer_2++);
    }
    
    for (unsigned i = 0; i < size1 + size2; ++i)
        array1[i] = tmp[i];
    delete[] tmp;
}

#endif /* Merge_h */
