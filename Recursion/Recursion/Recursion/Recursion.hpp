//
//  Recursion.hpp
//  Recursion
//
//  Created by Adam Saher on 27/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Recursion_hpp
#define Recursion_hpp

#include <stdio.h>

/**
 Return whether the passed string is a palindrome

 @param str cstring
 @return True if the passed string is a palindrome, false otherwise.
 */
bool isPalindrome (const char* str);


/**
 Return the sum of numbers from 0 till n

 @param n A whole number
 @return $\sum $
 */
unsigned summation(unsigned n);



/**
 Return the sum of all digits in the passed number

 @param n A whole number
 @return summation of all digits. sum_of_digits(12) returns 3
 */
unsigned sum_of_digits(unsigned n);
#endif /* Recursion_hpp */
