#include "String.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
String::String() {
    len = 0;
    s = new char[1];
    s[0] = '\0';
}

String::String(const char *str) {
    if(str == nullptr)
        str = "";
    s = new char[strlen(str) + 1];
    len = strlen(str);

    for(int i=0;i<=len;i++)
        s[i] = str[i];
}

String::String(const String &str) : s(new char[str.len + 1]), len(str.len){
    for(int i=0; i<=len;i++)
        s[i] = str.s[i];
}

String::String(String &&str) noexcept : s(std::move(str.s)), len(std::move(str.len)) {
    str.s = new char [1];
    str.s[0] = '\0' ;
    str.len = 0;
}

String& String::operator=(const String &str) {
    String tmp(str);
    swap(tmp);
    return *this;
}

String& String::operator=(String &&str) noexcept {
    if(this == &str) return *this;

    String tmp = move(str);
    swap(tmp);

    str.s = new char[1];
    str.s[0] = '\0';

    str.len = 0;
    return *this;

}

void String::swap(String& str){
    using std::swap;
    swap(s, str.s);
    swap(len, str.len);
}

String::~String() {
    if(s) delete[] s;
}

const char* String::data() const {
    return s;
}

char& String::at(size_t pos){
    if(len!=0 && 0 <= pos && pos < len)
        return s[pos];
    throw std::out_of_range("out of range at index: " + std::to_string(pos) + ", but the length of String is " + std::to_string(len));
}

size_t String::size() const {
    return len;
}

void String::print(const char* str) const {
    // std::cout << str << ": " << s << ", size: " << len << " address: " << (void *) s << std::endl;
    std::cout << str << ": " << s << ", size: " << len << std::endl;
}

bool String::operator == (const String& str) const{
    for(int i=0;i<str.len;i++)
        if(s[i] != str.s[i])
            return 0;
    return 1;
}

ostream& operator << (ostream& os, const String& str){
    os << str.s << endl;
    return os;
}