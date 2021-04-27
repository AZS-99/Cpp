//
//  main.cpp
//  stdout
//
//  Created by Adam Saher on 2021-04-27.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int width;
    int len;
    int area;
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;
    std::cout << "Enter the len of the rectangle: ";
    std::cin >> len;
    area = width * len;
    std::cout << "Area: " << area << std::endl;
    return 0;
}
