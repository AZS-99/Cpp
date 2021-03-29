/*
 This assignment assumes you have already gone throught the Files assignment.
 
 Created by Adam Saher on 2021-03-29.
 */


#ifndef DataTable_h
#define DataTable_h

#include <vector>
#include <fstream>
#include <sstream>

template <typename T>
class DataTable {
    std::vector<std::pair<int, int>> points;
public:
    DataTable(std::fstream&);
};


template <typename T>
DataTable<T>::DataTable(std::fstream& file) {
    std::string line;
    std::stringstream ss;
    int x, y;
    while(getline(file, line)) {
        ss << line;
    }
}

#endif /* DataTable_h */
