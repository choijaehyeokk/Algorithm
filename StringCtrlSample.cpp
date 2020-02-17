#include <iostream>
#include <TCHAR.h>
#include "CMyString.h"
#include "CMyStringEx.h"

using namespace std;
void TestFunc(const CMyString &ref)
{
	cout << ref[0] << endl;
	cout << ref[ref.GetLength() - 1] << endl;
}
int _tmain(int argc,_TCHAR* argv[])
{
	CMyString b("World"), c;
	c = "Hello" + b;
	cout << c << endl;
	return 0;

}

