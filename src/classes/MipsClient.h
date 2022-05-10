#ifndef __MIPSCLIENT_H
#define __MIPSCLIENT_H

#include <vector>
#include <stdint.h>
#include <iostream>
using namespace std;

const int NUM_REGISTERS = 31;
const int CONST_REGISTER = 31;
const int MAX_MEM = 1024;

class MipsClient {
    int32_t registers[31] = {0};
    int32_t memory[1024] = {0};
    int64_t programCounter = 0;
    int32_t lo = 0;
    int32_t hi = 0;

    public:
    MipsClient();
    /**
     * @brief Get the current program counter
     * 
     * @return int64_t 
     */
    int64_t getPC() const;

    /**
     * @brief Increment the program counter to the next line
     * 
     */
    void incrementPC();

    /**
     * @brief Jump to a new command
     * 
     * @param newPC New command address
     */
    void setPC(int64_t newPC);

    /**
     * @brief Set register #reg to val
     * 
     * @param reg The register to set
     * @param val The 
     */
    void setRegister(int reg, int32_t val);

    /**
     * @brief Get register #reg
     * 
     * @param reg The register to get
     * @return int32_t 
     */
    int32_t getRegister(int reg) const;

    /**
     * @brief Get memory at address. Must be a multiple of 4.
     * 
     * @param address The address to the block of memory
     * @return int32_t 
     */
    int32_t getMemory(uint32_t address) const;

    /**
     * @brief Set the memory at address to val
     * 
     * @param address Address to memory
     * @param val The value to set
     */
    void setMemory(uint32_t address, int32_t val);

    /**
     * @brief Change the lo register to val
     * 
     * @param val 
     */
    void setLo(int32_t val);

    /**
     * @brief Change the hi register to val
     * 
     * @param val 
     */
    void setHi(int32_t val);

    /**
     * @brief Get the Lo register
     * 
     * @return int32_t 
     */
    int32_t getLo() const;

    /**
     * @brief Get the Hi register
     * 
     * @return int32_t 
     */
    int32_t getHi() const;

    /**
     * @brief Output the mips registers
     * 
     * @param os 
     * @param client 
     * @return ostream& 
     */
    friend ostream& operator<<(ostream& os, const MipsClient& client);

};

#endif