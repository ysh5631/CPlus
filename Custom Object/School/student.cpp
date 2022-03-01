#include "student.h"
#include <iostream>
#include <string>
using namespace std;

void Student::modifyGPA(double gpa){
    _gpa = gpa;
}

void Student::print() const{
    cout << _id << " " << _name << " " << _gpa << endl;
}
