#ifndef ASSIGMENT_AUDIENCE_H
#define ASSIGMENT_AUDIENCE_H
#include <iostream>
#include "Membership.h"
#include "Ticket.h"
#include <iostream>
#include <vector>
using namespace std;
class Audience{
private:
    Membership membership;
    Ticket ticket;
    long money;
public:
    Audience() {}
    Audience(long money, int remainCount) : money(money), membership(remainCount){}
    long buy(){
        if(membership.isAvailable()){
            membership.use();
            return 0;
        } else{
            money -= ticket.getFee();
            return ticket.getFee();
        }
    }
};
#endif //ASSIGMENT_AUDIENCE_H
