#include <stdio.h>
#include <iostream>
#include <queue>
int main() {
	int a, b;
	int r[5010];
	std::queue<int> queue;
	std::cin >> a >> b;
	for (int i = 1 ; i < a + 1; i ++)
	{
		queue.push(i);
	}
	printf("<");
	for (int i = 0; i < a; i++)
	{
		for(int j = 0; j < b - 1; j ++)
		{
			int t = queue.front();
			queue.pop();
			queue.push(t);
		}
		int t = queue.front();
		queue.pop();
		
		if(queue.empty())
		{
			printf("%d>", t);
			break;
		}
		else
		{
			printf("%d, ", t);
		}
	}
	
	return 0;
}
