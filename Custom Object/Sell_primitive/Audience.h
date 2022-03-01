#ifndef ASSIGMENT_AUDIENCE_H
#define ASSIGMENT_AUDIENCE_H
#include "Ticket.h"
#include <iostream>
class Audience {
public:
    Audience(std::string name) : name{name} {};
    Audience(std::string name, Ticket ticket) : name{name}, ticket{ticket}, hasTicket{true} {}
    std::string getName(){
        return name;
    }
    Ticket getTicket(){
        return ticket;
    }
    void setTicket(Ticket ticket){
        this->ticket = ticket;
    }
    bool isOwner() {
        return hasTicket;
    }
private:
    std::string name;
    bool hasTicket = false;
    Ticket ticket;
};
#endif //ASSIGMENT_AUDIENCE_H
