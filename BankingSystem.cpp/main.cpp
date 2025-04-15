#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() 
{

    std::cout << "Checking the Account Classes\n" << std::endl;
    cout.precision(2);
    cout << fixed;
    
    // Savings Account

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"John"} );
    sav_accounts.push_back(Savings_Account {"James", 2000} );
    sav_accounts.push_back(Savings_Account {"Mary", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking Account
   
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account {} );
    check_accounts.push_back(Checking_Account {"Kirk"} );
    check_accounts.push_back(Checking_Account {"Sam", 2000} );
    check_accounts.push_back(Checking_Account {"Jones", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust Account
  
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {} );
    trust_accounts.push_back(Trust_Account {"Dake", 10000, 5.0} );
    trust_accounts.push_back(Trust_Account {"Jake", 20000, 4.0} );
    trust_accounts.push_back(Trust_Account {"Allen", 30000} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++){
        withdraw(trust_accounts, 1000);
    }

    std::cout << "=========================================================\n" << std::endl;
    std::cout << "Checking the exception handling for the given conditions\n"  <<  std::endl;

    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> larrys_account;
    try {
        larrys_account = std::make_unique<Savings_Account>("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }



    try {
        moes_account = std::make_unique<Savings_Account>("Moe", 1000.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(500.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(1000.0);
        std::cout << *moes_account << std::endl;
        
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InsufficientFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

