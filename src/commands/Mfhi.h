#ifndef __MFHI_H
#define __MFHI_H
#include "Command.h"
#include <vector>
using namespace std;

const vector<Token::Type> MFHI_PATTERN = {Token::Type::ID, Token::Type::REGISTER};

class Mfhi: public Command {
    vector<Token> tokens;

    public:
    Mfhi(vector<Token> tokens);
    void run( MipsClient & client, const LabelTable & table) const;
    static string cmd() { return "mfhi"; }
};

#endif