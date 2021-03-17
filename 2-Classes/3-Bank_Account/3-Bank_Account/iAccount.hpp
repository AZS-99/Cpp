/*
 An interface is PURE abstract class; a special case of abstract classes containing only pure virtual methods (= 0)
 which are the only methods we want the user to have access to.
 An interface doesn't contain any member variables (the user doesn't need to know about them; they only need the methods)
 and is the only thing that we are going to include int the main.cpp, so the user can't access even the abstract class
 below it, and hence, can't see the member variables.
 
 Created by Adam Saher on 08/12/2018.
*/
#ifndef iAccount_hpp
#define iAccount_hpp

#include <iostream>

enum class AccountType {
    chequing,
    savings
};


class iAccount {
    virtual bool withdraw(const double&) = 0;
    virtual bool deposit(const double&) = 0;
    virtual std::ostream& print(std::ostream&) const = 0;
    friend std::ostream& operator<<(std::ostream&, const iAccount*); //A friend fn can't be virtual, since it doesn't belong.
};

// Constructors can't be virtual. why?!
// Abstract classes can neither be passed as parameters, nor used as return type, but we can use their pointers instead
iAccount* create_account(const AccountType&, const double&);


/*
 All classes that come before the first one that has an implementation for all the pure virtual methods in the
 interface, are abstract.
 */

#endif /* iAccount_hpp */
