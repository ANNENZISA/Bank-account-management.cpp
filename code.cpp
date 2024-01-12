#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    double balance;

public:
    BankAccount(const string& name, double initialBalance) {
        accountHolderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Balance: $" << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;

    while (true) {
        cout << "\n----- Banking System Menu -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";

        int choice;
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double initialBalance;
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter initial balance: $";
                cin >> initialBalance;
                accounts.push_back(BankAccount(name, initialBalance));
                cout << "Account created successfully.\n";
                break;
            }
            case 2: {
                int accountIndex;
                double depositAmount;
                cout << "Enter account index: ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < accounts.size()) {
                    cout << "Enter deposit amount: $";
                    cin >> depositAmount;
                    accounts[accountIndex].deposit(depositAmount);
                } else {
                    cout << "Invalid account index.\n";
                }
                break;
            }
            case 3: {
                int accountIndex;
                double withdrawalAmount;
                cout << "Enter account index: ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < accounts.size()) {
                    cout << "Enter withdrawal amount: $";
                    cin >> withdrawalAmount;
                    accounts[accountIndex].withdraw(withdrawalAmount);
                } else {
                    cout << "Invalid account index.\n";
                }
                break;
            }
            case 4: {
                int accountIndex;
                cout << "Enter account index: ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < accounts.size()) {
                    accounts[accountIndex].displayAccountInfo();
                } else {
                    cout << "Invalid account index.\n";
                }
                break;
            }
            case 5:
                cout << "Exiting the Banking System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 5.\n";
        }
    }

    return 0;
}
