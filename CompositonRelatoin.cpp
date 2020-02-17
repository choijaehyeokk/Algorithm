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
	void Print()
	{
		Node *pNode = m_HeadNode.pNext;
		while (pNode)
		{
			cout << pNode->m_szName << endl;
			pNode = pNode->pNext;
		}
	}

private:
	Node m_HeadNode;
};
class MyUI
{
public:
	MyUI(MyList &rList)
		:m_list(rList)
	{

	}
	int PrintMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n->";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}
	void Run()
	{
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1:
				cout << "이름: ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;
			case 2:
				m_list.Print();
				break;
			default:
				break;
			}
		}
	}
private:
	MyList &m_list;
	//여기부터는 composition Relation
/*public :
	int PrintMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n->";
		cout.flush();
		int nInput = 0;
		cin >> nInput;

		return nInput;
	}

	void Run()
	{
		char szName[32];
		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1:
				cout << "이름: ";
				cout.flush();
				cin >> szName;
				m_list.AddNewNode(szName);
				break;
			case 2:
				m_list.Print();
				break;
			default:
				break;
			}
		}
	}
private:
	MyList m_list;*/
};
int main()
{
	//Aggregation관계
	MyList list;
	MyUI ui(list);
	ui.Run();
/*ComPositon관계
	MyUI ui;
	ui.Run();*/

	return 0;
}
