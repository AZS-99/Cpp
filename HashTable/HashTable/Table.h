//
//  Table.h
//  HashTable
//
//  Created by Adam Saher on 07/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Table_h
#define Table_h
#include <string>

template <typename T>
class Table {
    Table(){};
    virtual void update(std::string& key, T& value) = 0;
    virtual void remove(std::string& key) = 0;
    virtual void find(std::string& key) = 0;
    ~Table(){};
};
#endif /* Table_h */
