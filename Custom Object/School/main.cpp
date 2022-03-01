#include "school.h"
#include "student.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

enum Command { ADD, DELETE, PRINT, FIND, MODIFY, QUIT, INVALID };

pair<string, Student> make_student(){
    cout << "Enter id, name, gpa : " << endl;
    string id; string studentName; double gpa;
    cin >> id >> studentName >> gpa;
    Student s{id, studentName, gpa};
    pair<string, Student> result = pair<string, Student>{id, s};
    return result;
}

Command getCommand(const string& command){
    static map<string, Command> cmd = {
            {"add", ADD}, {"delete", DELETE}, {"print", PRINT},
            {"find", FIND}, {"modify", MODIFY}, {"quit", QUIT},
            {"invalid", INVALID}
    };
    auto find_it = cmd.find(command);
    if(find_it!=end(cmd))
        return cmd[command];
    else
        return cmd["invalid"];
}

int main() {
    cout << "Set School Name : " << endl;
    string schoolName; cin >> schoolName;
    School& school = School::getInstance(schoolName);

    while(true) {
        cout << "Enter Command: " << endl;
        string cmd; cin >> cmd;
        transform(begin(cmd), end(cmd), begin(cmd), [](char& c){return tolower(c);});
        Command c = getCommand(cmd);
        switch(c) {
            case ADD: {
                auto r = make_student();
                school.addStudent(r.first, r.second);
                break;
            }
            case DELETE: {
                cout << "Enter id : " << endl;
                string id; cin >> id;
                school.deleteStudent(id);
                break;
            }
            case FIND: {
                cout << "Enter id : " << endl;
                string id; cin >> id;
                auto r = school.findStudent(id);
                if (r) school.print(id);
                break;
            }
            case MODIFY: {
                cout << "Enter id, gpa : " << endl;
                string id; double gpa; cin >> id >> gpa;
                auto r = school.findStudent(id);
                if(r) school.modifyStudentGPA(id, gpa);
                break;
            }
            case PRINT: {
                school.print();
                // 자동으로 전부 반복한다.
                break;
            }
            case QUIT: {
                return 0;
            }
            case INVALID: {
                cout << "Invalid Command" << endl;
                break;
            }


        }
    }
}