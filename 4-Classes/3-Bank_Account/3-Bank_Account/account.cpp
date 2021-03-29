//
//  account.cpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-11.
//

#include "account.hpp"

Account::Account(const double& amount) {
    balance = amount;
    transactions_count = 0u;
}


bool Account::deposit(const double& amount) {
    if (amount > 1) {
        balance += amount;
        return true;
    }
    return false;
}


bool Account::withdraw(const double& amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}


std::ostream& Account::print(std::ostream& os) const {
    return os << "Balance: " << balance;
}
