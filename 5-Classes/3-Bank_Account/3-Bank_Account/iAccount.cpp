//
//  iAccount.cpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-14.
//

#include "iAccount.hpp"
#include "chequing_account.hpp"
#include "saving_account.hpp"

iAccount* create_account(const AccountType& account_type, const double& amount) {
    iAccount* account = nullptr;
    switch (account_type) {
        case AccountType::chequing:
            account = new ChequingAccount(amount);
            break;
        case AccountType::savings:
            account = new SavingAccount(amount);
            break;
        default:
            break;
    }
    return account;
}


std::ostream& operator<<(std::ostream& os, const iAccount* account) {
    account->print(os);
    return os;
}
