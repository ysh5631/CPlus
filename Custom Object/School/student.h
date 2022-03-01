#ifndef ASSIGMENT_STUDENT_H
#define ASSIGMENT_STUDENT_H
#include <string>
#include <iostream>

class Student {
public:
    Student(std::string id, std::string name, double gpa)
            : _id{id}, _name{name}, _gpa{gpa} { };
    ~Student() = default;
    void modifyGPA(double gpa);
    void print() const;

private:
    std::string _id, _name;
    double _gpa = 0.0;
};
#endif //ASSIGMENT_STUDENT_H
