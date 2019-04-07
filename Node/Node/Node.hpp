//
//  Node.hpp
//  Node
//
//  Created by Adam Saher on 06/04/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <typename T>
class Node {
    T data_;
    Node* right_;
    Node* left_;
public:
    Node(T data = T{}, Node* left = nullptr, Node* right = nullptr);
};
#endif /* Node_hpp */
