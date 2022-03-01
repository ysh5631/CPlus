#ifndef ASSIGMENT_STACK_H
#define ASSIGMENT_STACK_H
#include "StackException.h"
#include <iostream>
using namespace std;
template<typename T>
class Stack {
public:
    Stack(int sz) :size(sz) {s = new T[size];}
    ~Stack() noexcept {
        if(s) delete[] s;
    }
    // 복사 생성자와 복사 대입 연산자를 삭제하시오
    void push(T c) {
        if(top >= size) throw StackException("Stack is full!","main.cpp",0);
        s[top++] = c ;
    }
    T pop() {
        if(top == 0) throw StackException("Stack is empty!","main.cpp",0);
        T r = s[--top];
        return r ;
    }
    void print() const {
        for(int i=0;i<size;i++)
            cout << s[i] << endl;
    }
private:
    int size = 0;   int top = 0;
    T* s = nullptr;
} ;
#endif //ASSIGMENT_STACK_H