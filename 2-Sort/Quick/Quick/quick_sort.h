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
        
        
        do {
            while(*left < *pivot) ++left;
            while(*right > *pivot) --right;
            
            if (left < pivot && right > pivot)
                std::swap(*left, *right);
        } while (left < pivot && right > pivot);
        
        T* original_pivot_value_ptr = nullptr;
        
        if (left < pivot) {
            while (left < pivot && *left < *pivot) ++left;
            original_pivot_value_ptr = left;
            
            do {
                std::swap(*left++, *pivot--);
                while(*pivot > *original_pivot_value_ptr) --pivot;
                while (*left < *original_pivot_value_ptr) ++left;
            } while(left < pivot);
            std::swap(*pivot, *original_pivot_value_ptr);
            
        } else if (right > pivot) {
            while (right > pivot && *right > *pivot) --right;
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
