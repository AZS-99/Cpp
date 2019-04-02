//
//  ChainingTable.h
//  HashTable
//
//  Created by Adam Saher on 17/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef ChainingTable_h
#define ChainingTable_h
#include "SortedList.h"
#include "Pair.h"

template <typename T>
class ChainingTable : public Table<T> {
    SortedList<container::Pair<std::string, T>>* table_;
    unsigned size_;
    std::hash<std::string> hash_;
public:
    ChainingTable(const unsigned& size);
    ~ChainingTable();
    ChainingTable(const ChainingTable& other);
    ChainingTable& operator=(const ChainingTable&);
    ChainingTable& operator=(ChainingTable&&);
    ChainingTable(ChainingTable&& other);
    
    
    
    bool update(const std::string& key, const T& value);
    
    
    /**
     Remove the key-value pair from the table

     @param key : String that
     @return true if the key-value could be removed successfully; false otherwise.
     */
    bool remove(const std::string& key);
    
    
    /**
     Find the key-value pair that its key is equal to the one passed as an argument.
     If found, get the value of this pair and pass it to the second argument.

     @param key A string that is key of the pair
     @param value any value of type T
     @return true if the key-pair value could be found and the second argument's value has been
                set successfully, false otherwise.
     */
    bool find(const std::string& key,  T& value) ;
    std::ostream& display(std::ostream&) const;
};


template <typename T>
ChainingTable<T>::ChainingTable(const unsigned& size) {
    size_ = size;
    table_ = new SortedList<container::Pair<std::string, T>>[size_];
}


template <typename T>
ChainingTable<T>::~ChainingTable<T>() {
    delete[] table_;
}


template <typename T>
ChainingTable<T>::ChainingTable(const ChainingTable& src) {
    size_ = src.size_;
    table_ = new SortedList<container::Pair<std::string, T>>[size_];
    for (unsigned i = 0; i < size_; ++i)
        table_[i] = src.table_[i];
}


template <typename T>
ChainingTable<T>& ChainingTable<T>::operator=(const ChainingTable<T>& src) {
    if (this != &src) {
        delete[] table_;
        size_ = src.size_;
        table_ = new SortedList<container::Pair<std::string, T>>[size_];
        for (unsigned i = 0; i < size_; ++i)
            table_[i] = src.table_[i];
    }
    return *this;
}


template <typename T>
ChainingTable<T>& ChainingTable<T>::operator=(ChainingTable<T>&& src) {
    std::swap(size_, src.size_);
    std::swap(table_, src.table_);
}


template <typename T>
ChainingTable<T>::ChainingTable(ChainingTable&& src) {
    size_ = src.size_;
    table_ = src.table_;
    src.table_ = nullptr;
}


template <typename T>
bool ChainingTable<T>::update(const std::string &key, const T &value) {
    unsigned index = hash_(key) % size_;
    auto pair = container::make_pair(key, value);
    auto it = table_[index].search(pair);
    if (it != table_[index].end())
        *it = pair;
    else
        table_[index].insert(pair);
    return true;
}


template <typename T>
bool ChainingTable<T>::remove(const std::string& key) {
    unsigned index = hash_(key) % size_;
    auto pair = container::make_pair(key, T{});
    for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
        if (*it == pair) {
            table_[index].erase(it);
            return true;
        }
    }
    return false;
}


template <typename T>
bool ChainingTable<T>::find(const std::string &key, T &value)  {
    unsigned index = hash_(key) % size_;
    auto it = table_[index].search(container::make_pair(key, value));
    if (it == table_[index].cend())
        return false;
    value = (*it).second;
    return true;
}


template <typename T>
std::ostream& ChainingTable<T>::display(std::ostream &os) const {
    for (unsigned i = 0u; i < size_; ++i)
        os << table_[i] << std::endl;
    return os;
}


#endif /* ChainingTable_h */
