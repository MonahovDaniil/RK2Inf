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
            cerr << "Y�������� ������ �� ����� ���� �������������.\n";
            balance = 0.0;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "���������� ����� " << accountNumber << " �� ����� " << amount << ". ����� ������: " << balance << endl;
        }
        else {
            cerr << "C���� ���������� ������ ���� �������������.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "������ �� ����� " << accountNumber << " ����� " << amount << ". ����� ������: " << balance << endl;
        }
        else {
            cerr << "������������ ������� ��� ����� ������ �����������.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() const {
        cout << "����� �����: " << accountNumber << endl;
        cout << "��������: " << ownerName << endl;
        cout << "������: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(long long accNum, const string& owner, double Balance, double rate) :
        BankAccount(accNum, owner, Balance), interestRate(rate) {
        if (rate < 0) {
            cerr << "������: ���������� ������ �� ����� ���� �������������.\n";
            interestRate = 0.0;
        }
    }

    void accrueInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "��������� �������� �� ���� " << accountNumber << ": " << interest << ". ����� ������: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    BankAccount checkingAccount(1234567890, "���� ������", 1000.0);
    SavingsAccount savingsAccount(9876543210, "���� ������", 500.0, 0.05);

    checkingAccount.displayAccountInfo();
    checkingAccount.deposit(500.0);
    checkingAccount.withdraw(200.0);
    checkingAccount.displayAccountInfo();

    cout << "\n--- �������������� ���� ---\n";
    savingsAccount.displayAccountInfo();
    savingsAccount.deposit(300.0);
    savingsAccount.accrueInterest();
    savingsAccount.displayAccountInfo();

    return 0;
}
