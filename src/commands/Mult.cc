#include "Mult.h"
#include "MipsClient.h"
using namespace std;
void Mult::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(3).valAsNumber());
    int64_t t = client.getRegister(tokens.at(5).valAsNumber());

    int64_t res = s * t;

    client.setLo(res);
    client.setHi(res >> 32);
}

Mult::Mult(vector<Token> tokens): tokens{tokens} {}
