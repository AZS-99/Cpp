//
// Created by Adam Saher on 2021-05-15.
//

#include "str.h"

std::string truncate(const std::string& str, const unsigned& k) {
    auto count_spaces = 0u;
    auto it = str.cbegin();
    while (count_spaces < k && it < str.cend()) {
        if (std::isspace(*it++))
            ++count_spaces;
    }
    // You need to not include the last space.
    return it == str.cend()? std::string(str) : str.substr(0, it - str.cbegin() - 1);
}
