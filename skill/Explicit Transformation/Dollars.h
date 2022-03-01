#ifndef ASSIGMENT_DOLLARS_H
#define ASSIGMENT_DOLLARS_H
#include "Cents.h"
class Dollars{
    int dollar = 0;
public:
    Dollars();
    Dollars(int dollar) : dollar(dollar) {}
    explicit operator Cents() const {
        static Cents ce(dollar);
        return ce;
    }
};
#endif //ASSIGMENT_DOLLARS_H
