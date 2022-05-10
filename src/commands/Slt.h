#ifndef __SLT_H
#define __SLT_H
#include "Command.h"
#include <vector>
using namespace std;

class Slt: public Command {
    vector<Token> tokens;

    public:
    Slt(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "slt"; }
};

#endif