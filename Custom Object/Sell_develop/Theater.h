#ifndef ASSIGMENT_THEATER_H
#define ASSIGMENT_THEATER_H
#include <iostream>
#include <memory>
#include "Audience.h"
#include "TicketSeller.h"
using namespace std;
class Theater{
private:
    TicketSeller ticketSeller;
public:
    Theater(TicketSeller ticketSeller)\
    : ticketSeller(move(ticketSeller)) {}
    void enter(Audience& audience){
        getTicketSeller().sellTo(audience);
    }
    TicketSeller getTicketSeller(){
        return ticketSeller;
    }
};
#endif //ASSIGMENT_THEATER_H
