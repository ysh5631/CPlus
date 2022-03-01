#ifndef ASSIGMENT_LOGGER_H
#define ASSIGMENT_LOGGER_H
#include <string>
#include <iostream>
void printTicketInfo(std::string className, long size){
    std::cout << "# of tickets in " << className << ": " << size<< std::endl;
}
#endif //ASSIGMENT_LOGGER_H
