#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Error creating file." << std::endl;
        return 1;
    }

    outFile << "Hello, World!" << std::endl;
    outFile << "This is a test file." << std::endl;
    outFile << "C++ file handling example." << std::endl;
    outFile.close();

    std::ifstream inFile("output.txt");
    if (!inFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();

    return 0;
}
