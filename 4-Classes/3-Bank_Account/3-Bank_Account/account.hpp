//
//  account.hpp
//  3-Bank_Account
//
//  Created by Adam Saher on 2021-03-11.
//

#ifndef account_hpp
#define account_hpp
#include <iostream>
#include "iAccount.hpp"

class Account : public iAccount {
protected:
    double balance;
    unsigned transactions_count;
public:
    Account(const double& = 0.0);
    bool withdraw(const double&);
    bool deposit(const double&);
    std::ostream& print(std::ostream&) const;
};


#endif /* account_hpp */
