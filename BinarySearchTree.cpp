#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;
//���Ḯ��Ʈó�� ����ü�� ���� ���� Ž��Ʈ���� ��� 
BinaryTreeNode* insertTreeNode(BinaryTreeNode**, int);
//Ʈ���� ��带 �����ϱ� ���� �Լ� 
BinaryTreeNode* getTreeNode(int);
//Ʈ������ ��带 ����ִ� �Լ�					
int getHeight(BinaryTreeNode*);
//Ʈ���� ���̸� ����ϴ� �Լ� 
int Max(int a, int b)
{
	int result = (a > b) ? a : b;
	return result;
}				
int main()
{
	BinaryTreeNode* treeHead=NULL;
	//����⸦ ����Ű�� ������ 
	int i;
	int height=0;
	int num = 0;
	
	int a,k;
	//a : �Է��Ϸ����ϴ� ����Ǽ�, k : ����� Ű���� 
	cin>>a;
	
	for(i =0; i<a;i++)
	{
		cin>>k;
		
		insertTreeNode(&treeHead, k);
		//k���� ���� ��带 �����Ѵ�. 
		num=treeHead->data;
		//num�� Ʈ����尡 ����Ű�� �������̴� 
	}
	height=getHeight(treeHead);
	printf("%d", height);
	return 0;
}

BinaryTreeNode* getTreeNode(int inputdata)
{
	BinaryTreeNode* new_node=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	//����ü ũ�⸸ŭ�� �޸𸮸� �Ҵ����ش�. (��带 �������ش�) 
	if (new_node == NULL)
	{
		exit(1);
	}
	new_node->data=inputdata;
	//�Է��� �����͸� �������ش�. 
	new_node->left=new_node->right=NULL;
	
	//��带 �����Ѵ�. 
	return new_node;
}

BinaryTreeNode* insertTreeNode(BinaryTreeNode** root, int inputdata)
//ó���� ������� head�� �������̹Ƿ�, head�ּҸ� �������� ���������͸� ��ߵǾ���. 
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
			//����ִٸ� �׳� ��ƶ� 
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
			//����ִٸ� ��ƶ� 
			else
			{
				idx=idx->right;
			}
		}
		//���� �����͸� ������ ��忡 �ִ°��� ���ϸ鼭 ������ left ũ�� rigth�� ����Ű�Ը����
		//����Ž��Ʈ���� �������ش�. 
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
		//��忡 ���ʿ������� ��������� ���ϸ鼭 ���̸� ���Ѵ�. 
	}
	else
		return 0;
}
