#include <iostream>
#include <fstream>

void redirectOutputToFile(const std::string& filename) {
    std::ofstream out(filename); // Open a file for writing

    // Redirect std::cout to the file
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save original cout buffer
    std::cout.rdbuf(out.rdbuf()); // Redirect cout to the file
    
    // Output to cout will be written to the file
    std::cout << "Redirected output to file.\n";

    // Restore cout to its original state
    std::cout.rdbuf(coutbuf); // Restore original cout buffer

    std::cout << "Back to console output.\n"; // Output to console
}

int main() {
    redirectOutputToFile("grsjrhghhhhhhhhhhhhhhh.txt");
    return 0;
}
