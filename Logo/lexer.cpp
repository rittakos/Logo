#include "lexer.h"

void Lexer::write(std::ostream& os)
{
	os << "[";

	for (int idx = 0; idx < tokens.size() - 1; ++idx)
		os << tokens[idx] << ", ";

	os << tokens[tokens.size() - 1] << "]";
}


void Lexer::tokenise(std::string text)
{
	std::string token = "";
	bool isString = false;

	for (char ch : text)
	{
		if (nothingSpecial(ch) || isString)
		{
			token += ch;
			continue;
		}

		if (isIgnorantCharacter(ch))
		{
			if (token != "")
				tokens.push_back(Token(token));
			token = "";
			continue;

		}else if (isSpecialCharacter(ch))
		{
			if(token != "")
				tokens.push_back(Token(token));
			token = ch;

		}
		else if (isStringIdentifierCharacter(ch))
		{
			if (isString)
				token += ch;
			isString = !isString;
		}


		tokens.push_back(Token(token));
		token = "";
	}
}

bool Lexer::nothingSpecial(char ch)
{
	return !(isIgnorantCharacter(ch) || isSpecialCharacter(ch) || isStringIdentifierCharacter(ch));
}

bool Lexer::isIgnorantCharacter(char c)
{
	return ignorantCharacters.count(c);
}

bool Lexer::isSpecialCharacter(char c)
{
	return specialCharacters.count(c);
}

bool Lexer::isStringIdentifierCharacter(char c)
{
	return stringIdentifierCharacters.count(c);
}