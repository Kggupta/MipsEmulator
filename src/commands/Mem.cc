#include "Mem.h"
#include "MipsClient.h"
#include <iomanip>
#include <iostream>
using namespace std;

void Mem::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getMemory(tokens.at(1).valAsNumber());
    cout << dec << tokens.at(1).valAsNumber() << ": " << "0x" << hex << std::setw(8) << std::setfill('0') << s << endl;
}

Mem::Mem(vector<Token> tokens): tokens{tokens} {}
