#ifndef __JR_H
#define __JR_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> JR_PATTERN = {Token::Type::ID, Token::Type::REGISTER};

class Jr: public Command {
    vector<Token> tokens;

    public:
    Jr(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "jr"; }
};

#endif