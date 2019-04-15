//
//  Heap_sort.h
//  Heap_sort
//
//  Created by Adam Saher on 15/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Heap_sort_h
#define Heap_sort_h

template <typename T>
void heapify(T* array, const unsigned& size, const unsigned& subarray_global_index) {
    if (size < 2)
        return;
    
    unsigned global_left_child_index = 2 * subarray_global_index + 1;
    unsigned global_right_child_index = 2 * subarray_global_index + 2;
    
    unsigned relative_left_child_index = global_left_child_index - subarray_global_index;
    unsigned relative_right_child_index = global_right_child_index - subarray_global_index;
    

    if (relative_left_child_index < size)
        heapify(array + relative_left_child_index, size - relative_left_child_index, global_left_child_index);

    if (relative_right_child_index < size)
        heapify(array + relative_right_child_index, size - relative_right_child_index, global_right_child_index);

    if (relative_left_child_index < size && *array < *(array + relative_left_child_index))
        std::swap(*array, *(array + relative_left_child_index));

    if (relative_right_child_index < size && *array < *(array + relative_right_child_index))
        std::swap(*array, *(array + relative_right_child_index));

}


template <typename T>
void heap_sort(T* array, const unsigned& size) {
    for (unsigned i = 0; i < size; ++i) {
        heapify(array, size - i, 0);
        std::swap(*array, *(array + size - 1 - i));
    }
}
    
    
    
    
//    if (left_child_index < size - 1)
//        heapify(array + left_child_index - index, size - left_child_index, left_child_index);
//
//    if (right_child_index < size - 1)
//        heapify(array + right_child_index - index, size - right_child_index, right_child_index);
//
//    if (left_child_index < size - 1 && *array < *(array + left_child_index))
//        std::swap(*array, *(array + right_child_index));
//
//    if (right_child_index < size - 1 && *array < *(array + right_child_index))
//        std::swap(*array, *(array + right_child_index));







//bool is_even(unsigned num) {
//    return num % 2 == 0;
//}


//template <typename T>
//void heapify(T* arr, unsigned size) {
//    unsigned j;
//    bool bubbled;
//    for (unsigned i = size - 1; i > 0; --i) {
//        j = i;
//        bubbled = false;
//        while (j > 0 && !bubbled) {
//            //if right node
//            if (is_even(j)) {
//                if (arr[j] > arr[(j - 2) / 2]) {
//                    std::swap(arr[j], arr[(j - 2) / 2]);
//                    j = (j - 2) / 2;
//                }
//                else
//                    bubbled = true;
//            }
//            //if left node
//            else {
//                if (arr[j] > arr[(j - 1) / 2]) {
//                    std::swap(arr[j], arr[(j - 1) / 2]);
//                    j = (j - 1) / 2;
//                }
//                else
//                    bubbled = true;
//            }
//        }
//    }
//}


#endif /* Heap_sort_h */
