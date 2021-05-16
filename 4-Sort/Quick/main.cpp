#include <iostream>
#include "quick.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    int array[] = {3, 2, 1, 5, 8};
    quick_sort(array, sizeof(array)/sizeof(int));

    for(auto& element : array)
        std::cout << element << std::endl;
    return 0;
}
