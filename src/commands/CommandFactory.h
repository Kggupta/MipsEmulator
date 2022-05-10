#ifndef __CMDFACTORY_H
#define __CMDFACTORY_H
#include "Command.h"

class CommandFactory {
    public:
    Command * create(vector<Token> & tokenLine);
};

#endif