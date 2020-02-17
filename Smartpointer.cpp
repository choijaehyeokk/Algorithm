/* AUTO PTR
#include <iostream>
#include <memory>
using namespace std;

class MyData
{
public:
	MyData() { cout << "MyData()" << endl; }
	~MyData() { cout << "~MyData()" << endl; }
	void TestFunc() { cout << " MyData::TestFunc()" << endl; }
};
int main(void)
{
	cout << "*****BEGIN*****" << endl;
	auto_ptr<MyData> ptrTest(new MyData);
	auto_ptr<MyData> ptrNew;

	cout << "0x" << ptrTest.get() << endl;

	//ptrNew = ptrTest;
	//얕은 복사는 문제를 발생시킴.
	//이는 ptrTest의 포인터값을 ptrNew에 전달해주고 자기자신은 NULL로 초기화됨.

	cout << "0x" << ptrTest.get() << endl;

	ptrTest->TestFunc();
	//배열로 동적할당하여 인수로 처리할시 삭제도 배열로 삭제해야하기 떄문에 오류가 발생한다.
	
	cout << "*****END*****" << endl;
	return 0;
}
*/
/* SHARED PTR
#include <iostream>>
#include <memory>
using namespace std;

class Test
{
public:
	Test() { cout << "Test()" << endl; };
	~Test() { cout << "~Test()" << endl; }
	void TestFunc() { cout << "Test::TestFunc()" << endl; }
};

int main(void)
{
	cout << "*****BEGIN*****" << endl;
	shared_ptr<Test> ptr1(new Test);

	cout << "counter: " << ptr1.use_count() << endl;
	{
		shared_ptr<Test> ptr2(ptr1);

		cout << "counter: " << ptr1.use_count() << endl;
		ptr2->TestFunc();
	}

	cout << "counter: " << ptr1.use_count() << endl;
	ptr1->TestFunc();
	cout << "*****END*****" << endl;
	return 0;
}
*/
#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
	void TestFunc() { cout << "Test::TestFunc()" << endl; }
};

int main(void)
{
	unique_ptr<Test> ptr1(new Test);

	return 0;
}