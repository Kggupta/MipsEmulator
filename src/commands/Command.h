#ifndef __CMD_H
#define __CMD_H
#include "Token.h"
#include <vector>
class MipsClient;
class LabelTable;
using std::vector;

class Command {
    public:
    virtual void run( MipsClient & client, const LabelTable & table) const = 0;
    static string cmd();
    virtual ~Command() {return;}
};

#endif