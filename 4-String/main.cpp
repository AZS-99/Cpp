#include <iostream>
#include <string>
#include "str.h"

int main() {
    std::string str("Hello, I am Adam");
    std::cout << truncate(str, 2) << std::endl;
    return 0;
}
