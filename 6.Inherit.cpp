#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		cout << " CMyData Constructor" << endl;
	}
	int GetData() { return nData; }
	void SetData(int nParam)
	{
		nData = nParam;
	}
private:
	int nData;
protected:
	void PrintData() { cout << "CMyData::PrintData()" << endl; }
};
class inheritCMyData : public CMyData
{
public:
	inheritCMyData() 
	{
		cout << " inheitCMyData() " << endl;
	}
	void TestFunc()
	{
		PrintData();
		SetData(5);
		cout << CMyData::GetData() << endl;
		cout << GetData() << endl;
	}
};
int main(void)
{
	CMyData a;
	a.SetData(100);
	cout << a.GetData() << endl;
	
	inheritCMyData b;
	b.SetData(500);
	cout << b.GetData() << endl;
	b.TestFunc();
	
	return 0;

}