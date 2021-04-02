/*
 Assume we have an array [6, 1, 3, 5, 2, 4]
 The idea is to split the array into two, then sort each side on its own, getting something like:
                    [1, 3, 5] and [2, 4, 6]
 then merge the both arrays into a one sorted array.
 
 Created by Adam Saher on 2021-03-23.
 */

#ifndef merge_h
#define merge_h

template <typename T>
void merge(T* array1, const unsigned& size1, T* array2, const unsigned& size2);


template <typename T>
void merge_sort(T* array, const unsigned& size) {
    if (size < 2)
        return;
    auto mid = size/2;
    merge_sort(array, mid);
    merge_sort(array + mid, size - mid);
    
    merge(array, mid, array + mid, size - mid);
}


template <typename T>
void merge(T* array1, const unsigned& size1, T* array2, const unsigned& size2) {
    auto ptr1 = array1;
    auto ptr2 = array2;
    
    T tmp[size1 + size2];
    auto tmp_idx = 0u;
    
    while (ptr1 < array2 && ptr2 < array2 + size2)
        tmp[tmp_idx++] = *ptr1 < *ptr2? *ptr1++ :  *ptr2++;
    // If there are elements left out in the first half
    while (ptr1 < array2)
        tmp[tmp_idx++] = *ptr1++;
    //If there are elements left out in the second half
    while (ptr2 < array2 + size2)
        tmp[tmp_idx++] = *ptr2++;
    
    for (auto i = 0u; i < size1 + size2; ++i)
        array1[i] = tmp[i];
}

#endif /* merge_h */
