#pragma once
#include "stack.h"
#include <string>

class TCalculator
{
private:
	std::string infix;
	std::string postfix;
	Stack<char> st;
	Stack<double> st2;
	int Priority(char elem);
public:

	TCalculator()
	{
		infix = "";
		postfix = "";
	}

	std::string GetExpression()
	{
		return infix;
	}

	void SetExpression(std::string expr)
	{
		infix = expr;
		if (CheckBrackets() != true)
		{
			throw "SetExperession";
		}
	}

	std::string GetPostfix()
	{
		return postfix;
	}
	
	bool CheckBrackets();

	void ToPostfix();

	double CalcPostfix();

};

