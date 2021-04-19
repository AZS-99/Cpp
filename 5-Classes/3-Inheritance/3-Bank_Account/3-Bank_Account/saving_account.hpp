//
//  saving_account.hpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-13.
//

#ifndef saving_account_hpp
#define saving_account_hpp


#include <stdio.h>
#include "account.hpp"

const unsigned SAVINGS_TRANSACTION_LIMIT = 1;
const double SAVINGS_TRANSACTION_FEE = 0.5;

class SavingAccount : public Account {
public:
    SavingAccount(const double& = 0);
    bool withdraw(const double&);
};

#endif /* saving_account_hpp */
