#include "MipsClient.h"
#include "InvalidScan.h"
#include <iomanip>

MipsClient::MipsClient() {
    registers[30] = -1;
}

int64_t MipsClient::getPC() const { return programCounter; }

void MipsClient::incrementPC() { programCounter += 4; }

void MipsClient::setPC(int64_t newPC) { programCounter = newPC; }

void MipsClient::setHi(int32_t val) {hi = val;}
void MipsClient::setLo(int32_t val) {lo = val;}

int32_t MipsClient::getHi() const {return hi;}
int32_t MipsClient::getLo() const {return lo;}

void MipsClient::setRegister(int reg, int32_t val) {
    if (reg == CONST_REGISTER) return;
    registers[reg - 1] = val;
}

int32_t MipsClient::getRegister(int reg) const {
    if (reg < 1 || reg > NUM_REGISTERS) throw InvalidScan("Register out of bounds: $" + to_string(reg));
    return registers[reg - 1];
}

int32_t MipsClient::getMemory(uint32_t address) const {
    if (address % 4 != 0) throw InvalidScan("Unaligned memory access at: " + to_string(address));

    return memory[address / 4];
}

void MipsClient::setMemory(uint32_t address, int32_t val) {
    if (address % 4 != 0) throw InvalidScan("Unaligned memory access at: " + to_string(address));
    memory[address / 4] = val;
} 

ostream& operator<<(ostream& os, const MipsClient& client) {
    cout << "--------------------" << endl << "MIPS EMULATOR" << endl << "--------------------" << endl;
    for (int i = 0; i < NUM_REGISTERS; i++) {
        if (i % 5 == 0 && i != 0) cout << endl;

        cout << dec << i + 1 << ": " << "0x" << std::hex << std::setw(8) << std::setfill('0') << client.getRegister(i + 1) << " ";
    }
    return os;
}
