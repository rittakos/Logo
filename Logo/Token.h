#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>
#include "tokentype.h"


class Token
{
public:
	Token(std::string str);

	TokenType GetType() const;
	std::string GetValue() const;
private:
	TokenType type_;
	std::string value_;

	TokenType findType(std::string str);
};


std::ostream& operator<< (std::ostream& os, const Token& token); 
bool isOperator(std::string str);
bool isLiteral(std::string str);
bool isKeyword(std::string str);
bool isSeparator(std::string str);
bool isIdentifier(std::string str);

#endif // !TOKEN_H
