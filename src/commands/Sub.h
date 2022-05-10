#ifndef __SUB_H
#define __SUB_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> STD_PATTERN = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA,
                                            Token::Type::REGISTER, Token::Type::COMMA, Token::Type::REGISTER};

class Sub: public Command {
    vector<Token> tokens;

    public:
    Sub(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "sub"; }
};

#endif