#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#define N 30	//�����Ϸ��� �������� ���� or Ʈ������� ����

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

#endif
