#include "Audience.h"
#include "Ticket.h"
#include "TIcketOffice.h"
#include "TicketSeller.h"
#include "Theater.h"
#include "Logger.h"
#include <iostream>
#include <vector>
#include <memory>
int main() {
    Ticket ticket;
    Audience kim {"kim", ticket}; //티켓을 가진 kim
    Audience lee {"lee"};         //티켓 없는 lee
    Audience park {"park"};       //티켓 없는 park

    auto tickets = std::vector<Ticket> {10, Ticket()}; //10개의 티켓
    std::shared_ptr<TicketOffice> ticketOffice = \
    std::make_shared<TicketOffice>(1'000'000,tickets); //100만원치 티켓?
    auto ticketSeller = TicketSeller {ticketOffice}; //판매소 인자로 판매원 객체 생성

    Theater theater(ticketSeller); //극장 객체 생성
    theater.enter(kim);             //kim 입장 - 티켓 있으니까, Nice~ 출력
    theater.enter(lee);             //lee 입장 - 티켓 없으므로, The ticket~ 출력
    theater.enter(park);            //park 입장 - 티켓 없으므로, The ticket~ 출력

    std::cout << "\nReport the state of objects!\n" << std::endl;
    printTicketInfo("main()", tickets.size()); //위에서 10개의 티켓벡터 생성했으므로 10
    theater.report();   //
    ticketSeller.report();
    ticketOffice->report();

    return 0;
}