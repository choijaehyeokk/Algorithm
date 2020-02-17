#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void)
{
	/*
	//unique_ptr<string> pname{ new string{"Algernon"} };
	auto pname = make_unique<string>("Algernon");
	//make_unique<>() 함수는 인수를 클래스 생성자에 전달하여 힙에 string 객체를 생성하고 유니크 포인터를 반환한다.
	auto pstr = make_unique<string>(6, "*");
	pname.reset();
	pstr.reset();
	unique_ptr<string> pst{ pstr.get() };
	pst.reset();

	size_t len = { 10 };
	auto pname2 = make_unique<int[]>(len);
	pname2.reset();
	//cout << *pname << endl;
	//cout << *pstr << endl;
	*/

	//===========================================================================================
	/*
	auto new_ptr = make_unique<string>("Algernon");

	unique_ptr<string> n_ptr{ new_ptr.release() };
	if (!new_ptr)
		cout << "new_ptr is nullptr" << endl;
	if (n_ptr)
		cout << "This is " << *n_ptr << endl;
	n_ptr.reset();

	shared_ptr<double> pdata{ new double(3.3) };
	cout << "First pdata : " << *pdata << endl;
	//shared pointer는 객체의 값을 변경할 수 있다.

	*pdata = 3.5;
	cout << "Changed pdata : " << *pdata << endl;

	auto s_ptr = make_shared<double>(99.99);
	cout << "s_ptr : " << *s_ptr << endl;

	s_ptr.reset();
	s_ptr = pdata;
	//복제하는 경우 레퍼런스 카운트가 증가한다.
	cout << "changed s_ptr : " << *s_ptr << endl;
	
	auto value = s_ptr.get();
	cout << "value : " << *value << endl;

	s_ptr.reset(new double{ 9.311 });
	cout << "s_ptr : " << *s_ptr << endl;
	
	s_ptr = nullptr;

	s_ptr = pdata;
	if ((s_ptr == pdata) && (s_ptr != nullptr))
	{
		cout << "두 포인터는 같은 객체를 가리킵니다." << endl;
	}
		
	shared_ptr<double> ns_ptr{ pdata };
	
	if (pdata.unique())
		cout << "객체를 가리키는 포인터는 하나입니다." << endl;
	else
		cout << "두개 이상 있습니다." << "\n인스턴스 갯수는 : " << pdata.use_count() << "개입니다."<< endl;
	
	*/

	//======================================================================================

	/*auto pData = make_shared<int>(10);
	//shared 포인터가 가리키는 객체를 weak 포인터가 가리킬수있게함.
	weak_ptr<int> pwData{ pData };
	weak_ptr<int> pwData2{ pwData };

	
	if (!pwData.expired())
		cout << "가리키는 객체가 존재합니다." << endl;*/

	string animals[6] = {"기린","호랑이","코끼리","사자","고릴라","북극곰"};

	cout << animals[5] << endl;
	cout << animals->length()<< endl;

	for (int i = 0; i < animals->size(); ++i)
	{
		//cout << animals->length() << endl;
		cout << animals[i] << endl;
		cout << i << endl;
	}
	
	return 0;

}