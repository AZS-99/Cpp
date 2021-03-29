//
//  main.cpp
//  Container_fns
//
//  Created by Adam Saher on 2021-03-29.
//

#include <iostream>
#include "DataTable.h"

int main(int argc, const char * argv[]) {
    //Names of the files are passed in argv (Revise the Files assignment)
    std::fstream file(argv[1]);
    
    DataTable<float> data_table(file);
    
    return 0;
}
