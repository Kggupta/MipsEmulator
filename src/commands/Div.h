#ifndef __DIV_H
#define __DIV_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> DIV_PATTERN = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA,
                                            Token::Type::REGISTER};

class Div: public Command {
    vector<Token> tokens;

    public:
    Div(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "div"; }
};

#endif