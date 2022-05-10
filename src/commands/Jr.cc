#include "Jr.h"
#include "MipsClient.h"
#include "InvalidScan.h"
#include "EndProgram.h"
using namespace std;

void Jr::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(1).valAsNumber());
    if (s == -1) throw EndProgram("Successfully ended program.");
    if (s % 4 != 0) throw InvalidScan("Unaligned Access to Program Counter");
    client.setPC(s);
}

Jr::Jr(vector<Token> tokens): tokens{tokens} {}
