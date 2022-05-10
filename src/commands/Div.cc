#include "Div.h"
#include "MipsClient.h"
using namespace std;
void Div::run(MipsClient & client, const LabelTable & table) const {
    int32_t s = client.getRegister(tokens.at(3).valAsNumber());
    int32_t t = client.getRegister(tokens.at(5).valAsNumber());

    int32_t res = s / t;
    int32_t rem = s % t;

    client.setLo(res);
    client.setHi(rem);
}

Div::Div(vector<Token> tokens): tokens{tokens} {}
