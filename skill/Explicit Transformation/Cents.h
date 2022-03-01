#ifndef ASSIGMENT_CENTS_H
#define ASSIGMENT_CENTS_H
class Cents{
    int cent = 0;
public:
    Cents();
    Cents(int cent) : cent(cent) {}
    explicit operator int() const {
        return cent*100;
    }
};
#endif //ASSIGMENT_CENTS_H
