#ifndef __BEQ_H
#define __BEQ_H
#include "Command.h"
#include <vector>
using namespace std;

class Beq: public Command {
    vector<Token> tokens;

    public:
    Beq(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "beq"; }
};

#endif