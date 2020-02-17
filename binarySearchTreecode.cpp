#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#include <iostream>
using namespace std;

typedef struct BiTreeNode
{
	int data;
	struct BiTreeNode* left;
	struct BiTreeNode* right;
}BiTreeNode;

BiTreeNode* insert_tree_node(BiTreeNode**, int);//����Ʈ���� ��� �������ִ� �Լ�
BiTreeNode* get_tree_node(int);					//��� �������ִ� �Լ�
BiTreeNode* search_node(BiTreeNode**, int);		//����Ʈ���� key���� ���� ����� ���� Ž��
int get_node_count(BiTreeNode*);				//����Ʈ���� �� ����� �� ����
int get_leaf_node_count(BiTreeNode*);			//����Ʈ���� ���� ���� ����
int get_height(BiTreeNode*);					//����Ʈ���� ���� �˷��ִ� �Լ�
int max_val(int, int);							//����Ʈ�� ���� �˷��ٶ�, ���� ������ �ڽ� �� ū�� �˷��ִ� �Լ�
void delete_tree_node(BiTreeNode**, int);		//����Ʈ���� key���� ���� ��� ����
void inorder(BiTreeNode*);						//����Ʈ���� ��� ����� ������ ���
BiTreeNode* max_tree_node(BiTreeNode*);			//����Ʈ���� �ִ밪�� ���� �����;˷��ְ� ��� �ּ� ����
BiTreeNode* min_tree_node(BiTreeNode*);			//����Ʈ���� �ּҰ��� ���� ������ �˷��ְ� ��� �ּ� ����
void free_tree_node(BiTreeNode*);

int main()
{
	BiTreeNode* tree_head=NULL;
	int i=0;
	int node_count=0, leaf_node=0, tree_height=0, num=0;
	int a,k;
	srand((unsigned)time(NULL));

	cin>>a;
	
	for(i =0; i<a;i++)
	{
		cin>>k;
		insert_tree_node(&tree_head, k);
		num=tree_head->data;
	}
	
	
	printf("\n");
	search_node(&tree_head, rand()%100+1);

	max_tree_node(tree_head);
	min_tree_node(tree_head);

	node_count=get_node_count(tree_head);
	printf("����Ʈ���� �� ����� ���� :: %d\n", node_count);
	
	leaf_node=get_leaf_node_count(tree_head);
	printf("����Ʈ���� ���ܳ���� �Ѱ��� :: %d\n", leaf_node);

	tree_height=get_height(tree_head);
	printf("����Ʈ���� ���� : %d\n", tree_height);

	delete_tree_node(&tree_head, rand()%50+1);
	delete_tree_node(&tree_head, num);
		delete_tree_node(&tree_head, rand()%50+1);
	
	inorder(tree_head);

	node_count=get_node_count(tree_head);
	printf("����Ʈ���� �� ����� ���� :: %d\n", node_count);
	printf("\n");

	free_tree_node(tree_head);
	inorder(tree_head);

	return 0;
}

BiTreeNode* get_tree_node(int putData)
{
	BiTreeNode* new_node=(BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (new_node == NULL)
	{
		printf("error :: it hasn't enough capacity at heap memory\n");
		exit(1);
	}

	new_node->data=putData;
	new_node->left=new_node->right=NULL;

	return new_node;
}

BiTreeNode* insert_tree_node(BiTreeNode** root, int putData)
{
	BiTreeNode* idx = *root;
	if ((*root) == NULL)	//Ʈ���� �������
	{
		(*root)= get_tree_node(putData);
		///printf(" %d ", (*root)->data);
		return *root;
	}

	while(1)
	{
		if (idx->data > putData)
		{
			if (idx->left == NULL)
			{
				idx->left=get_tree_node(putData);
				//printf(" %d ", idx->left->data);
				break;
			}
			else
			{
				idx=idx->left;
			}
		}
		else if(idx->data <putData)
		{
			if (idx->right ==NULL)
			{
				idx->right=get_tree_node(putData);
				//printf(" %d ",idx->right->data);
				break;
			}
			else
			{
				idx=idx->right;
			}
		}
		else	//idx->data == putData
		{
			printf("ERROR:: �ߺ��� ������ �����Ҽ� ���� : %d \n",idx->data);
			return NULL;
		}
	}

	return idx;
}

BiTreeNode* search_node(BiTreeNode** idxnode, int searchData)
{
	BiTreeNode* idx= *idxnode;

	if (idx== NULL)	//Ʈ���� �������..
	{
		printf("this tree is empty.. so doesn't exist such data : %d \n", searchData);
		return NULL;	//Ž����ҽ� NULL����
	}

	while(1)
	{
		if (idx->data>searchData)
		{
			if (idx->left != NULL)
			{
				idx=idx->left;
			}
			else
			{
				printf("error : this tree cannot found such data :: %d\n", searchData);
				return NULL;	//Ž������
			}
		}
		else if (idx->data<searchData)
		{
			if (idx->right != NULL)
			{
				idx=idx->right;
			}
			else
			{
				printf("error : this tree cannot found such data :: %d\n", searchData);
				return NULL;
			}
		}
		else //(idx->data == searchData)
		{
			printf("Ž�� ���� : %d \n", idx->data);
			return idx;
		}
	}
}

int get_node_count(BiTreeNode* node)
{
	if (node != NULL)
	{
		return 1+get_node_count(node->left)+get_node_count(node->right);
	}
	else return 0;
}

int get_leaf_node_count(BiTreeNode* node)
{
	if (node != NULL)	//��尡 null�� �ƴҶ� �� ��� ����
	{
		if ((node->left==NULL)&&(node->right==NULL))	//�Ѵ� �ڽ��� ������.. 1
			return 1;

		else	//�Ѵ� or �Ѵ� �ڽ��� ������ ���� ������ ��ȸ�Ͽ� �������� 1�� ���� ���� ������ŭ ���ϰ� �ȴ�
			return get_leaf_node_count(node->left)+get_leaf_node_count(node->right);
	}

	else return 0;	//node�� ���϶�..	//��� �������� ����
}


int get_height(BiTreeNode* node)
{
	if (node!=NULL)
	{
		return 1+max(get_height(node->left), get_height(node->right));
	}
	else
		return 0;
}

void delete_tree_node(BiTreeNode** node, int key)
{
	BiTreeNode* child = *node;
	BiTreeNode* parent = child;
	BiTreeNode* successor=NULL;
	BiTreeNode* p_successor=NULL;
	printf("key:%d\n",key);


	while((child != NULL)&&(child->data != key))	//������ ���� �� �θ��� ã��..
	{
		parent=child;
		if(child->data>key)	child=child->left;
		else child=child->right;
	}

	if (child == NULL)	//�� while������ Ž�� ����
	{
		printf("ERROR :: ���� �Ϸ��� �ϴ� data; %d �������� ����\n", key);
		return;
	}



	if ((child->left==NULL)&&(child->right==NULL))	//������尡 ���ܳ���϶�.. �θ����� �����̳� ������ null�� �ʱ�ȭ
	{
		if (parent==child)	//��Ʈ��� ���� �̰��� ��Ʈ����ε� ����, ������ �ڽ��� ���� ��� �̹Ƿ�, Ʈ���� ��尡 1���ΰ��
		{
			*node=NULL;
		}

		if(parent->left == child)	parent->left=NULL;
		else parent->right=NULL;
	}

	else if ((child->left !=NULL) && (child->right == NULL))	//��������� �����ڽ��� ������..	����� �����ڽ��̶� ���� or �θ���� �����ڽ� ����
	{
		if (child==parent)	//��Ʈ��� ����
		{
			*node=child->left;
		}

		if (parent->left==child)	parent->left=child->left;
		else	parent->right=child->left;	//����

	}

	else if ((child->left == NULL) && (child->right != NULL))	//��������� �����ʿ� �ڽ��� ������
	{
		if (parent == child)	//��Ʈ��� ����
		{
			*(node)=child->right;
		}

		if (parent->left==child)	parent->left=child->right;
		else	parent->right=child->right;
	}

	else
	{
		successor = child->left;
		p_successor=successor;

		while (successor->right !=NULL)
		{
			p_successor=successor;
			successor=successor->right;
		}

		if(parent == child)	//��Ʈ��� ����
		{
			if (p_successor == successor)	//��ȯ���� ����
			{
				successor->right=child->right;
			}
			else
			{
				p_successor->right=successor->left;
				successor->right=child->right;
				successor->left=child->left;
			}
			*node=successor;
		}


		else	//������尡 �ڽ��� 2���̰�, ��Ʈ��� �ƴҶ� ����
		{
			if (parent->right==child)
			{
				if (p_successor==successor)
				{
					successor->right=child->right;
					parent->right=successor;
					child->right=child->left=NULL;
				}
				else
				{
					p_successor->right=NULL;
					successor->right=child->right;
					successor->left=child->left;
					parent->right=successor;
				}
			}
			else
			{
				if (successor==p_successor)
				{
					parent->left=successor;
					successor->right=child->right;
				}
				else
				{
					p_successor->right=NULL;
					successor->left=child->left;
					successor->right=child->right;
					parent->left=successor;
				}
			}
		}

	}
	child->left=NULL;
	child->right=NULL;
	free(child);

}

void inorder(BiTreeNode* idx)
{
	if (idx !=NULL)
	{
		inorder(idx->left);
		inorder(idx->right);
	}
	else
		return;
}

BiTreeNode* min_tree_node(BiTreeNode* idx)
{
	while(idx->left !=NULL)	idx=idx->left;
	printf("Ʈ���� �ּҰ� : %d \n", idx->data);

	return idx;
}

BiTreeNode* max_tree_node(BiTreeNode* idx)
{
	while(idx->right !=NULL) idx=idx->right;
	printf("Ʈ���� �ִ밪 : %d \n", idx->data);

	return idx;
}

void free_tree_node(BiTreeNode* node)
{
	if (node !=NULL)
	{
		free_tree_node(node->left);
		free_tree_node(node->right);
		free(node);
	}
}
