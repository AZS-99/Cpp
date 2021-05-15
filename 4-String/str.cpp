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
    return str.substr(0, it - str.cbegin());
}
