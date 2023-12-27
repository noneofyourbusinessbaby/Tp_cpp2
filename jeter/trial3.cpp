#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultimap = {
        {5, "Five"},
        {2, "Two"},
        {8, "Eight"},
        {1, "One"},
        {3, "Three"}
    };

    // Sort the multimap by keys in descending order
    std::multimap<int, std::string, std::greater<>> sortedMap(myMultimap.begin(), myMultimap.end());

    // Display the sorted multimap in descending order
    for (const auto& pair : sortedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
