#include "Lw.h"
#include "MipsClient.h"
#include "InvalidScan.h"
using namespace std;
void Lw::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(5).valAsNumber());
    int64_t i = tokens.at(3).valAsNumber();
    if ((s+i) % 4 != 0) throw InvalidScan("Unaligned Access to memory.");
    if (s + i > MAX_MEM * 4 || s + i < 0) throw InvalidScan("Memory access out of bounds");

    client.setRegister(tokens.at(1).valAsNumber(), client.getMemory(s+i));
}

Lw::Lw(vector<Token> tokens): tokens{tokens} {}
