#include <iostream>
#include <iomanip>

class SavingsAccount {
private:
    static double annualInterestRate;
    double savingsBalance;

public:
    SavingsAccount(double balance) : savingsBalance(balance) {}

    void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate) / 12.0;
        savingsBalance += monthlyInterest;
    }

    static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    double getBalance() const {
        return savingsBalance;
    }
};

// Initialize the static member variable
double SavingsAccount::annualInterestRate = 0.0;

int main() {
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    // Set annual interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    std::cout << "Month 1:" << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Saver 1 balance: $" << std::fixed << std::setprecision(2) << saver1.getBalance() << std::endl;
    std::cout << "Saver 2 balance: $" << std::fixed << std::setprecision(2) << saver2.getBalance() << std::endl;

    // Set annual interest rate to 5%
    SavingsAccount::modifyInterestRate(0.05);

    std::cout << "Month 2:" << std::endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "Saver 1 balance: $" << std::fixed << std::setprecision(2) << saver1.getBalance() << std::endl;
    std::cout << "Saver 2 balance: $" << std::fixed << std::setprecision(2) << saver2.getBalance() << std::endl;

    return 0;
}
