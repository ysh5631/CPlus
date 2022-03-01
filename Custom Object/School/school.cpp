#include "school.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

void School::addStudent(const std::string& id, const Student& s){
    students.insert(pair<string, Student>(id, s));
}

void School::deleteStudent(const std::string& id){
    students.erase(id);
}

// map<string, Student> students
void School::modifyStudentGPA(const string& id, double gpa) {
    auto it = (this->students).find(id);
    if (it != (this->students).end()) {
        (it->second).modifyGPA(gpa);
    }
}

bool School::findStudent(const std::string& id) const{
    auto find_it = students.find(id);
    if(find_it != students.end())
        return true;
    else
        return false;
}

void School::print(const std::string& id) const{
    auto find_it = students.find(id);
    if(find_it != students.end())
        (find_it->second).print();
}