// File: bank_account.cpp (65 lines)
#include <iostream>
#include <string>
#include <iomanip>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;
    
public:
    BankAccount(std::string accNum, std::string holder, double initialBalance = 0)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}
    
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
            return true;
        }
        std::cout << "Invalid deposit amount!\n";
        return false;
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
            return true;
        }
        std::cout << "Invalid withdrawal amount or insufficient funds!\n";
        return false;
    }
    
    void displayAccountInfo() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\n=== Account Information ===\n";
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
    
    double getBalance() const { return balance; }
    
    void transfer(BankAccount& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            std::cout << "Transfer successful!\n";
        } else {
            std::cout << "Transfer failed!\n";
        }
    }
};

int main() {
    std::cout << "=== Bank Account System ===\n\n";
    
    // Create accounts
    BankAccount account1("ACC001", "John Doe", 1000.00);
    BankAccount account2("ACC002", "Jane Smith", 500.00);
    
    // Display initial balances
    account1.displayAccountInfo();
    account2.displayAccountInfo();
    
    // Perform transactions
    std::cout << "\n=== Transactions ===\n";
    account1.deposit(250.50);
    account1.withdraw(150.25);
    
    // Transfer money
    std::cout << "\n=== Transfer ===\n";
    account1.transfer(account2, 200.00);
    
    // Display final balances
    std::cout << "\n=== Final Balances ===\n";
    account1.displayAccountInfo();
    account2.displayAccountInfo();
    
    // Test insufficient funds
    std::cout << "\n=== Testing Overdraft ===\n";
    account1.withdraw(account1.getBalance() + 100);
    
    return 0;
}
