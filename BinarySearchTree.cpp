#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;
//연결리스트처럼 구조체를 만든 이진 탐색트리의 노드 
BinaryTreeNode* insertTreeNode(BinaryTreeNode**, int);
//트리에 노드를 삽입하기 위한 함수 
BinaryTreeNode* getTreeNode(int);
//트리에서 노드를 얻어주는 함수					
int getHeight(BinaryTreeNode*);
//트리의 높이를 계산하는 함수 
int Max(int a, int b)
{
	int result = (a > b) ? a : b;
	return result;
}				
int main()
{
	BinaryTreeNode* treeHead=NULL;
	//꼭대기를 가리키는 포인터 
	int i;
	int height=0;
	int num = 0;
	
	int a,k;
	//a : 입력하려고하는 노드의수, k : 노드의 키값들 
	cin>>a;
	
	for(i =0; i<a;i++)
	{
		cin>>k;
		
		insertTreeNode(&treeHead, k);
		//k값을 가진 노드를 삽입한다. 
		num=treeHead->data;
		//num는 트리헤드가 가리키는 데이터이다 
	}
	height=getHeight(treeHead);
	printf("%d", height);
	return 0;
}

BinaryTreeNode* getTreeNode(int inputdata)
{
	BinaryTreeNode* new_node=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	//구조체 크기만큼의 메모리를 할당해준다. (노드를 생성해준다) 
	if (new_node == NULL)
	{
		exit(1);
	}
	new_node->data=inputdata;
	//입력한 데이터를 삽입해준다. 
	new_node->left=new_node->right=NULL;
	
	//노드를 리턴한다. 
	return new_node;
}

BinaryTreeNode* insertTreeNode(BinaryTreeNode** root, int inputdata)
//처음에 만들어준 head는 포인터이므로, head주소를 담으려면 이중포인터를 써야되었다. 
{
	BinaryTreeNode* idx = *root;
	if ((*root) == NULL)
	{
		(*root)= getTreeNode(inputdata);
		return *root;
	}

	while(1)
	{
		if (idx->data > inputdata)
		{
			if (idx->left == NULL)
			{
				idx->left=getTreeNode(inputdata);
				break;
			}
			//비어있다면 그냥 담아라 
			else
			{
				idx=idx->left;
			}
		}
		else if(idx->data <inputdata)
		{
			if (idx->right ==NULL)
			{
				idx->right=getTreeNode(inputdata);
				break;
			}
			//비어있다면 담아라 
			else
			{
				idx=idx->right;
			}
		}
		//들어온 데이터를 가지고 노드에 있는값과 비교하면서 작으면 left 크면 rigth로 가리키게만들어
		//이진탐색트리를 생성해준다. 
		else	
		{
			return NULL;
		}
	}
	return idx;
}
int getHeight(BinaryTreeNode* node)
{
	if (node!=NULL)
	{
		return Max(getHeight(node->left), getHeight(node->right))+1;
		//노드에 왼쪽오른쪽을 재귀적으로 비교하면서 높이를 구한다. 
	}
	else
		return 0;
}
