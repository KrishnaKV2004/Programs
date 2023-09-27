#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> dictionary;

    // Insert key-value pairs
    dictionary["apple"] = 10;
    dictionary["banana"] = 5;
    dictionary["cherry"] = 7;

    // Access values
    std::cout << "The value of apple is: " << dictionary["apple"] << std::endl;

    // Iterate through the unordered_map
    for (const auto& pair : dictionary) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}