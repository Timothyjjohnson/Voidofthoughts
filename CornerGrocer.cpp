/* 
Timothy Johnson
June 2024
CS210 Programming Languages
Professor Tepe
*/

#include <iostream>
#include <fstream>
#include <map>

// function to prompt the menu for user
int getMenuOption() {
    int option;
    std::cout << "Menu's Options:\n";
    std::cout << "1) Look up the item's frequency\n";
    std::cout << "2) Print the item's frequencies\n";
    std::cout << "3) Print item frequency histogram\n";
    std::cout << "4) Exit Menu\n";
    std::cout << "Input your option: ";
    std::cin >> option;
    return option;
}

// function to look up the item's frequency
void lookupItemFrequency(const std::map<std::string, int>& itemFrequencies) {
    std::string item;
    std::cout << "Look up the item to get the frequency: ";
    std::cin >> item;

    auto iter = itemFrequencies.find(item);
    if (iter != itemFrequencies.end()) {
        std::cout << "Frequency of " << item << ": " << iter->second << std::endl;
    }
    else {
        std::cout << "Item not found." << std::endl;
    }
}

// function to print the item's frequencies
void printItemFrequencies(const std::map<std::string, int>& itemFrequencies) {
    std::cout << "Items Frequencies:\n";
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

// function to print the item's frequency histogram
void printItemHistogram(const std::map<std::string, int>& itemFrequencies) {
    std::cout << "Item Frequency Histogram:\n";
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    // open input file for reading item frequencies
    std::ifstream inputFile("CS210_Project_Three_Input_File.txt");
    if (!inputFile.is_open()) {
        std::cout << "Error opening input file." << std::endl;
        return 1;
    }

    std::map<std::string, int> itemFrequencies;

    // read the item frequencies from input file and update map
    std::string item;
    while (inputFile >> item) {
        itemFrequencies[item]++;
    }

    inputFile.close();

    // create output file for writing item frequencies
    std::ofstream outputFile("frequency.dat");
    if (!outputFile.is_open()) {
        std::cout << "Error opening output file." << std::endl;
        return 1; // Return error code if file cannot be opened
    }

    // write item frequencies to output file
    for (const auto& pair : itemFrequencies) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close();

    int option;
    do {
        option = getMenuOption();
        switch (option) {
        case 1:
            lookupItemFrequency(itemFrequencies);
            break;
        case 2:
            printItemFrequencies(itemFrequencies);
            break;
        case 3:
            printItemHistogram(itemFrequencies);
            break;
        case 4:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
        std::cout << std::endl;
    } while (option != 4);

    return 0;
}
