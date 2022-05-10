#include "Token.h"

Token::Token(Token::Type type, string val): type(type), value(val) {}

const string & Token::getValue() const {return value;}

Token::Type Token::getType() const {return type;}

int64_t Token::valAsNumber() const {
    istringstream ss;
    int64_t res;

    switch (type)
    {
    case INT:
        ss.str(value);
        break;
    case HEXINT:
        ss.str(value);
        ss >> std::hex;
        break;
    case REGISTER:
        ss.str(value.substr(1));
        break;
    default:
        return 0;
    }
    ss >> res;

    return res;
}