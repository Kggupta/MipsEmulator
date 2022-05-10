#ifndef __LW_H
#define __LW_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> LW_PATTERN = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA, Token::Type::INT, Token::Type::LPAREN, Token::Type::REGISTER, Token::Type::RPAREN};

class Lw: public Command {
    vector<Token> tokens;

    public:
    Lw(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "lw"; }
};

#endif