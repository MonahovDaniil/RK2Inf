#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    long long accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(long long accNum, const string& owner, double Balance = 0.0) :
        accountNumber(accNum), ownerName(owner), balance(Balance) {
        if (Balance < 0) {
            cerr << "Yачальный баланс не может быть отрицательным.\n";
            balance = 0.0;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнение счета " << accountNumber << " на сумму " << amount << ". Новый баланс: " << balance << endl;
        }
        else {
            cerr << "Cумма пополнения должна быть положительной.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снятие со счета " << accountNumber << " суммы " << amount << ". Новый баланс: " << balance << endl;
        }
        else {
            cerr << "Недостаточно средств или сумма снятия некорректна.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() const {
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(long long accNum, const string& owner, double Balance, double rate) :
        BankAccount(accNum, owner, Balance), interestRate(rate) {
        if (rate < 0) {
            cerr << "Ошибка: процентная ставка не может быть отрицательной.\n";
            interestRate = 0.0;
        }
    }

    void accrueInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Начислены проценты на счет " << accountNumber << ": " << interest << ". Новый баланс: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    BankAccount checkingAccount(1234567890, "Иван Иванов", 1000.0);
    SavingsAccount savingsAccount(9876543210, "Петр Петров", 500.0, 0.05);

    checkingAccount.displayAccountInfo();
    checkingAccount.deposit(500.0);
    checkingAccount.withdraw(200.0);
    checkingAccount.displayAccountInfo();

    cout << "\n--- Сберегательный счет ---\n";
    savingsAccount.displayAccountInfo();
    savingsAccount.deposit(300.0);
    savingsAccount.accrueInterest();
    savingsAccount.displayAccountInfo();

    return 0;
}
