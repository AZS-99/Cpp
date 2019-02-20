//
//  main.cpp
//  Array_based
//
//  Created by Adam Saher on 19/02/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#include <iostream>
#include "Queue.h"
int main(int argc, const char * argv[]) {
    Queue<unsigned> queue;
    queue.push(10);
    queue.push(20);
    
    queue.push(30);
    queue.push(40);
    queue.push(50);
    queue.push(60);
    
    queue.push(70);
    queue.push(80);
    queue.push(90);
    for (unsigned i = 0; i < 10; ++i) {
        std::cout << queue.peek() << std::endl;
        queue.pop();
    }
    return 0;
}
