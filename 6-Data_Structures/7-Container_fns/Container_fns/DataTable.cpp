//
//  DataTable.cpp
//  Container_fns
//
//  Created by Adam Saher on 2021-03-29.
//

#include "DataTable.hpp"

DataTable::DataTable(std::fstream& file) {
    std::string line;
    std::stringstream ss;
    float x, y;
    while(getline(file, line)) {
        ss << line;
        ss >> x >> y;
        points.push_back(std::make_pair(x, y));
    }
}


double DataTable::mean() const {
    
}
