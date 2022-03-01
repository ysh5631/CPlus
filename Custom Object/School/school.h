#ifndef ASSIGMENT_SCHOOL_H
#define ASSIGMENT_SCHOOL_H
#include "student.h"
#include <map>
#include <string>
#include <iostream>

class School {
public:
    // singleton pattern -------------
    static School& getInstance(std::string name) {
        static School s{name};
        return s;
    };
    School (School const&) = delete;
    School (School&&) = delete;
    School & operator=(School const&) = delete;
    School & operator=(School &&) = delete;
    ~School() = default;
    // -------------------------------
    void addStudent(const std::string& id, const Student& s);
    void deleteStudent(const std::string& id);
    void modifyStudentGPA(const std::string& id, double gpa);
    bool findStudent(const std::string& id) const;
    void print() const {
        std::cout << "School Name: " << _name << ", " << "# of Student: " << students.size() << '\n';
        for (const auto& s: students)
            s.second.print();
    }
    void print(const std::string& id) const;

private:
    // you can not create an instance of Student class directly.
    School(std::string name) : _name(name) {};
    std::string _name;
    std::map<std::string, Student> students;
};
#endif //ASSIGMENT_SCHOOL_H