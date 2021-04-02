//
//  chequing_account.cpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-11.
//

#include "chequing_account.hpp"

//Semicolon initiates the parent
ChequingAccount::ChequingAccount(const double& amount) : Account(amount) {
    transactions_count = 0u;
}


bool ChequingAccount::deposit(const double& amount) {
    if (transactions_count < TRANSACTION_LIMIT) {
        return Account::deposit(amount) && ++transactions_count;
    } else {
        if (amount + balance > TRANSACTION_FEE)
            return Account::deposit(amount) && Account::withdraw(TRANSACTION_FEE);
        return false;
    }
}


bool ChequingAccount::withdraw(const double& amount) {
    if (transactions_count < TRANSACTION_LIMIT)
        return Account::withdraw(amount) && ++transactions_count;
    else {
        if (amount + balance > TRANSACTION_FEE)
            return Account::deposit(amount) && Account::withdraw(TRANSACTION_FEE);
        return false;
    }
}
