#ifndef __ADDI_H
#define __ADDI_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> IMMEDIATE_PATTERN = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA,
                                            Token::Type::REGISTER, Token::Type::COMMA, Token::Type::INT};

class AddI: public Command {
    vector<Token> tokens;

    public:
    AddI(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "addi"; }
};

#endif