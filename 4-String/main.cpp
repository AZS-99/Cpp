#include <iostream>
#include <string>
#include "str.h"

int main() {
    std::string str("Hello, I am Adam");
    std::cout << truncate_n_words(str, 2) << std::endl;
    return 0;
}
