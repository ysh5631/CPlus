#ifndef ASSIGMENT_STRING_H
#define ASSIGMENT_STRING_H
#include <stddef.h>
#include <iostream>
using namespace std;
class String {
public:
    String();
    String(const char* str);
    String(const String& str);
    String& operator=(const String& str);
    String(String&& str) noexcept;
    String& operator=(String&& str) noexcept;
    ~String();
    const char* data() const;
    char& at(size_t);
    size_t size() const;
    void print(const char* str="") const;
    bool operator == (const String& str) const;
    friend ostream& operator << (ostream& os, const String& s);
private:
    void swap(String& str);
    int len;
    char* s;
};
#endif //ASSIGMENT_STRING_H
