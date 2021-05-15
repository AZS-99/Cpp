#include <iostream>
#include <string>
#include "str.h"

int main() {
    std::string str("Hello, I am Adam");
    std::cout << truncate(str, 10) << std::endl;
    return 0;
}
