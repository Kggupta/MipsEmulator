#include "Bne.h"
#include "MipsClient.h"
#include "LabelTable.h"
#include "InvalidScan.h"
#include <string>
using namespace std;

void Bne::run(MipsClient & client, const LabelTable & table) const {
    int64_t s = client.getRegister(tokens.at(1).valAsNumber());
    int64_t t = client.getRegister(tokens.at(3).valAsNumber());
    if (s == t) return;

    if (tokens.at(5).getType() == Token::INT) {
        client.setPC(client.getPC() + tokens.at(5).valAsNumber() * 4);
        return;
    }
    string label = tokens.at(5).getValue();
    if (!table.labelExists(label)) throw InvalidScan("Label " + label + " does not exist.");
    client.setPC(table.getLine(label));
}

Bne::Bne(vector<Token> tokens): tokens{tokens} {}
