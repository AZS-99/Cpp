/*
 This assignment assumes you have already gone throught the Files assignment.
 
 Created by Adam Saher on 2021-03-29.
 */


#ifndef DataTable_h
#define DataTable_h

#include <vector>
#include <fstream>
#include <sstream>

class DataTable {
    std::vector<std::pair<double, double>> points;
public:
    DataTable(std::fstream&);
    double mean() const;
};

#endif /* DataTable_h */
