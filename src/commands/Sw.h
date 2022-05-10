#ifndef __SW_H
#define __SW_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> SW_PATTERN = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA, Token::Type::INT, Token::Type::LPAREN, Token::Type::REGISTER, Token::Type::RPAREN};

class Sw: public Command {
    vector<Token> tokens;

    public:
    Sw(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "sw"; }
};

#endif