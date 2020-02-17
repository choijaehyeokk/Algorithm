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

BiTreeNode* insert_tree_node(BiTreeNode**, int);//이진트리에 노드 삽입해주는 함수
BiTreeNode* get_tree_node(int);					//노드 생성해주는 함수
BiTreeNode* search_node(BiTreeNode**, int);		//이진트리내 key값을 가진 노드의 값을 탐색
int get_node_count(BiTreeNode*);				//이진트리의 총 노드의 수 리턴
int get_leaf_node_count(BiTreeNode*);			//이진트리의 말단 노드수 리턴
int get_height(BiTreeNode*);					//이진트리의 높이 알려주는 함수
int max_val(int, int);							//이진트리 높이 알려줄때, 왼쪽 오른쪽 자식 중 큰값 알려주는 함수
void delete_tree_node(BiTreeNode**, int);		//이진트리내 key값을 가진 노드 삭제
void inorder(BiTreeNode*);						//이진트리내 모든 노드의 데이터 출력
BiTreeNode* max_tree_node(BiTreeNode*);			//이진트리내 최대값을 가진 데이터알려주고 노드 주소 리턴
BiTreeNode* min_tree_node(BiTreeNode*);			//이진트리내 최소값을 가진 데이터 알려주고 노드 주소 리턴
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
	printf("이진트리의 총 노드의 갯수 :: %d\n", node_count);
	
	leaf_node=get_leaf_node_count(tree_head);
	printf("이진트리의 말단노드의 총갯수 :: %d\n", leaf_node);

	tree_height=get_height(tree_head);
	printf("이진트리의 높이 : %d\n", tree_height);

	delete_tree_node(&tree_head, rand()%50+1);
	delete_tree_node(&tree_head, num);
		delete_tree_node(&tree_head, rand()%50+1);
	
	inorder(tree_head);

	node_count=get_node_count(tree_head);
	printf("이진트리의 총 노드의 갯수 :: %d\n", node_count);
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
	if ((*root) == NULL)	//트리가 비었을때
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
			printf("ERROR:: 중복된 데이터 삽입할수 없음 : %d \n",idx->data);
			return NULL;
		}
	}

	return idx;
}

BiTreeNode* search_node(BiTreeNode** idxnode, int searchData)
{
	BiTreeNode* idx= *idxnode;

	if (idx== NULL)	//트리가 비었을때..
	{
		printf("this tree is empty.. so doesn't exist such data : %d \n", searchData);
		return NULL;	//탐색취소시 NULL리턴
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
				return NULL;	//탐색실패
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
			printf("탐색 성공 : %d \n", idx->data);
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
	if (node != NULL)	//노드가 null이 아닐때 즉 노드 존재
	{
		if ((node->left==NULL)&&(node->right==NULL))	//둘다 자식이 없을때.. 1
			return 1;

		else	//둘다 or 둘다 자식이 있을때 왼쪽 오른쪽 순회하여 마지막엔 1이 남아 말단 노드수만큼 더하게 된다
			return get_leaf_node_count(node->left)+get_leaf_node_count(node->right);
	}

	else return 0;	//node가 널일때..	//노드 존재하지 않음
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


	while((child != NULL)&&(child->data != key))	//삭제할 노드와 그 부모노드 찾기..
	{
		parent=child;
		if(child->data>key)	child=child->left;
		else child=child->right;
	}

	if (child == NULL)	//위 while문에서 탐색 실패
	{
		printf("ERROR :: 삭제 하려고 하는 data; %d 존재하지 않음\n", key);
		return;
	}



	if ((child->left==NULL)&&(child->right==NULL))	//삭제노드가 말단노드일때.. 부모노드의 왼쪽이나 오른쪽 null로 초기화
	{
		if (parent==child)	//루트노드 삭제 이경우는 루트노드인데 왼쪽, 오른쪽 자식이 없는 경우 이므로, 트리에 노드가 1개인경우
		{
			*node=NULL;
		}

		if(parent->left == child)	parent->left=NULL;
		else parent->right=NULL;
	}

	else if ((child->left !=NULL) && (child->right == NULL))	//삭제노드의 왼쪽자식이 있을때..	헤더랑 왼쪽자식이랑 연결 or 부모노드랑 왼쪽자식 연결
	{
		if (child==parent)	//루트노드 삭제
		{
			*node=child->left;
		}

		if (parent->left==child)	parent->left=child->left;
		else	parent->right=child->left;	//왼쪽

	}

	else if ((child->left == NULL) && (child->right != NULL))	//삭제노드의 오른쪽에 자식이 있을때
	{
		if (parent == child)	//루트노드 삭제
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

		if(parent == child)	//루트노드 삭제
		{
			if (p_successor == successor)	//순환하지 않음
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


		else	//삭제노드가 자식이 2개이고, 루트노드 아닐때 삭제
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
	printf("트리내 최소값 : %d \n", idx->data);

	return idx;
}

BiTreeNode* max_tree_node(BiTreeNode* idx)
{
	while(idx->right !=NULL) idx=idx->right;
	printf("트리내 최대값 : %d \n", idx->data);

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
