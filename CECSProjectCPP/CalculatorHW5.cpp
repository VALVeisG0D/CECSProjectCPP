//Name: Vichaya Chantamoke
//SID: 011497796
//Homework 5: Recursive Descent Calculator 

#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <cmath>

char token; /*global token variable*/

/*function prototypes for recursive calls*/
int exp(void); //+ - operations
int expPrime(void); //* / % operations
int term(void); //unary minus
int termPow(void); //exponential right associative
int factor(void); 

void error(void)
{
	fprintf(stderr, "Error\n");
	exit(1);
}

void match(char expectedToken)
{
	if (token == expectedToken)
		token = getchar();
	else
		error();
}

int main()
{
	int result;
	token = getchar();/*load token with first
					  character for lookahead*/
	result = exp();

	if (token == '\n')/*check for end of line*/
		printf("Result = %d\n", result);
	else
		error();/*extraneous chars on line*/

	return 0;
}

//+ - operations with same precedence
int exp()
{
	int temp = term();

	while ((token == '+') || (token == '-'))
	{
		switch (token)
		{
		case '+':
			match('+');
			temp += term();
			break;
		case '-':
			match('-');
			temp -= term();
			break;
		}
	}

	return temp;
}

//* / % operations with same precedence
int term()
{
	int temp = expPrime();

	while ((token == '*') || (token == '/') || (token == '%'))
	{
		switch (token)
		{
		case '*':
			match('*');
			temp *= factor();
			break;
		case '/':
			match('/');
			temp /= factor();
			break;
		case '%':
			match('%');
			temp %= factor();
			break;
		}
	}

	return temp;
}

//unary minus, returns negative of term
int expPrime()
{
	return termPow();
}

//right associative exponent
int termPow()
{
	int temp = factor();

	while (token == '^')
	{
		switch (token)
		{
		case '^':
			match('^');
			temp = pow(temp, termPow()); //branch to the right instead of left
			break;
		}
	}

	return temp;
}

int factor()
{
	int temp;

	if (token == '(')
	{
		match('(');
		temp = exp();
		match(')');
	}
	else if (isdigit(token) || (token == '-'))
	{
		ungetc(token, stdin);
		scanf_s("%d", &temp);
		token = getchar();
	}
	else
		error();

	return temp;
}