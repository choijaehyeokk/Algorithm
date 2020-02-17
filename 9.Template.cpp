#include <iostream>
using namespace std;

template <typename T>
class MyArray
{
public:
	explicit MyArray(int nSize)
	{
		m_nSize = nSize;
		m_pData = new T[nSize];
	}
	~MyArray() { delete m_pData; }
	MyArray(const MyArray &ref)
	{
		m_pData = new T[ref.m_nSize];
		memcpy(m_pData, ref.m_pData, sizeof(T)*ref.m_nSize);
		m_nSize = ref.m_nSize;
	}
	MyArray& operator=(const MyArray &ref)
	{
		if(&ref == this)
		{
			return *this;
		}
		delete m_pData;
		m_pData = new T[ref.m_nSize];
		memcpy(m_pData, ref.m_pData, sizeof(T)*ref.m_nSize);
		m_nSize = ref.m_nSize;
		return *this;
	}
	MyArray(MyArray &&ref)
	{
		operator = (ref);
	}
	MyArray& operator=(const MyArray &&ref)
	{
		m_pData = ref.m_pData;
		m_nSize = ref.m_nSize;
		ref.m_pData = nullptr;
		ref.m_nSize = 0;
	}
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "ERROR:배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}
		return m_pData[nIndex];
	}
	T& operator[](int nIndex) const
	{
		return operator[](nIndex);
	}
	int GetSize() { return m_nSize; }

private:
	int m_nSize = 0;
	T *m_pData = nullptr;
};
int main(void)
{
	MyArray<int> arr(5);
	int ten = 10;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = ten;
		
		ten += 10;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	MyArray<int> arr2(3);
	arr2.operator=(arr);
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << ' ';
	}
	cout << endl;
	return 0;
}