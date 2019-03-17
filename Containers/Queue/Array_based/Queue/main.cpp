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
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    
    queue.enqueue(70);
    queue.enqueue(80);
    queue.enqueue(90);
    
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    for (unsigned i = 0; i < 15; ++i) {
        std::cout << "value: " << queue.peek() << std::endl;
        queue.dequeue();
    }
    return 0;
}
