#include <iostream>
using namespace std;

class MyException
{
public:
	MyException(int nCode, const char *pszMsg)
	{
		m_nErrorCode = nCode;
		strcpy_s(m_msMsg, sizeof(m_msMsg), pszMsg);
	}
	int GetErrorCode() const
	{
		return m_nErrorCode;
	}
	const char * GetMessage() const
	{
		return m_msMsg;
	}
private:
	int m_nErrorCode = 0;
	char m_msMsg[32];
};
int main(void)
{
	try
	{
		int nInput = 0;
		cout << "양의 정수를 입력하세요: ";
		cin >> nInput;

		if (nInput < 0)
		{
			MyException exp(10, "양의 정수를 입력해야 합니다.");
			throw exp;
		}
		
	}

	catch (MyException &Exp)
	{
		cout << "ERROR CODE[" << Exp.GetErrorCode() << "]" << Exp.GetMessage() << endl;
	}
}