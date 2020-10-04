#include "Token.h"
#include <unordered_set>


Token::Token(std::string str)
{
	value_ = str;
	type_ = findType(str);
}


/*
* identifier
* keyword,
* separator
* oprator
* literal
*/

TokenType Token::findType(std::string str)
{
	if (isOperator(str))
		return oprator;
	if (isLiteral(str))
		return literal;
	if (isKeyword(str))
		return keyword;
	if (isSeparator(str))
		return separator;
	//if (isIdentifier(str))
	return identifier;
}


bool isOperator(std::string str)
{
	std::unordered_set<std::string> operators = {"+", "-", "<", ">", "=", "!", "*", "/"};
	return operators.count(str);
}

bool isLiteral(std::string str)
{
	std::unordered_set<std::string> literals = { "true", "false"};
	if(literals.count(str))
		return literals.count(str);
	if (str[0] == '"' && str[str.size() - 1] == '"')
		return true;
	for (char ch : str)
		if (isdigit(ch))
			continue;
		else
			return false;

	return true;
}

bool isKeyword(std::string str)
{
	std::unordered_set<std::string> keywords = {"if", "for", "while", "else"};
	return keywords.count(str);
}

bool isSeparator(std::string str)
{
	std::unordered_set<std::string> separators = { "{", "}", "(", ")", "[", "]", ",", ".", ";", ":" };
	return separators.count(str);
}

bool isIdentifier(std::string str)
{
	return false;
}

TokenType Token::GetType() const
{
	return type_;
}

std::string Token::GetValue() const
{
	return value_;
}


std::ostream& operator<< (std::ostream& os, const Token& token)
{
	std::string type = "";

	switch (token.GetType())
	{
	case identifier: type = "identifier";
		break;
	case keyword: type = "keyword";
		break;
	case separator: type = "separator";
		break;
	case oprator: type = "operator";
		break;
	case literal: type = "literal";
		break;
	default:
		type = "invalid type";
		break;
	}

	os << "( " << type << ", " << token.GetValue() << " )";
	return os;
}