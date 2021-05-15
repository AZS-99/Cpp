//
//  array.h
//  3-Array
//
//  Created by Adam Saher on 2021-05-14.
//

#ifndef array_h
#define array_h


// Return whether all elements are unique
template <typename T>
bool all_elements_unique(T* array, unsigned size) {
    bool ascii[256] = {0};
    for (auto i = 0u; i < size; ++i) {
        auto index = int(array[i]);
        if (ascii[index])
            return false;
        ascii[index] = true;
    }
    return true;
}




#endif /* array_h */
