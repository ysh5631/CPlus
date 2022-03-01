#ifndef ASSIGMENT_TICKETOFFICE_H
#define ASSIGMENT_TICKETOFFICE_H
#include "Logger.h"
#include <vector>
class TicketOffice {
public:
    TicketOffice(long amount, std::vector<Ticket>& tickets) : amount{amount}, tickets{tickets}{}
    Ticket getTicket() {
        Ticket ticket = *tickets.begin();
        tickets.erase(tickets.begin());
        return ticket;
    }
    void minusAmount(long amount){
        this->amount -= amount;
    }
    void plusAmount(long amount){
        this->amount += amount;
    }
    void report(std::string name="TicketOffice") const {
        printTicketInfo(name, tickets.size());
    }
private:
    long amount;
    std::vector<Ticket> tickets;
};

#endif //ASSIGMENT_TICKETOFFICE_H
