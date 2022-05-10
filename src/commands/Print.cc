#include "Print.h"
#include "MipsClient.h"
#include <iomanip>
#include <iostream>
using namespace std;

void Print::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(1).valAsNumber());
    cout << tokens.at(1).valAsNumber() << ": " << "0x" << hex << std::setw(8) << std::setfill('0') << s << endl;
}

Print::Print(vector<Token> tokens): tokens{tokens} {}
