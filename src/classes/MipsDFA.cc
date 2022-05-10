#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <utility>
#include <set>
#include <array>
#include "MipsDFA.h"
using namespace std;

Token::Type MipsDFA::toType(States state) const {
    switch (state) {
        case ID: return Token::ID;
        case LABEL: return Token::LABEL;
        case COMMA: return Token::COMMA;
        case LPAREN: return Token::LPAREN;
        case RPAREN: return Token::RPAREN;
        case INT: return Token::INT;
        case ZERO: return Token::INT;
        case HEXINT: return Token::HEXINT;
        case REGISTER: return Token::REGISTER;
        case WSPACE: return Token::WSPACE;
        case COMMENT: return Token::COMMENT;
        default: throw InvalidScan("Invalid Tokenization : Could not tokenize program.");
    }
    return Token::FAIL; // Should never run
}

MipsDFA::MipsDFA() {
    for (size_t src = 0; src < transitions.size(); src++) {
        for (size_t dest = 0; dest < transitions[0].size(); dest++) {
            transitions[src][dest] = FAIL;
        }
    }

    // A simple DFA that tokenizes MIPS code.
    // What's great about this is that it can easily be converted into an ARM dfa sice the general syntax is similar.
    transition(START, ID, isalpha);
    transition(START, ZERO, "0");
    transition(START, INT, "123456789");
    transition(START, DASH, "-");
    transition(START, COMMENT, ";");
    transition(START, WSPACE, isspace);
    transition(START, DOLLAR, "$");
    transition(START, COMMA, ",");
    transition(START, LPAREN, "(");
    transition(START, RPAREN, ")");
    transition(ID, ID, isalnum);
    transition(ID, LABEL, ":");
    transition(ZERO, ZEROHEX, "x");
    transition(ZERO, INT, isdigit);
    transition(ZEROHEX, HEXINT, isxdigit);
    transition(HEXINT, HEXINT, isxdigit);
    transition(DASH, INT, isdigit);
    transition(INT, INT, isdigit);
    transition(COMMENT, COMMENT, [](int val) -> int {return val != '\n';});
    transition(WSPACE, WSPACE, isspace);
    transition(DOLLAR, REGISTER, isdigit);
    transition(REGISTER, REGISTER, isdigit);
}

vector<Token> MipsDFA::munch(const string &in) const {
    vector<Token> res;

    States curState = START;
    string munched;

    for (string::const_iterator inPos = in.begin(); inPos != in.end();) {
        States src = curState;
        curState = destination(curState, *inPos);
        if (!isFailed(curState)) {
            munched += *inPos;
            src = curState;
            inPos ++;
        }

        if (inPos == in.end() || isFailed(curState)) {
            if (isAccept(src)) {
                res.push_back(Token(toType(src), munched));
                munched = "";
                curState = START;
            } else {
                if (isFailed(curState)) {
                    munched += *inPos;
                }
                throw InvalidScan("Invalid Scan : Could not tokenize " + munched + ".");
            }
        }
    }
    
    return res;
}

void MipsDFA::transition(States src, States dest, const string & read) {
    for (char c : read) {
        transitions[src][c] = dest;
    }
}

void MipsDFA::transition(States src, States dest, int (*test)(int)) {
    for (int i = 0; i < TRANSITION_NUM; i++) {
        if (test(i)) { transitions[src][i] = dest; }
    }
}

MipsDFA::States MipsDFA::destination(States src, char read) const {
    return transitions[src][read];
}

bool MipsDFA::isFailed(States state) const {
    return state == FAIL;
}

bool MipsDFA::isAccept(States state) const {
    return accepting.count(state) != 0;
}

vector<Token> MipsDFA::tokenize(const string & in) {
    static MipsDFA mips;

    vector<Token> tokens = mips.munch(in);

    vector<Token> cleaned;

    for (auto & token : tokens) {
        if (token.getType() == Token::WSPACE || token.getType() == Token::Type::COMMENT) continue;
        cleaned.push_back(token);
    }
    return cleaned;
}