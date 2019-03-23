//
//  Pair.h
//  Pair
//
//  Created by Adam Saher on 17/03/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

#ifndef Pair_h
#define Pair_h

namespace container {
    template <typename T, typename V>
    struct Pair {
        T first;
        V second;
        Pair(); //Important for T{} initialisation, like a Node of Pairs
        Pair(const T&, const V&);
        bool operator<(const Pair&) const;
        bool operator==(const Pair&) const;
    };
    
    template <typename T, typename V>
    Pair<T, V>::Pair() {
        first = T{};
        second = V{};
    }
    
    
    template <typename T, typename V>
    Pair<T, V>::Pair(const T& first, const V& second) {
        this->first = first;
        this->second = second;
    }
    
    
    template <typename T, typename V>
    bool Pair<T, V>::operator<(const Pair& other) const {
        return first < other.first;
    }
    
    
    template <typename T, typename V>
    bool Pair<T, V>::operator==(const Pair<T, V>& other) const {
        return first == other.first;
    }
    
    
    template <typename T, typename V>
    std::ostream& operator<<(std::ostream& os, const Pair<T, V>& pair) {
        return os << "<" << pair.first << ", " << pair.second << ">";
    }
    
    template <typename T, typename V>
    Pair<T, V> make_pair(const T& first, const V& value) {
        return Pair<T, V>(first, value);
    }
}





#endif /* Pair_h */
