#ifndef __MIPSDFA_H
#define __MIPSDFA_H
#include "Token.h"
#include "InvalidScan.h"
#include <string>
#include <vector>
#include <set>
#include <cstdint>
#include <ostream>
#include <array>
using namespace std;

const int TRANSITION_NUM = 128;

class MipsDFA {
    public:
    enum  States {
        ID = 0,
        LABEL,
        COMMA,
        LPAREN,
        RPAREN,
        INT,
        HEXINT,
        REGISTER,
        WSPACE,
        COMMENT,
        FAIL,
        START,
        ZERO,
        ZEROHEX,
        DASH,
        DOLLAR,
        DUMMY = DOLLAR
    };
    private:
    // All the accepting tokens for the program
    std::set<States> accepting = {ID, LABEL, HEXINT, INT, ZERO, COMMA, 
                                    REGISTER, LPAREN, RPAREN, WSPACE, COMMENT};

    // All the transitions the DFA can take
    std::array<std::array<States, TRANSITION_NUM>, DUMMY + 1> transitions;

    // Convert state to token type
    Token::Type toType(States state) const;
    public:
    MipsDFA();

    /**
     * @brief Munch the string input into tokens using simplified maximal munch
     * 
     * @param in The string to munch
     * @return vector<Token> 
     */
    vector<Token> munch(const string &in) const;

    /**
     * @brief Create a transition from state src to dest if any character in read is at the top
     * 
     * @param src The source state
     * @param dest The destination state
     * @param read The value to read in
     */
    void transition(States src, States dest, const string & read);

    /**
     * @brief Create a transition from state src to dest if test returns true
     * 
     * @param src The source state
     * @param dest The destination state
     * @param test The function to test
     */
    void transition(States src, States dest, int (*test)(int));

    /**
     * @brief Determine the destination given the character to read and the source
     * 
     * @param src The source state
     * @param read The value to read
     * @return States - The destination
     */
    States destination(States src, char read) const;


    /**
     * @brief Get if the state is a fail state
     * 
     * @param state The state
     * @return true 
     * @return false 
     */
    bool isFailed(States state) const;

    /**
     * @brief Get if the state is a accept state
     * 
     * @param state The state
     * @return true 
     * @return false 
     */
    bool isAccept(States state) const;

    /**
     * @brief Tokenizes a input string into a vector of tokens and removes whitespace tokens
     * 
     * @param in The string to tokenize
     * @return vector<Token> 
     */
    static vector<Token> tokenize(const string & in);
};

#endif