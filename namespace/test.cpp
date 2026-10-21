#include <iostream>
#include <string>

//Defince a struct called student to hold informaion about a student

struct Student
{
    std::string name;
    int rollNumber;
    float mathMarks;
    float scienceMarks;
    float englishMarks;
};


int main()
{
    //Declare a variable of type Student
    Student student1;

    //Input: prompt the user to enter the student details
    std::cout << "Enter student's name: ";
    std::getline(std::cin >> std::ws, student1.name);    //use getline to allow spaces int the name

    std::cout << "Enter the student's roll numbe: ";
    std::cin >> student1.rollNumber;

    std::cout << "Enter marks in Math: ";
    std::cin >> student1.mathMarks;

    std::cout << "Enter the marks in Science: ";
    std::cin >> student1.scienceMarks;

    std::cout << "Enter the marks in English: ";
    std::cin >> student1.englishMarks;

    // processing: Calculate the total and aveerage marks for the student 

    float totalMarks = student1.mathMarks + student1.scienceMarks + student1.englishMarks;
    float averageMarks = totalMarks / 3;


    //Output the student details and the calculated results
    std::cout << "\nStudent's Information:" << '\n';
    std::cout << "Name: " << student1.name << '\n';
    std::cout << "Roll Number:" << student1.rollNumber << '\n';
    std::cout << "Math Marks: " << student1.mathMarks << '\n';
    std::cout << "Science Marks: " << student1.scienceMarks << '\n';
    std::cout << "English Marks: " << student1.englishMarks << '\n';
    std::cout << "\nTotal marks: " << totalMarks << '\n';
    std::cout << "Average Marks: " << averageMarks << '\n';

    return 0;

}
