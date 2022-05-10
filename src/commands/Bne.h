#ifndef __BNE_H
#define __BNE_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> BREAK_PATTERN = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA,
                                            Token::Type::REGISTER, Token::Type::COMMA, Token::Type::INT};
const vector<Token::Type> BREAK_PATTERN2 = {Token::Type::ID, Token::Type::REGISTER, Token::Type::COMMA,
                                            Token::Type::REGISTER, Token::Type::COMMA, Token::Type::ID};

class Bne: public Command {
    vector<Token> tokens;

    public:
    Bne(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "bne"; }
};

#endif