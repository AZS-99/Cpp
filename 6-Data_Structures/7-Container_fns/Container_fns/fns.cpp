//
//  fns.cpp
//  Container_fns
//
//  Created by Adam Saher on 2021-04-19.
//


#include <vector>
#include <string>
#include <set>
#include <map>
#include "fns.hpp"


//All possible combinations of letters by dialling on phone pads
std::vector<std::string> string_combinations(const std::string num_str) {
    const std::map<char, std::set<char>> dictionary = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    std::vector<std::string> result, tmp;
    result.push_back("");
    std::set<char> set;
    for (auto& digit : num_str) {
        set = dictionary.find(digit)->second;
        for (auto it_s = set.begin(); it_s != set.end(); ++it_s) {
            for (auto it_r = result.begin(); it_r != result.end(); ++it_r) {
                tmp.push_back(*it_r + *it_s);
            }
        }
        result.swap(tmp);
        tmp.clear();
    }

    return result;
}
