#ifndef ASSIGMENT_TICKETSELLER_H
#define ASSIGMENT_TICKETSELLER_H
#include "TicketOffice.h"
#include "Audience.h"
#include <iostream>
#include <memory>
using namespace std;
class TicketSeller{
private:
    TicketOffice ticketOffice;
public:
    TicketSeller(TicketOffice ticketOffice)\
    : ticketOffice(move(ticketOffice)) {}
    void sellTo(Audience audience){
        long amount = audience.buy();
        ticketOffice.plusAmount(amount);
        ticketOffice.getTicketOffice().erase(ticketOffice.getTicketOffice().begin());
    }
};
#endif //ASSIGMENT_TICKETSELLER_H
