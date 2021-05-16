//
// Created by Adam Saher on 2021-05-15.
//

#include "str.h"

/// Return a copy of the passed string until the char before the kth space
std::string truncate_n_words(const std::string& str, const unsigned& n) {
    auto count_spaces = 0u;
    auto it = str.cbegin();
    while (count_spaces < n && it < str.cend()) {
        if (std::isspace(*it++))
            ++count_spaces;
    }
    // You need to not include the last space.
    return it == str.cend()? std::string(str) : str.substr(0, it - str.cbegin() - 1);
}


/// Return a string shuffled so that the indices vector holds the correct order of their
/// parallel values in the passed string
/// example: string "mada" indices: [4, 3, 2, 1]  -> "adam"
std::string shuffle_string(const std::string& str, const std::vector<int>& indices) {
    std::string shuffled(str.length(), '\0');
    auto it_str = str.cbegin();
    auto it_idx = indices.cbegin();
    auto it_sh = shuffled.begin();

    for (; it_str < str.cend(); ++it_str, ++it_idx) {
        it_sh = shuffled.begin() + *it_idx;
        *it_sh = *it_str;
    }
    return shuffled;
}

