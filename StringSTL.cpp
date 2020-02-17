/* 
STL의 STRING 클래스를 이용하여 간편하게 string 객체를 만들어냄
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string strName;
	cout << "이름 : ";
	cin >> strName;
	cout << "당신의 이름은 " << strName << "입니다" << endl;

	return 0;
}
*/
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vec(3);
	vec[0] = 10;
	vec[1] = 11;
	vec[2] = 12;

	for (auto &n : vec)
	{
		cout << n << '\t';
	}
	cout << endl;

	vec.push_back(30);
	vec.push_back(40);

	for (auto &n : vec)
		cout << n << '\t';

	cout << endl;

	vec.pop_back();

	for (auto &n : vec)
		cout << n << '\t';
	cout << endl;
	return 0;
}
