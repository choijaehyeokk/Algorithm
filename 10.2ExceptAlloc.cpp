#include <iostream>
#include <new>
//bad_alloc 클래스를 사용하기 위한 헤더
using namespace std;

class Test
{
public:
	Test(int nSize)
	{
		m_pszData = new char[nSize];
	}
	~Test()
	{
		delete[] m_pszData;
		cout << "정상적으로 객체가 소멸하였습니다." << endl;
	}
private:
	char *m_pszData;
};
int main(void)
{
	int nInput = 0;
	try {
		cout << "Input size : ";
		cin >> nInput;
		Test a(nInput);
	}
	catch(bad_alloc &exp)
	{
		cout << exp.what() << endl;
		cout << "ERROR: Test() " << endl;
	}
	return 0;


}