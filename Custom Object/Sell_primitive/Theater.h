#ifndef ASSIGMENT_THEATER_H
#define ASSIGMENT_THEATER_H
class Theater {
public:
    Theater(TicketSeller& ticketSeller) : ticketSeller(ticketSeller){}
    void enter(Audience audience) {
        if(!audience.isOwner()){ //티켓 없음.
            // 티켓 가지고 있는사람한테 판매원을통해 티켓팔고, 티켓판매소 벡터에서 삭제
            Ticket ticket = ticketSeller.getTicketOffice().getTicket();
            std::cout << "The ticket price is " << ticket.getFee() << " WON."  << std::endl;
            // 판매원 객체를 통해, 판매소의 plusAmount함수 접근, 티켓 1장 값 더해줌.
            ticketSeller.getTicketOffice().plusAmount(ticket.getFee());
            // 관람객에게 티켓을 줌.
            audience.setTicket(ticket);
        }
        std::cout << "Nice to meet you " << audience.getName() << "! Please enter the theater." << std::endl;
    }
    void report() {
        ticketSeller.getTicketOffice().report("Theater > TicketSeller > TicketOffice");
    }
private:
    TicketSeller ticketSeller;
};
#endif //ASSIGMENT_THEATER_H
