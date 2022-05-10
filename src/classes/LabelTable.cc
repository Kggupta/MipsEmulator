#include "LabelTable.h"
#include "InvalidScan.h"
using std::pair;


void LabelTable::addLabel(string name, int64_t line) {
    labels.insert(pair<string, int64_t>(name, line));
} 


bool LabelTable::labelExists(string name) const {
    return labels.count(name) > 0;
}


int64_t LabelTable::getLine(string name) const {
    return labels.at(name);
}


void LabelTable::buildLabelTable(vector<Token> & tokenLine) {
    if (tokenLine.empty()) return;
    bool incrementLine = false;
    for (auto & token : tokenLine) {
        string trimmedLabel = token.getValue();
        trimmedLabel.pop_back();

        switch (token.getType()) {
            case Token::LABEL:
                if (labelExists(trimmedLabel)) {
                    throw InvalidScan("Duplicate label found: " + trimmedLabel);
                    return;
                } 
                addLabel(trimmedLabel, lineNumber*4);
                break;
            default:
                incrementLine = true;
                break;
        }
    }
    if (incrementLine) lineNumber++;
}


void LabelTable::cleanLabels(vector<Token> & tokenLine) {
    if (tokenLine.size() == 0) return;
    int index = 0;
    for (size_t i = 0; i < tokenLine.size(); i++) {
        if (tokenLine.at(i).getType() == Token::LABEL) {
            index++;
        } else {
            break;
        }
    }
    if (index == 0) return;
    tokenLine.erase(tokenLine.begin(), tokenLine.begin() + index);
}