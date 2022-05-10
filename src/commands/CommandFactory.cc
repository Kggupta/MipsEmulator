#include "CommandFactory.h"
#include "Add.h"
#include "AddI.h"
#include "Mult.h"
#include "Sub.h"
#include "Div.h"
#include "Mfhi.h"
#include "Mflo.h"
#include "Beq.h"
#include "Bne.h"
#include "Jr.h"
#include "Lw.h"
#include "Sw.h"
#include "Slt.h"
#include "Print.h"
#include "Mem.h"
#include "Command.h"
using namespace std;

bool isMatch(vector<Token> & tokens, vector<Token::Type> pattern) {
    if (pattern.size() != tokens.size()) return false;
    for (size_t i = 0; i < tokens.size(); i++) {
        if (pattern.at(i) != tokens.at(i).getType()) return false;
    }
    return true;
}


// This is alot of if statements and repeated code
// I want to come back to this and improve the implementation in the future.
Command * CommandFactory::create(vector<Token> & tokens) {
    string cmd = tokens.at(0).getValue();
    if (cmd == Add::cmd()) {
        if (!isMatch(tokens, STD_PATTERN)) return nullptr;
        return new Add(tokens);
    } else if (cmd == Sub::cmd()) {
        if (!isMatch(tokens, STD_PATTERN)) return nullptr;
        return new Sub(tokens);
    } else if (cmd == Mult::cmd()) {
        if (!isMatch(tokens, MULT_PATTERN)) return nullptr;
        return new Mult(tokens);
    } else if (cmd == AddI::cmd()) {
        if (!isMatch(tokens, IMMEDIATE_PATTERN)) return nullptr;
        return new AddI(tokens);
    } else if (cmd == Div::cmd()) {
        if (!isMatch(tokens, DIV_PATTERN)) return nullptr;
        return new Div(tokens);
    } else if (cmd == Mfhi::cmd()) {
        if (!isMatch(tokens, MFHI_PATTERN)) return nullptr;
        return new Mfhi(tokens);
    } else if (cmd == Mflo::cmd()) {
        if (!isMatch(tokens, MFLO_PATTERN)) return nullptr;
        return new Mflo(tokens);
    } else if (cmd == Beq::cmd()) {
        if (!isMatch(tokens, BREAK_PATTERN) && !isMatch(tokens, BREAK_PATTERN2)) return nullptr;
        return new Beq(tokens);
    } else if (cmd == Bne::cmd()) {
        if (!isMatch(tokens, BREAK_PATTERN) && !isMatch(tokens, BREAK_PATTERN2)) return nullptr;
        return new Bne(tokens);
    } else if (cmd == Jr::cmd()) {
        if (!isMatch(tokens, JR_PATTERN)) return nullptr;
        return new Jr(tokens);
    } else if (cmd == Lw::cmd()) {
        if (!isMatch(tokens, LW_PATTERN)) return nullptr;
        return new Lw(tokens);
    } else if (cmd == Sw::cmd()) {
        if (!isMatch(tokens, SW_PATTERN)) return nullptr;
        return new Sw(tokens);
    } else if (cmd == Slt::cmd()) {
        if (!isMatch(tokens, STD_PATTERN)) return nullptr;
        return new Slt(tokens);
    } else if (cmd == Print::cmd()) {
        if (!isMatch(tokens, JR_PATTERN)) return nullptr;
        return new Print(tokens);
    } else if (cmd == Mem::cmd()) {
        if (!isMatch(tokens, JR_PATTERN)) return nullptr;
        return new Mem(tokens);
    }
    return nullptr;
}