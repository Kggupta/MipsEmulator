#include "Mfhi.h"
#include "MipsClient.h"
using namespace std;
void Mfhi::run(MipsClient & client, const LabelTable & table) const {
    client.setRegister(tokens.at(1).valAsNumber(), client.getHi());
}

Mfhi::Mfhi(vector<Token> tokens): tokens{tokens} {}
