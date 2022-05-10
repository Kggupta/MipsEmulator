#ifndef __ENDPRGM_H
#define __ENGPRGM_H
#include <exception>
#include <string>

class EndProgram {
    std::string message;

    public:
    EndProgram(std::string message): message{message} {};

    const std::string what() const { return "Successfully ended program." + message; };
};

#endif