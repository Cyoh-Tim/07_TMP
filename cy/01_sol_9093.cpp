#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
int main() {
	int a;
	std::string in;
	std::cin >> a;
	std::cin.ignore();
	for (int i = 0; i < a; i++)
	{
		std::string in;
		std::stack<char> stack;
		getline(std::cin, in);
		in += ' ';
		for (int j = 0; j < in.length(); j++)
		{
			if (in[j] == ' ')
			{
				while (true)
				{
					std::cout << stack.top();
					stack.pop();
					if (stack.empty())
						break;
				}
				printf(" ");
			}
			else
			{
				stack.push(in[j]);
			}
		}
		printf("\n");
	}
	return 0;
}