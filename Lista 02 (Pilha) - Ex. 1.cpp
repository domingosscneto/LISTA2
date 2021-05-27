#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__
#define E 9

const int STATIC_STACK_CAPACITY = E;

struct StaticStack
{
	int count;
	char values[STATIC_STACK_CAPACITY];
};

StaticStack Create();

bool Push(StaticStack &stack, char elem);

char Pop(StaticStack &stack);

char Top(const StaticStack &stack);

int Size(const StaticStack &stack);

int Count(const StaticStack &stack);

bool IsEmpty(const StaticStack &stack);

bool Clear(StaticStack &stack);

#endif

#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");

	char inverte[E];
	string frase, space = " ";

	cout << "Digite uma STRING de até " << E << " caracteres, desconsiderando os espaços): ";
	getline(cin, frase);
	cout << frase << '\n';

	StaticStack stack = Create();

	for (int i = 0; i < frase.size(); ++i)
		if (frase[i] != space[0])
		{
			Push(stack, (char)frase[i]);
		}

	for (int i = 0; i < frase.size(); ++i)
	{
		inverte[i] = stack.values[stack.count - 1 - i];
		cout << inverte << "\n";
	}

	cout << inverte << "\n";
	int count = 0;
	for (int i = 0; i < stack.count; ++i)
	{
		if (stack.values[i] == inverte[i])
			count++;
	}
	if (count == stack.count)
		cout << "É um palímdromo\n";
	else
		cout << "Não é um palíndromo\n";
}