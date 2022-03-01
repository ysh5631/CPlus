#ifndef ASSIGMENT_MEMBERSHIP_H
#define ASSIGMENT_MEMBERSHIP_H
#include <iostream>
using namespace std;
class Membership{
private:
    int remainCount;
public:
    Membership();
    Membership(int remainCount) : remainCount(remainCount) {}
    void use() {
        remainCount -= 1;
    }
    bool isAvailable(){
        if(remainCount > 0)
            return true;
        else
            return false;
    }
};
#endif //ASSIGMENT_MEMBERSHIP_H
