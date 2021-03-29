//
//  data_table.hpp
//  Lambda
//
//  Created by Adam Saher on 2021-03-29.
//

#ifndef data_table_hpp
#define data_table_hpp


#include <vector>
#include <fstream>
#include <sstream>



class DataTable {
    std::vector<std::pair<double, double>> points;
public:
    DataTable(std::fstream&);
    double mean() const;
    double median() const;
};

#endif /* data_table_hpp */
