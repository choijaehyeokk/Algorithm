#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

class Root
{
public:
	double operator()(double x)
	{
		return sqrt(x);
	}
};
int main()
{
	double data[] = { 1.5,2.5,3.5,4.5,5.5 };

	//객체로 전달하기.
	Root root;
	cout << "Square roots are:" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), root);

	//람다 표현식을 인수로 사용하기
	cout << "\n\nCubeds are:" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [](double x) {return x * x*x; });

	//function<>타입의 변수를 인수로 사용하기
	function<double(double)> op = [](double x) {return x * x *x; };
	cout << "\n\nSquares are:" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), op);
	
	//다른 람다 표현식을 호출하는 람다 표현식을 인수로 사용하기
	cout << "\n\n4th powers are:" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [&op](double x) {return op(x)*op(x); });

	cout << endl;
}