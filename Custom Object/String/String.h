#ifndef ASSIGMENT_STRING_H
#define ASSIGMENT_STRING_H
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

class String {
public:
    String() ;
    String(const char* s) ;
    ~String() noexcept ;
    String(String&& s)  noexcept;
    String& operator=(String&& s) noexcept {
        std::cout << "move assignment operator" << std::endl;
        String tmp(std::move(s));
        swap(tmp);
        return *this;
    }
    String(const String& s) noexcept ;
    String& operator=(const String& s) noexcept {
        std::cout << "copy assignment operator" << std::endl;
        String tmp(s);
        swap(tmp);
        return *this;
    }
public:
    const char* data() const;
    bool empty() const;
    size_t size() const;
    String& append(const String& str);
    String& append(const char* str);
    int compare(const String& s) const;
    int compare(const char* s) const;
private:
    std::vector<char> _data;
    void swap(String& other) noexcept {
        using std::swap;
        swap(this->_data, other._data);
    };
};
#endif //ASSIGMENT_STRING_H
