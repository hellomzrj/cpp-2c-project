#include <iostream>
using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;

public:
    Account(string number, double initialBalance)
    {
        accountNumber = number,
        balance = initialBalance;
    }
    // Abstraction
    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << endl;
        }
    }
    // Abstraction
    virtual void withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account " << accountNumber << endl;
        }
        else
        {
            cout << "Insufficient balance in account " << accountNumber << endl;
        }
    }
    // Abstraction
    virtual void displayBalance()
    {
        cout << "Account " << accountNumber << " has a balance of $" << balance << endl;
    }
};

// Inheritance 
class SavingsAccount : public Account
{
    //Encapsulation
private:
    double interestRate;

public:
    SavingsAccount(string number, double initialBalance, double rate) : Account(number, initialBalance)
    {
        interestRate = rate;
    }
};

// Inheritance
class CheckingAccount : public Account
{

public:
    CheckingAccount(string number, double initialBalance)
        : Account(number, initialBalance) {}

    // Polymorphism 
    void withdraw(double amount) override
    {
        // Allow overdraft up to $100
        if (amount > 0 && balance >= amount - 100)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " from checking account " << accountNumber << endl;
        }
        else
        {
            cout << "Insufficient balance or overdraft limit reached in checking account "
                 << accountNumber << endl;
        }
    }
};

int main()
{
    SavingsAccount savings("SA001", 1000.0, 5.0);
    CheckingAccount checking("CA001", 500.0);

    Account *account1 = &savings;
    Account *account2 = &checking;

    account1->deposit(200);
    account2->deposit(300);
    cout << endl;

    account1->withdraw(150);
    account2->withdraw(400);
    cout << endl;

    account1->displayBalance();
    account2->displayBalance();
    cout << endl;

    return 0;
}
