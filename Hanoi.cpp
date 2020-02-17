#include "pch.h"
#include <iostream>
using namespace std;

void main()
{
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int n = 4;
	hanoi(a, b, c, n);
}

void hanoi(char from, char temp, char to, int n)
{
	int cnt = 0;
	if (n == 1)
	{
		++cnt;
		std::cout << "[" << cnt << "]말뚝" << from << "에서 말뚝" << to << "로 원반 1개를 이동" << endl;
	}
	else
	{
		hanoi(from, to, temp, n - 1);
		++cnt;
		cout << "[" << cnt << "]말뚝" << from << "에서 말뚝" << to << "로 원반" << n << "개를 이동" << endl;
		hanoi(temp, from, to, n - 1);
		cout << "총횟수:" << cnt;
	}
}