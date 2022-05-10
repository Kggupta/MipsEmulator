#include "Add.h"
#include "MipsClient.h"
using namespace std;
void Add::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(3).valAsNumber());
    int64_t t = client.getRegister(tokens.at(5).valAsNumber());

    client.setRegister(tokens.at(1).valAsNumber(), s+t);
}

Add::Add(vector<Token> tokens): tokens{tokens} {}
