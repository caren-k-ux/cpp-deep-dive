#include <iostream>
#include <string>

//Definition of BankAccount class

class bankAccount
{
    private:
    //private attributes: only accessible within the class
    std::string accountHolderName;
    int accountNumber;
    double balance;

    public:
    //constructor to initialize bank account
    bankAccount(std::string, int , double);
    bankAccount();
    void displayAccountDetails();
    void deposit(double);
    void withdraw(double);
    double getBalance();

    ~bankAccount();



bankAccount::bankAccount(std::string name, int accNum, double bal)
    :accountHolderName(name) , accountNumber(accNum), balance(bal)
    {

    }

bankAccount::bankAccount()
    :accountHolderName("Unknown"), accountNumber(0), balance(0.0)
    {}

bankAccount::~bankAccount()
{
    std::cout << "cleanup";
}

void bankAccount::displayAccountDetails()
{
    std::cout << "Account Holder: " << accountHolderName << '\n';
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Account Balance: " << balance << '\n';
}

void bankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        std::cout << "Deposited: $" << amount << '\n';
        std::cout << "New Balance: $" << balance << '\n';

    }

    else
    {
        std::cout << "Invalid deposit amount." << '\n';
    }
}

void bankAccount::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        std::cout << "Withdrew: $" << amount << '\n';
        std::cout << "Remaining Balance: $" << balance << '\n';
    }

    else if (amount > balance)
    {
        std::cout << "Insufficient balance!" << '\n';

    }

    else
    {
        std::cout << "Invalid withdrawal amount." << '\n';
    }
}

double bankAccount::getBalance()
{
    return balance;
}

int main()
{
    //Creating an object of bank account class for parametised constructor
    bankAccount account1("John Doe", 1234567, 500.0);
    //display account detals
    std::cout << "Initial account details: " << '\n';
    account1.displayAccountDetails();
    std::cout << '\n';

    //Deposit some amount
    std::cout << "Enter the amount you want to deposit: " ;
    double deposit {0.0};
    std::cin >> deposit;
    account1.deposit(deposit);
    std::cout << '\n';

    std::cout << "Performing withdrawal Operation: " << '\n';
    account1.withdraw(100,0);
    std::cout << '\n';

    std::cout << "Attempting to withdraw exceeding amount: " << '\n';
    account1.withdraw(600.0);

    std::cout << '\n';
    //display final account details
    std::cout << "Final Account Details: " << '\n';
    account1.displayAccountDetails();
    return 0;


}
