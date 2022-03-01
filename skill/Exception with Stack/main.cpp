#include "Stack.h"
#include "StackException.h"
#include <iostream>
using namespace std;
int main(){
    try{
        Stack<char> stack(1);
        stack.push('a');
        stack.pop(); stack.pop();

        stack.print();
    } catch(const StackException& e) { cerr << e.what() << endl;}
}

//int main(){
//    Stack<char> stack(1);
//    stack.push('a');
//    stack.push('b');
//
//    stack.print();
//}
//
//int main(){
//    Stack<int> stack(1);
//    stack.push(1);  stack.pop();
//    stack.push(2);
//
//    stack.print(); // 2 출력됨.
//    stack.pop();
//}
//
//int main(){
//    Stack<char> stack(2);
//    stack.push(1); stack.push(2);
//    stack.pop(); stack.pop();
//    stack.push(3);
//
//    stack.print(); // 3 출력됨.
//}