#include <iostream>
using namespace std;
#define DefaultFare 1000

class Person
{
public:
	Person() {}
	virtual ~Person() { cout << "virtual ~Person() " << endl; }
	virtual void CalFare() = 0;
	virtual unsigned int GetFare() { return nFare; }
protected:
	unsigned int nFare;
};
class Baby : public Person
{
public:
	Baby() {}
	virtual ~Baby() { cout << "virtual ~Baby()" << endl; }
	virtual void CalFare()
	{
		nFare = 0;
	}
};
class Child : public Person
{
public:
	Child() {}
	virtual ~Child() { cout << "virtual ~Child()" << endl; }
	virtual void CalFare()
	{
		nFare = DefaultFare*0.5;
	}
};
class Teen : public Person
{
public:
	Teen() {}
	virtual ~Teen() { cout << "virtual ~Teen()" << endl; }
	virtual void CalFare()
	{
		nFare = DefaultFare *0.75;
	}
};
class Adult : public Person
{
public:
	Adult() {}
	virtual ~Adult() { cout << "virtual ~Adult()" << endl; }
	virtual void CalFare()
	{
		nFare = DefaultFare;
	}
};

int main(void)
{
	Person* list[5] = { 0, };
	int nAge = 0;

	for (auto &person : list)
	{
		cout << "나이를 입력하세요:";
		cin >> nAge;
		if (0 < nAge && nAge < 8)
			person = new Baby;
		else if (nAge < 14)
			person = new Child;
		else if (nAge < 20)
			person = new Teen;
		else if (nAge >= 20)
			person = new Adult;
		else
			continue;
		person->CalFare();
	}
	for (auto person : list)
	{
		cout << person->GetFare() << "원" << endl;
	}
	for (auto person : list)
	{
		delete person;
	}
	return 0;
}