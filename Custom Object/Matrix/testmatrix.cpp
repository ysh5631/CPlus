#include "matrix.h"
#include <iostream>
#include <cassert>
using namespace std;

//-----test1-------
int main() {
    matrix m1 = {{1,2}, {3, 4}};
    matrix m2 = {{5,6}, {7, 8}};

    matrix m3 (m1 + m2);
    matrix m4;

    m4 = m3;
    cout << m4 << endl;
    cout << m4.size().first << " " << m4.size().second << endl;
}

//-----test2-------
//int main() {
//    matrix m = {{1,1}, {1,1}};
//    matrix n = {{2,2}, {2,2}};
//
//    m = n;
//    assert(m==n);
//    n = {{3,3}, {3,3}};
//
//    assert(!(m==n));
//    cout << m << endl;
//    cout << n << endl;
//}

//-----test3-------
//int main() {
//    matrix m11 = {{1,2},{3,4}};
//    matrix m22 = {{5,6},{7,8}};
//
//    cout << m11.transpose() << endl;
//    cout << m22.transpose() << endl;
//}