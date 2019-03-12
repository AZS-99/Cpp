/******************************************
 Name: Adam Saher
 Sudent No: 
 userID: sadam4
 Date: 17/10/2018
 ******************************************/

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <numeric>
#include <algorithm>

namespace w7 {
    template <typename T>
    class DataTable {
        const size_t field_width;
        const size_t precision;
        std::vector<std::pair<T, T>> data;
    public:
        DataTable(std::ifstream&, size_t, size_t);
        size_t getSize() const;
        T mean() const;
        T median() const;
        T sigma() const;
        void regression(T& slope, T& y_intercept) const;
        void display(std::ostream&) const;
    };
    
    
    template <typename T>
    DataTable<T>::DataTable(std::ifstream& file, size_t field_width, size_t precision): field_width(field_width), precision(precision){
        
        std::string line;
        T x, y;
        std::stringstream ss;
        while (getline(file, line)){
            ss << line; //we didn't need cleaning up the stringstream using ss.str(string()) because it gets emptied in the next step.
            ss >> x >> y; //stringstream takes care of the types; x and y are assigned values of type T, not strings. + skips spaces
            data.push_back(std::make_pair(x, y));
        }
        file.close();
    }
    
    
    template <typename T>
    size_t DataTable<T>::getSize() const {
        return data.size();
    }
    
    
    template <typename T>
    T DataTable<T>::mean() const {
        //accumulate passes the type of return and the dereference of the first pointer (data.begin)
        return std::accumulate(data.begin(), data.end(), T(0.0), [] (T& accumulated, const std::pair<T, T>& element){
            return accumulated + element.second;
        }) / getSize();
    }
    
    
    template <typename T>
    T DataTable<T>::median() const {
        size_t size = data.size();
        
        std::vector<T> cpy(size, 0);
        std::transform(data.begin(), data.end(), cpy.begin(), [] (const std::pair<T, T>& p1) {
            return p1.second;
        });
        
        std::sort(cpy.begin(), cpy.end());
        return  cpy[size/2];
    }
    
    
    template <typename T>
    T DataTable<T>::sigma() const {
        double m = mean();
        double a = std::accumulate(data.begin(), data.end(), 0.0, [&m] (double& accumulated, const std::pair<T, T>& element) {
            return accumulated + std::pow((element.second - m), 2);
        });
        return std::sqrt(a/(getSize() - 1));
    }
    
    
    template <typename T>
    void DataTable<T>::regression(T& slope, T& intercept) const {
        size_t size = getSize();
        
        double sigmaY = std::accumulate(data.begin(), data.end(), 0.0, [] (double& accumulated, const std::pair<T, T>& p) {
            return accumulated + p.second;
        });
        
        double sigmaX = std::accumulate(data.begin(), data.end(), 0.0, [] (double& accumulated, const std::pair<T, T>& p) {
            return accumulated + p.first;
        });
        
        double sigmaX2 = std::accumulate(data.begin(), data.end(), 0.0, [] (double accumulated, const std::pair<T, T>& p) {
            return accumulated + std::pow(p.first, 2);
        });
        
        double sigmaXY = std::accumulate(data.begin(), data.end(), 0.0, [] (T accumulated, const std::pair<T, T>& p) {
            return accumulated + p.first * p.second;
        });
        
        slope = (size * sigmaXY - sigmaX * sigmaY) / (size * sigmaX2 - std::pow(sigmaX, 2));
        intercept = (sigmaY - slope * sigmaX) / size;
    }
    
    
    template <typename T>
    void DataTable<T>::display(std::ostream& os) const {
        os << std::setw(field_width) << "x" << std::setw(field_width) << "y" << std::endl;
        std::for_each(data.begin(), data.end(), [&] (std::pair<T, T> p) {
            //std::fixed makes integers show as doubles.
            os << std::fixed << std::setw(field_width) << std::setprecision(precision) << std::right << p.first  << std::setw(field_width) << p.second << std::endl;
        });
    }
    
    
    template <typename T>
    std::ostream& operator<<(std::ostream& os, DataTable<T> dataTable) {
        dataTable.display(os);
        return os;
    }
}

#endif /* DataTable_h */
