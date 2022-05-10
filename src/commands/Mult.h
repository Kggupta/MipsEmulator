#ifndef __MULT_H
#define __MULT_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> MULT_PATTERN = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA,
                                            Token::Type::REGISTER};

class Mult: public Command {
    vector<Token> tokens;

    public:
    Mult(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "mult"; }
};

#endif