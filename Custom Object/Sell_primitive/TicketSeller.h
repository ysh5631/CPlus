#ifndef ASSIGMENT_TICKETSELLER_H
#define ASSIGMENT_TICKETSELLER_H
#include <memory>
class TicketSeller {
public:
    TicketSeller(std::shared_ptr<TicketOffice>& ticketOffice): ticketOffice(ticketOffice){}
    TicketOffice& getTicketOffice() {
        return *ticketOffice;
    }
    void report(){
        ticketOffice->report("TicketSeller > TicketOffice");
    }
private:
     std::shared_ptr<TicketOffice> ticketOffice;
};

#endif //ASSIGMENT_TICKETSELLER_H
