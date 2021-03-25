//
//  main.cpp
//  Queue
//
//  Created by Adam Saher on 2021-03-24.
//

#include <iostream>
#include "Queue.h"

int main(int argc, const char * argv[]) {
    auto queue = Queue<int>();
    queue.push(10);
    std::cout << queue.peek() << std::endl;
    queue.push(11);
    std::cout << queue.peek() << std::endl;
    std::cout <<queue.pop() << std::endl;
    std::cout << queue.peek() << std::endl;
    return 0;
}
