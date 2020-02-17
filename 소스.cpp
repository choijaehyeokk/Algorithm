#include <iostream>

int TestFunc(int nParam)
{
	int nResult = nParam * 2;
	return nResult;
}
int main(void)
{
	int nInput = 0;
	std::cout << "Input number:";
	std::cin >> nInput;

	int &&rData = nInput + 5;
	std::cout << rData << std::endl;

	int &&result = TestFunc(10);
	std::cout << result << std::endl;
	result += 10;
	std::cout << result << std::endl;

	return 0;
}

 