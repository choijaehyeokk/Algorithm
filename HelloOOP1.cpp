#include <iostream>
using namespace std;
class MyData
{
public:
	MyData()
	{
		cout << "Nomal Constructor" << endl;
	}
	MyData(int nParam)
	{
		cout << "int(nParam) Constructor" << endl;
	}
	MyData(double nParam)
	{
		cout << "double(nParam) Constructor" << endl;
	}
};
class MyDataEx : public MyData
{
public:
	//using MyData::MyData;
	MyDataEx()
	{
		cout << "MyDataEx Nomal Constructor" << endl;
	}
	MyDataEx(int nParam)
		:MyData(nParam)
	{
		cout << "MyDataEx int(nParam) Constructor" << endl;
	}
	MyDataEx(double nParam)
		:MyData(nParam)
	{
		cout << "MyDataEx double(nParam) Constructor" << endl;
	}
};
int main(void)
{
	MyDataEx a;
	cout << "***********" << endl;
	MyDataEx b(10);
	cout << "***********" << endl;
	MyDataEx c(2.3);
	cout << "***********" << endl;

	return 0;
}