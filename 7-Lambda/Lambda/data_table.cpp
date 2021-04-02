//
//  data_table.cpp
//  Lambda
//
//  Created by Adam Saher on 2021-03-29.
//

#include "data_table.hpp"
#include <algorithm>
#include <numeric>

DataTable::DataTable(std::fstream& file) {
    std::string line;
    std::stringstream ss;
    double x, y;
    while(getline(file, line)) {
        ss << line;
        ss >> x >> y;
        points.push_back(std::make_pair(x, y));
    }
    file.close();
}


double DataTable::mean() const {
    return std::accumulate(points.cbegin(), points.cend(), double(0), [] (double& bank, const std::pair<double, double>& point) {
        return bank + point.second;
    })/points.size();
}


double DataTable::median() const {
    std::vector<double> range(points.size());
    std::transform(points.cbegin(), points.cend(), range.begin(), [] (const std::pair<double, double>& point) {
        return point.second;
    });
    std::sort(range.begin(), range.end());
    return range[range.size()/2];
}


