//
//  main.cpp
//  print
//
//  Created by Adam Saher on 2021-04-02.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Hello, world!" << std::endl;  //std::endl resolves to the end-line of the OS: \n, \r\n, or \r
    
    double x(10000);
    std::cout.width(10); //Width determines the MIN with for the NEXT OUTPUT ONLY
    std::cout <<  x << std::endl;
    std::cout <<  x << std::endl; //Not affected by cout.width
    
    
    std::cout.width(10);
    std::cout.fill('x'); // Set the padding char
    std::cout << x << std::endl;
    
    x += 0.123456789;
    std::cout.setf(std::ios::scientific);
    std::cout << x << std::endl;
    std::cout.unsetf(std::ios::scientific); // Unlike cout.width, cout.set persists until turned off.
    
    std::cout.setf(std::ios::fixed);// Fixed forces printing with readable decimal, use fixed.
    std::cout << x << std::endl;
    
    std::cout.precision(3);
    std::cout << x << std::endl;
    
    return 0;
}
