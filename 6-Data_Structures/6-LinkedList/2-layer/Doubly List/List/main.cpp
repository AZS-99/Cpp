//
//  main.cpp
//  3-LinkedList
//
//  Created by Adam Saher on 2021-03-18.
//

#include <list>
#include "list.h"


int main(int argc, const char * argv[]) {
    auto stdlist = std::list<int>();
    stdlist = {1};
    stdlist.front() = 2;
    std::cout << stdlist.front() << std::endl;
    stdlist.push_back(3);
    stdlist.push_back(4);
    stdlist.push_back(5);
    
    auto it = stdlist.begin();
    auto end = stdlist.end();
    auto end1 = end;
    std::cout << "value of end: " << *end << std::endl;
    std::cout << "end = end1? " << (end == end1? true : false) << std::endl;
    auto j = 0u;
    while (j < 14) {
        std::cout << "iterator == end: " << (it == end) << std::endl;
        std::cout << "iterator's value: " << *it << std::endl;
        ++it;
        ++j;
    }
    
    
    
    
    auto list = List<int>();
    std::cout << (list.empty()? "is empty" : "not empty") << std::endl;
    list.push_back(2);
    list.push_back(2);
    list.front() = 1;
    list.push_front(0);
    list.push_front(-1);// [-1, 0, 1, 2];
    
    
    auto it1 = list.cbegin();
    auto k = 0u;
    while (k < 14) {
        std::cout << "my iterator's value: " << *(it1++) << std::endl;
        ++k;
    }
    
    
    
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.print(std::cout);
}
