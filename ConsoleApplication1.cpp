
#include "pch.h"
#include <iostream>
using namespace std;

void swap(char* a, char* b)
{
	char* temp = NULL;
	temp = a;
	a = b;
	b = temp;
}
void Permutation(char* a, const int k, const int m)
{
	static int count = 0;
	if (k == m)
	{
		for (int i = 0; i <= m; i++)
		{
			cout << a[i] << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
			swap(a[k], a[i]);
			Permutation(a, k + 1, m);
			count++;
			//printf("count:%d\n", count);
			swap(a[k], a[i]);
		}
	}
	//printf("count:%d\n", count);
}
int main()
{
	char a[4] = { 'a','b','c','d' };
	Permutation(a, 0, 3);
	return 0; 
}

