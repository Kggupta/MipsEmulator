#ifndef __INVALSCAN_H
#define __INVALSCAN_H
#include <exception>
#include <string>

class InvalidScan {
    std::string message;

    public:
    InvalidScan(std::string message): message{message} {};

    const std::string what() const { return message; };
};
#endif