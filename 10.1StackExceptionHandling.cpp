#include <iostream>

using namespace std;
void TestFunc1()
{

	cout << "***TestFunc1() - BEGIN***" << endl;
	throw 0;
	//throw 문을 이용하여 함수를 호출하기 이전으로 돌려 놓을 수 있음. 스택을 푼다고함.
	//Stack unwinding
	cout << "***testfunc1() - end***" << endl;
}
void TestFunc2()
{
	cout << "***TestFunc2()() - BEGIN***" << endl;
	TestFunc1();
	cout << "***TestFunc2()() - END***" << endl;
}
void TestFunc3()
{
	cout << "***TestFunc3() - BEGIN***" << endl;
	TestFunc2();
	cout << "***TestFunc3() - END***" << endl;
}
int main(void)
{
	try
	{
		TestFunc3();
	}
	catch (...)
	{
		cout << "Exception Handling" << endl;
	}
	
	return 0;
}