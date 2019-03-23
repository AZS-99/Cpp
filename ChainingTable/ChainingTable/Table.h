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
class Table{
public:
    Table(){}
    virtual bool update(const std::string& key, const T& value) = 0;
    virtual bool remove(const std::string& key) = 0;
    virtual bool find(const std::string& key,  T& value)  = 0;
    virtual ~Table(){}
};

#include "ChainingTable.h"

#endif /* Table_h */
