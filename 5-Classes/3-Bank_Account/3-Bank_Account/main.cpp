//
//  main.cpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-11.
//

#include <iostream>
#include "account.hpp"

int main(int argc, const char * argv[]) {
    iAccount* account = create_account(AccountType::chequing, 10);
    std::cout << account << std::endl;
    
    
    return 0;
}
