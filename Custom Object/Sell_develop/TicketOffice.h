#ifndef ASSIGMENT_TICKETOFFICE_H
#define ASSIGMENT_TICKETOFFICE_H
#include <iostream>
#include <vector>
#include "Ticket.h"
using namespace std;
class TicketOffice{
private:
    vector<Ticket> tickets;
    long amount = 100'000;
public:
    TicketOffice() = default;
    TicketOffice(vector<Ticket> tickets) : tickets(move(tickets)) {}
    vector<Ticket> getTicketOffice(){
        return tickets;
    }
    void plusAmount(long amount) {
        this->amount += amount;
    }
};

#endif //ASSIGMENT_TICKETOFFICE_H
