#ifndef __MFLO_H
#define __MFLO_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> MFLO_PATTERN = {Token::Type::ID, Token::Type::REGISTER};

class Mflo: public Command {
    vector<Token> tokens;

    public:
    Mflo(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "mflo"; }
};

#endif