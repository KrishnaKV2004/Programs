#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num /= 2;
    }

    if (count % 2 == 0) {
        std::cout << "The number is an evil number." << std::endl;
    } else {
        std::cout << "The number is not an evil number." << std::endl;
    }

    return 0;
}