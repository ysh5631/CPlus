#ifndef ASSIGMENT_TICKET_H
#define ASSIGMENT_TICKET_H
class Ticket {
public:
    long getFee() {
        return fee;
    }
private:
    long fee = 10'000;
};

#endif //ASSIGMENT_TICKET_H
