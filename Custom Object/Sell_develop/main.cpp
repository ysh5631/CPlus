#include "Theater.h"
#include "Ticket.h"
#include "TicketSeller.h"
#include "TicketOffice.h"
#include "theater.h"
#include <vector>
#include <iostream>

using namespace std;
int main() {
    std::vector <Ticket> tickets{{10'000},{10'000},{10'000}};
    TicketOffice ticketOffice{tickets};
    TicketSeller ticketSeller{ticketOffice};
    Theater theater{ticketSeller};
    Audience audience{100'000, {3}};
    theater.enter(audience);
}