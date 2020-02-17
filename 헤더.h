#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#define N 30	//삽입하려는 데이터의 갯수 or 트리노드의 갯수

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

#endif
