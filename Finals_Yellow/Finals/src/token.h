#pragma once

#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
  DATE,			// дата
  EVENT,		// событие
  COLUMN,		// категория под строки "event" и "date" в предикатах для FindIf и DelIf???
  LOGICAL_OP,	// логический оператор [AND, OR]
  COMPARE_OP,	// оператор сравнения [==, !=, >, <, и т.д.]
  PAREN_LEFT,	// открывающая скобка
  PAREN_RIGHT, 	// закрывающая скобка
};

struct Token {
  const string value;
  const TokenType type;
};

vector<Token> Tokenize(istream& cl);
