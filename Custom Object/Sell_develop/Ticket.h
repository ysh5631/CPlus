#ifndef ASSIGMENT_TICKET_H
#define ASSIGMENT_TICKET_H
#include <iostream>
using namespace std;
class Ticket{
private:
    long fee = 10'000;
public:
    Ticket() = default;
    Ticket(long fee) : fee(fee) {}
    long getFee() {return fee;}
};

#endif //ASSIGMENT_TICKET_H
