#ifndef __PRINT_H
#define __PRINT_H
#include "Command.h"
#include <vector>
using namespace std;

class Print: public Command {
    vector<Token> tokens;

    public:
    Print(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "pri"; }
};

#endif