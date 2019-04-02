//
//  Quick_sort.h
//  Quick_sort
//
//  Created by Adam Saher on 02/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Quick_sort_h
#define Quick_sort_h

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
void quick_sort(T* arr, unsigned size) {
    if (size < 2)
        return;
    
    unsigned pivot_index = size/2;
    T* pivot = arr + pivot_index;
    T* left = arr;
    T* right = arr + size - 1;
    bool both_sides_unordered = true;
    
    //There are values on the left of the pivot that are greater that *pivot, and vice-versa with the right side
    //Keep swapping those values from the left and the right till at least one side is in order
    while (both_sides_unordered) {
        while (left < pivot && *left < *pivot) ++left;
        while (right > pivot && *right > *pivot) --right;
        
        if (!(left == pivot || right == pivot))
            std::swap(*left, *right);
        else
            both_sides_unordered = false;
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
#endif /* Quick_sort_h */
