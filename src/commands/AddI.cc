#include "AddI.h"
#include "MipsClient.h"
using namespace std;
void AddI::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(3).valAsNumber());
    int64_t t = tokens.at(5).valAsNumber();

    client.setRegister(tokens.at(1).valAsNumber(), s+t);
}

AddI::AddI(vector<Token> tokens): tokens{tokens} {}
