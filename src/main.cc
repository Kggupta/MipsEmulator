#include <iostream>
#include <string>
#include "LabelTable.h"
#include "MipsClient.h"
#include "MipsDFA.h"
#include "Token.h"
#include "Command.h"
#include "CommandFactory.h"
#include "InvalidScan.h"
#include "EndProgram.h"
using namespace std;


int main(int argc, char* argv[]) {
    string line;
    LabelTable table;
    MipsClient client;
    if (argc == 2) client.configure(argv[1]);
    CommandFactory factory;
    vector<Command *> commands;
    try {
        while (getline(cin, line)) {
            vector<Token> tokenLine = MipsDFA::tokenize(line);
            table.buildLabelTable(tokenLine);
            LabelTable::cleanLabels(tokenLine);
            if(tokenLine.size() == 0) continue;
            Command * cmd = factory.create(tokenLine);
            if (cmd == nullptr) {
                throw InvalidScan("Invalid command : Syntax error\n-   " + line);
            }
            commands.push_back(cmd);
        }

        while (true) {
            Command * cmd = commands.at(client.getPC()/4);
            client.incrementPC();
            cmd->run(client, table);
        }
    } catch (InvalidScan &f) {
        cerr << f.what() << endl;
    } catch (EndProgram &f) {
        cout << client << endl;
    } catch (exception &f) {
        cerr << "Missing end of program." << endl; 
    }
    for (auto i : commands) delete i;

}