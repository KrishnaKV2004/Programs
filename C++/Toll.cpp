#include <iostream>

class TollBooth {
private:
    int totalCars;
    double totalCash;

public:
    TollBooth() : totalCars(0), totalCash(0.0) {}

    void payingCar() {
        totalCars++;
        totalCash += 0.5;
    }

    void nonPayCar() {
        totalCars++;
    }

    void display() {
        std::cout << "Total number of cars: " << totalCars << std::endl;
        std::cout << "Total cash collected: $" << totalCash << std::endl;
    }
};

int main() {
    TollBooth tollBooth;
    char choice;

    std::cout << "Toll Booth Program" << std::endl;
    std::cout << "-----------------" << std::endl;

    do {
        std::cout << "Press 'P' to count a paying car, 'N' to count a non-paying car, or 'E' to exit: ";
        std::cin >> choice;

        switch (choice) {
            case 'P':
            case 'p':
                tollBooth.payingCar();
                break;

            case 'N':
            case 'n':
                tollBooth.nonPayCar();
                break;

            case 'E':
            case 'e':
                tollBooth.display();
                std::cout << "Exiting the program." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'E' && choice != 'e');

    return 0;
}