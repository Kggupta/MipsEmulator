#ifndef __MEM_H
#define __MEM_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> MEM_PATTERN = {Token::Type::ID, Token::Type::HEXINT};

class Mem: public Command {
    vector<Token> tokens;

    public:
    Mem(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "mem"; }
};

#endif