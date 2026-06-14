#include <iostream> 
#include <map> // for my map table
#include <string> // text handling
#include <iomanip> // round to more decimal places
#include <algorithm> // to support "toupper"

int main() {

    double totalCredits = 0.0;
    double totalPoints = 0.0;
    int classCount = 0;
    char choice = 'y';

    // grade map, all accepted grade letters and their gpa point
    std::map<std::string, double> gradeMap = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0},
        {"D",  1.0},
        {"F",  0.0}, {"WU", 0.0}, {"FIN", 0.0}, {"FAB", 0.0}
    };

    // instructions
    std::cout << "GPA Calculator\n";
    std::cout << "Intructions: \n";
    std::cout << "i) Enter credits followed by letter grade (example: 3A or 4B+)\n";
    std::cout << "ii) Credits must be 1-9\n";
    std::cout << "iii) Valid grades: A+, A, A-, B+, B, B-, C+, C, D, F, WU, FIN, FAB\n\n";

    // the main loop
    while (choice == 'y' || choice == 'Y') {
        // variable to accept the user input
        std::string input;
        std::cout << "Enter credits and grade: ";
        std::cin >> input;

        // clear any input errors, and skips it to avoid an infinite loop
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input! Example: 3A\n";
            continue;
        }
        // splits the input into credit and grade,  the moment i lands on a letter
        // the loop stops and 'i' is now pointing right at where the grade begins
        int i = 0;
        while (i < input.size() && isdigit(input[i])) i++;

        // checks if the split worked
        // if there's no number OR no grade, print invalid and skip to the next loop.
        if (i == 0 || i == input.size()) {
            std::cout << "Invalid input! Example: 3A\n";
            continue;
        }

        // Converts number part (string) into an integer, prints an error instead of crashing.
        int credit;
        try {
            credit = std::stoi(input.substr(0, i));
        } catch (...) {
            std::cout << "Invalid input! Example: 3A\n";
            continue;
        }

        // get grade part and converts it to uppercase
        std::string grade = input.substr(i);
        for (char& c : grade) c = toupper(c);

        // credit range
        if (credit <= 0 || credit >= 10) {
            std::cout << "Invalid credits! Must be 1-9\n";
            continue;
        }

        // validates the correct grade
        if (!gradeMap.count(grade)) {
            std::cout << "Invalid grade!\n";
            continue;
        }

        //totals
        totalPoints += credit * gradeMap[grade];
        totalCredits += credit;
        classCount++;

        // asks the user to continue
        std::cout << "Add another class? (y/n): ";
        std::cin >> choice;
    }
        // final output
    if (classCount == 0) {
        std::cout << "No classes entered.\n";
    } else {
        double gpa = totalPoints / totalCredits;
        std::cout << "Classes taken: " << classCount << ", Semester GPA: ";
        
        // if GPA is a whole number, show 1 decimal, otherwise show 2
        if (gpa == (int)gpa) {
            std::cout << std::fixed << std::setprecision(1) << gpa << "\n";
        } else {
            std::cout << std::fixed << std::setprecision(2) << gpa << "\n";
        }
    }

    return 0;
}