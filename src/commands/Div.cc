#include "Div.h"
#include "MipsClient.h"
using namespace std;
void Div::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(3).valAsNumber());
    int64_t t = client.getRegister(tokens.at(5).valAsNumber());

    int64_t res = s / t;
    int64_t rem = s % t;

    client.setLo(res);
    client.setHi(rem);
}

Div::Div(vector<Token> tokens): tokens{tokens} {}
