#include "MipsClient.h"
#include "InvalidScan.h"
#include "MipsDFA.h"
#include <iomanip>
#include <fstream>

MipsClient::MipsClient() {
    registers[30] = -1;
}

int64_t MipsClient::getPC() const { return programCounter; }

void MipsClient::incrementPC() { programCounter += 4; }

void MipsClient::setPC(int64_t newPC) { programCounter = newPC; }

void MipsClient::setHi(int64_t val) {hi = val;}
void MipsClient::setLo(int64_t val) {lo = val;}

int64_t MipsClient::getHi() const {return hi;}
int64_t MipsClient::getLo() const {return lo;}

void MipsClient::setRegister(int reg, int64_t val) {
    if (reg == CONST_REGISTER) return;
    registers[reg - 1] = val;
}

int64_t MipsClient::getRegister(int reg) const {
    if (reg < 1 || reg > NUM_REGISTERS) throw InvalidScan("Register out of bounds: $" + to_string(reg));
    return registers[reg - 1];
}

int64_t MipsClient::getMemory(int64_t address) const {
    if (address % 4 != 0) throw InvalidScan("Unaligned memory access at: " + to_string(address));

    return memory[address / 4];
}

void MipsClient::setMemory(int64_t address, int64_t val) {
    if (address % 4 != 0) throw InvalidScan("Unaligned memory access at: " + to_string(address));
    memory[address / 4] = val;
} 

void MipsClient::configure(string file) {
    ifstream myfile;
    myfile.open(file);
    string line;

    while(getline(myfile, line)) {
        vector<Token> tokens = MipsDFA::tokenize(line);

        if (tokens.at(0).getValue() == "r") {
            setRegister(tokens.at(1).valAsNumber(), tokens.at(3).valAsNumber());
        } else if (tokens.at(0).getValue() == "m") {
            setMemory(tokens.at(1).valAsNumber(), tokens.at(3).valAsNumber());
        } else {
            throw InvalidScan("Invalid configuration.\n-     " + line);
        }
    }
}

ostream& operator<<(ostream& os, const MipsClient& client) {
    cout << "--------------------" << endl << "MIPS EMULATOR" << endl << "--------------------" << endl;
    for (int i = 0; i < NUM_REGISTERS; i++) {
        if (i % 5 == 0 && i != 0) cout << endl;

        cout << dec << i + 1 << ": " << "0x" << std::hex << std::setw(8) << std::setfill('0') << client.getRegister(i + 1) << " ";
    }
    return os;
}
