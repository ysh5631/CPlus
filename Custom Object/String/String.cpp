#include "String.h"
#include <exception>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

String::String() {
    cout << "default constructor" << endl;
}

String::String(const char* s)  {
    for(int i=0;i<strlen(s);i++)
        _data.push_back(s[i]);
    cout << "constructor with the one argument" << endl;
}

String::~String() noexcept {
    delete [] data();
    cout << "destructor" << endl;
}

String::String(String&& s) noexcept : _data(move(s._data)) {
    s._data.clear();
    cout << "move constructor" << endl;
}

String::String(const String& s) noexcept {
    copy(s._data.begin(),s._data.end(), back_inserter(_data));
    cout << "copy constructor" << endl;
}

const char* String::data() const {
    char* str = new char[_data.size()];
    copy(_data.begin(),_data.end(),str);
    return str;
}

bool String::empty() const {
    if(_data.size() == 0)
        return true;
    else
        return false;
}

size_t String::size() const {
    return _data.size();
}


String& String::append(const String& s) {
    _data.pop_back();

    for(auto& c : s._data)
        _data.push_back(c);
    return *this;
}

String& String::append(const char* s) {
    for(int i=0;i<strlen(s);i++)
        _data.push_back(s[i]);
    return *this;
}


int String::compare(const String& s) const {
    int j = 0;
    for(auto& c : s._data){
        if(_data[j] != c)
            return -1;
        j++;
    }
    return 0;
}

int String::compare(const char* s) const {
    int i = 0;
    for(auto& c : _data){
        if(s[i] != c)
            return -1;
        i++;
    }
    return 0;
}
