#include <iostream>
#include <string>
#include <vector>

// Define a struct to hold student data
struct Student {
    std::string name;
    std::vector<double> grades;
};

// Function to calculate the average grade
double calculateAverage(const Student& s) {
    if (s.grades.empty()) return 0.0;
    
    double sum = 0.0;
    for (double grade : s.grades) {
        sum += grade;
    }
    return sum / s.grades.size();
}

int main() {
    // Create a student instance
    Student student1;
    student1.name = "Corinne";
    student1.grades = {85.5, 90.0, 78.5, 92.0};

    // Output the results
    std::cout << "Student: " << student1.name << "\n";
    std::cout << "Average Grade: " << calculateAverage(student1) << "\n";

    return 0;
}