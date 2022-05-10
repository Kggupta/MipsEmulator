#include "Mflo.h"
#include "MipsClient.h"
using namespace std;
void Mflo::run(MipsClient & client, const LabelTable & table) const {
    client.setRegister(tokens.at(1).valAsNumber(), client.getLo());
}

Mflo::Mflo(vector<Token> tokens): tokens{tokens} {}
