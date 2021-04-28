//
//  saving_account.cpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-13.
//

#include "saving_account.hpp"

SavingAccount::SavingAccount(const double& amount) : Account(amount){}


bool SavingAccount::withdraw(const double& amount) {
    if (amount + balance > SAVINGS_TRANSACTION_FEE && transactions_count < SAVINGS_TRANSACTION_LIMIT)
        return Account::withdraw(amount) && ++transactions_count;
    return false;
}
