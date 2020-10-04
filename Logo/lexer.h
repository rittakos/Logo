#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <vector>
#include <set>
#include <unordered_set>

class Lexer
{
public:
	Lexer()
	{
		
	}

	std::vector<Token> getTokens() 
	{ 
		return tokens; 
	}

	void write(std::ostream & os = std::cout);
	
	void tokenise(std::string text);
private:
	std::vector<Token> tokens;
	
	

	bool nothingSpecial(char ch);

	std::string specChar = "{}()[]";
	std::unordered_set<char> specialCharacters = {'(', ')', '{', '}', '[', ']', '<', '>', '+', '-', '=', '!', '|', '&', '*', '/', '.', ',', ':', ';'};
	std::unordered_set<char> ignorantCharacters = { ' ', '\n', '\r', '\t' };
	std::unordered_set<char> stringIdentifierCharacters = { '"'};

	bool isIgnorantCharacter(char c);

	bool isSpecialCharacter(char c);

	bool isStringIdentifierCharacter(char c);
};
#endif
