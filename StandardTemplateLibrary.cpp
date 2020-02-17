#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
//#include <algorithm>
using namespace std;


/*
 template <class T>
T& larger(T& a, T& b)
{
	return a > b ? a : b;

}
int main()
{
	string first{ "Hello World!" };
	string second{ "HelloWorld!!" };

	auto begin_iterator = begin(first);
	auto end_iterator = end(first);
	//반복자를 활용하여 string 컨테이너에 포인터로 접근함.

	cout << "First string의 \n처음:" << *begin_iterator << "\n끝:" << *(end_iterator - 1) << endl;
	string& result = larger(first, second);
	cout << result << endl;
	vector<double> values;
	cout << "값은 공백으로 구분해서 입력하세요. 종료하려면 Ctrl+Z를 누르세요." << endl;
	values.insert(begin(values), istream_iterator<double>(cin), istream_iterator<double>());
	cout << "평균값 : " << (accumulate(begin(values), end(values), 0.0) / values.size()) << endl;


}*/

int main(void)
{
	double data[] = { 2.5,4.5,6.5,5.5,8.5 };
	cout << "배열 원소들: \n";
	for (auto iter = begin(data); iter != end(data); ++iter)
	{
		cout << *iter << " ";
	}
	auto total = accumulate(begin(data), end(data), 0.0);

	cout << "\n배열의 끝: " << *(end(data)-1);
	cout << "\n배열 원소들의 합계: " << total << endl;

	return 0;
}