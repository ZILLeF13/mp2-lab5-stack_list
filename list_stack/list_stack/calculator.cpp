//#define _CRT_SECURE_NO_WARNINGS

#include "calculator.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

//x= strtod(string,&stopstring)

int TCalculator::Priority(char elem) 
{
	switch (elem)
	{
	case'(':return 1;
	case')':return 1;
	case'+':return 2;
	case'-':return 2;
	case'*':return 3; 
	case'/':return 3;
	default: return 0;
	}
}

bool TCalculator::CheckBrackets()
{
	st.Clear_Stack();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			st.Push(infix[i]);
		}
		else
			if (infix[i] == ')')
			{
				if (st.Empty() == true)
				{
					return false;
				}
				st.Pop();
			}
	}
	return st.Empty();
}

void TCalculator::ToPostfix()
{
	postfix = "";
	std::string src = "(" + infix + ")";
	char elem = '!';
	unsigned int i = 0;
	st.Clear_Stack();
	while (i < src.size())
	{
		if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/')
		{
			postfix += " ";
			elem = st.Pop();
			while (Priority(elem) >= Priority(src[i]))
			{
				postfix += elem;
				elem = st.Pop();
			}
			st.Push(elem);
			st.Push(src[i]);
		}
		else
			if (src[i] == '(')
			{
				st.Push(src[i]);
			}
			else
				if (src[i] == ')')
				{
					elem = st.Pop();
					while (elem != '(')
					{
						postfix += elem;
						elem = st.Pop();
					}
				}
				else
					if ((src[i] >= '0' && src[i] <= '9')||src[i]=='.')
					{
						postfix += src[i];
					}
		i++;
	}
}

double TCalculator::CalcPostfix()
{
	unsigned int i = 0;
	st2.Clear_Stack();
	while (i < postfix.size())
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
		{
			double k2 = st2.Pop();
			double k1 = st2.Pop();
			switch (postfix[i])
			{
			case'+': {st2.Push(k1 + k2); i++; break; }
			case'-': {st2.Push(k1 - k2); i++; break; }
			case'*': {st2.Push(k1 * k2); i++; break; }
			case'/': {st2.Push(k1 / k2); i++; break; }
			default: return 0;
			}
		}
		/*if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			st2.Push(postfix[i] - '0');
		}*/
		else
		{
			if (postfix[i] != ' ')
			{
				int x=i, flag = 0, pos = 0,x1;
				while (postfix[x] != ' ' && x != postfix.size()&& postfix[x] != '+' && postfix[x] != '-' && postfix[x] != '*' && postfix[x] != '/')
				{
					if (postfix[x] == '.')
					{
						flag = 1;
						pos = x;
					}
					x++;
				}
				x1 = x - i - flag;
				if (flag == 1)
				{
					pos = x - pos - flag;
				}
				x = i;
				double q = 0;
				while (postfix[x] != ' ' && x != postfix.size() && postfix[x] != '+' && postfix[x] != '-' && postfix[x] != '*' && postfix[x] != '/')
				{
					if (postfix[x] != '.')
					{
						x1--;
						q += (postfix[x] - '0') * pow(10, x1);
					}
					x++;
				}
				if (flag == 1)
				{
					q /= pow(10, pos);
				}
				st2.Push(q);
				i = x;
				/*q = strtod(&postfix[i], NULL);
				cout << q << endl;
				st2.Push(q);
				x= sprintf(q1, "%f", q);
				x = strlen(q1);
				i = i + x - 1;*/
				/*x = q;
				q = q - x;
				cout<<"q="<<q;
				//sprintf(q1, "%f", q);
				if (q1 != "0")
				{
					x1 = strlen(q1);
					i += x1;
				}
				while (x != 0)
				{
					x = x / 10;
					i++; 
				}*/
			}
			else
				if (postfix[i] == ' ')
				{
					i++;
				}
		}
	}
	return st2.Top();
}