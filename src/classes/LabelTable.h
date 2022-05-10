#ifndef __LABELTABLE_H
#define __LABELTABLE_H

#include <map>
#include <string>
#include "Token.h"
#include <vector>
using std::vector;
using std::map;
using std::string;

class LabelTable {
    map<string, uint64_t> labels;
    uint64_t lineNumber = 0;

    /**
     * @brief Adds a label to the table along with the address line
     * 
     * @param name Label name
     * @param line Address to line
     */
    void addLabel(string name, uint64_t line);

    public:
    /**
     * @brief Return if the label exists in the table
     * 
     * @param name The name of the label to search
     * @return true 
     * @return false 
     */
    bool labelExists(string name) const;

    /**
     * @brief Gets the address location of a label name (label must exist in table)
     * 
     * @param name Label name
     * @return uint64_t
     */
    uint64_t getLine(string label) const;
    
    /**
     * @brief Populates the label table using the given tokenized assembly instruction
     * 
     * @param tokenLine Tokenized assembly instruction
     */
    void buildLabelTable(vector<Token> & tokenLine);

    /**
     * @brief Remove all labels from the tokens
     * 
     * @param tokenLine - tokenized assembly instruction
     */
    static void cleanLabels(vector<Token> & tokens);
};

#endif