#ifndef __TOKEN_H
#define __TOKEN_H

#include <string>
#include <sstream>
using std::string;
using std::istringstream;


class Token {
    public:
    enum Type {
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
        FAIL
    };

    private:
    Type type;
    string value;

    public:
    /**
     * @brief Construct a new Token object
     * 
     * @param type Type of the token
     * @param value The lexeme value
     */
    Token(Type type, string value);

    /**
     * @brief Get the Type object
     * 
     * @return Type 
     */
    Type getType() const;

    /**
     * @brief Get the lexeme value
     * 
     * @return const string& 
     */
    const string & getValue() const;

    /**
     * @brief Convert a register, integer, hexint to an int64_t
     * 
     * @return int64_t 
     */
    int64_t valAsNumber() const;

};

#endif 