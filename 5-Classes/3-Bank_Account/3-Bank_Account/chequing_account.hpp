//
//  chequing_account.hpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-11.
//

#ifndef chequing_account_hpp
#define chequing_account_hpp

#include "account.hpp"

const double TRANSACTION_FEE = 0.1;
const unsigned TRANSACTION_LIMIT = 5;
const double MONTHLY_FEE = 3;

class ChequingAccount : public Account {    
public:
    ChequingAccount(const double& = 0);
    bool deposit(const double&);
    bool withdraw(const double&);
};

#endif /* chequing_account_hpp */
