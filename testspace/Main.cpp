#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outputFile("output.txt"); // Create or open the "output.txt" file for writing

    if (outputFile.is_open()) { // Check if the file was successfully opened
        outputFile << "New text" << std::endl; // Write output to the file
        outputFile << "This is a line of text." << std::endl;
        outputFile.close(); // Close the file
        cout << "Output was written to the file." << std::endl;
    }
    else {
        cout << "Failed to open the file." << std::endl;
    }
}