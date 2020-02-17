// ConnectionList1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Node
{
	friend class MyList;
public:
	explicit Node(const char *pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}

private:
	char m_szName[32];
	Node *pNext = nullptr;
};
class MyList
{
public:
	MyList()
		:m_HeadNode("Dummy Head")
	{
		
	}
	~MyList() {
		Node *pNode = m_HeadNode.pNext;
		Node *pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;
			pNode = pNode->pNext;

			cout << pDelete->m_szName << endl;
			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}
	void AddNewNode(const char *pszName)
	{
		Node *pNode = new Node(pszName);
		pNode->pNext = m_HeadNode.pNext;
		m_HeadNode.pNext = pNode;
	}

private:
	Node m_HeadNode;
};
int main()
{
	MyList list;
	list.AddNewNode("길동");
	list.AddNewNode("철수");
	list.AddNewNode("영희");

	return 0;
}
