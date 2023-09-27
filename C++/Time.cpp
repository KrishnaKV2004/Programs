#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize data to 0
    Time() : hours(0), minutes(0), seconds(0) {}

    // Constructor to initialize data to fixed values
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Display time in 11:59:59 format
    void display() {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    // Add two Time objects and store the result in a new Time object
    Time addTime(const Time& t1, const Time& t2) {
        Time result;
        result.seconds = t1.seconds + t2.seconds;
        result.minutes = t1.minutes + t2.minutes + (result.seconds / 60);
        result.hours = t1.hours + t2.hours + (result.minutes / 60);

        result.seconds %= 60;
        result.minutes %= 60;

        return result;
    }
};

int main() {
    // Create two Time objects with fixed values
    Time time1(1, 30, 45);
    Time time2(2, 15, 30);

    // Create a third Time object and add time1 and time2
    Time time3 = time3.addTime(time1, time2);

    // Display the result
    std::cout << "Time1: ";
    time1.display();
    std::cout << "Time2: ";
    time2.display();
    std::cout << "Time1 + Time2: ";
    time3.display();

    return 0;
}
