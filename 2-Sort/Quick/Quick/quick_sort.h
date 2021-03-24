//
//  quick.h
//  Quick
//
//  Created by Adam Saher on 2021-03-21.
//

#ifndef quick_h
#define quick_h


template <typename T>
void quick_sort(T* array, unsigned size) {
    if (size > 1) {
        T* pivot =  array + size/2;
        T* left = array;
        T* right = array + size - 1;
        
        //Swap values greater than pivot on the left, for values less than pivot on the right
        bool both_sides_unorganized = true;
        do {
            while(*left < *pivot) ++left;
            while(*right > *pivot) --right;
            
            if (left < pivot && right > pivot)
                std::swap(*left, *right);
            else
                both_sides_unorganized = false;
        } while (both_sides_unorganized);
        
        T* original_pivot_value_ptr = nullptr;
        // If there are values left on the left side, swap them accordingly, keeping track of the pivot's value
        if (left < pivot) {
            original_pivot_value_ptr = left;
            do {
                std::swap(*left++, *pivot--);
                while(*pivot > *original_pivot_value_ptr) --pivot;
                while (*left < *original_pivot_value_ptr) ++left;
            } while(left < pivot);
            std::swap(*pivot, *original_pivot_value_ptr);
            
        } else if (right > pivot) {
            original_pivot_value_ptr = right;
            do {
                std::swap(*right--, *pivot++);
                while (*pivot < *original_pivot_value_ptr) ++pivot;
                while (*right > *original_pivot_value_ptr) --right;
            } while (right > pivot);
            std::swap(*pivot, *original_pivot_value_ptr);
        }
        
        quick_sort(array, pivot - array);
        quick_sort(pivot + 1, array + size - 1 - pivot);
    }
}

#endif /* quick_h */
