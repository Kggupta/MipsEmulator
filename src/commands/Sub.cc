#include "Sub.h"
#include "MipsClient.h"
using namespace std;
void Sub::run(MipsClient & client, const LabelTable & table) const {
    int32_t s = client.getRegister(tokens.at(3).valAsNumber());
    int32_t t = client.getRegister(tokens.at(5).valAsNumber());

    client.setRegister(tokens.at(1).valAsNumber(), s-t);
}

Sub::Sub(vector<Token> tokens): tokens{tokens} {}
