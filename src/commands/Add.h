#ifndef __ADD_H
#define __ADD_H
#include "Command.h"
#include <vector>
using namespace std;

class Add: public Command {
    vector<Token> tokens;

    public:
    Add(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "add"; }
};

#endif