#include <iostream>
#include <vector>

class Account {
private:
    int accountId;
    std::string accountHolderName;
    double balance;

public:
    Account(int accountId, std::string accountHolderName, double balance) : accountId(accountId), accountHolderName(accountHolderName), balance(balance) {}

    int getAccountId() const {
        return accountId;
    }

    std::string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful. The new balance is: " << balance << std::endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful. The new balance is: " << balance << std::endl;
        } else {
            std::cout << "Insufficient bank balance" << std::endl;
        }
    }
};

class Bank {
private:
    std::vector<Account> accounts;

public:
    void addAccount(Account account) {
        accounts.push_back(account);
    }

    void displayAllAccounts() const {
        for (const auto& account : accounts) {
            std::cout << "Account Id: " << account.getAccountId() << std::endl;
            std::cout << "Account holder name: " << account.getAccountHolderName() << std::endl;
            std::cout << "Balance: " << account.getBalance() << std::endl;
            std::cout << "----------------------------" << std::endl;
        }
    }

    Account* getAccountById(int accountId) {
        for (auto& account : accounts) {
            if (account.getAccountId() == accountId) {
                return &account;
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;

    // Adding some sample accounts
    Account account1(1, "Lzyrus", 5000);
    Account account2(2, "Love", 3000);

    bank.addAccount(account1);
    bank.addAccount(account2);

    int choice, accountId;

     while (true) {
         std :: cout <<"1. Deposit\n2. Withdraw\n3. Check Balance\n4. Display All Accounts\n5. Exit\n";
         std :: cout <<"Enter your choice: ";
         std :: cin >> choice ;

         switch(choice){
             case 1:{
                 double depositAmount ;
                 std :: cout <<"Enter Account Id: ";
                 std :: cin >> accountId ;

                 Account* depositAccount = bank.getAccountById(accountId);
                 if(depositAccount != nullptr){
                     std :: cout <<"Enter deposit amount: ";
                     std :: cin >> depositAmount ;
                     depositAccount->deposit(depositAmount);
                 } else{
                     std :: cout <<"Invalid Account Id"<<std :: endl ;
                 }
                 break ;
             }

             case 2:{
                 double withdrawAmount ;
                 std :: cout <<"Enter Account Id: ";
                 std :: cin >> accountId ;

                 Account* withdrawAccount = bank.getAccountById(accountId);
                 if(withdrawAccount != nullptr){
                     std :: cout <<"Enter withdraw amount: ";
                     std :: cin >> withdrawAmount ;
                     withdrawAccount->withdraw(withdrawAmount);
                 } else{
                     std :: cout <<"Invalid Account Id"<<std :: endl ;
                 }
                 break ;
             }

             case 3:{
                  double checkBalanceAmount ;
                  std :: cout <<"Enter Account Id: ";
                  std :: cin >> accountId ;

                  Account* checkBalanceAccount = bank.getAccountById(accountId);
                  if(checkBalanceAccount != nullptr){
                      checkBalanceAmount = checkBalanceAccount->getBalance();
                      std :: cout <<"Current Balance: "<<checkBalanceAmount<<std :: endl ;
                  } else{
                      std :: cout <<"Invalid Account Id"<<std :: endl ;
                  }
                  break ;
              }

              case 4:{
                   bank.displayAllAccounts();
                   break ;
               }

               case 5:
                   return 0 ;

               default :
                   std :: cout <<"Invalid Choice"<<std :: endl ;
          }
      }

      return 0 ;
}