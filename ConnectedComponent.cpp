#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int nodes,edges;
int count=0;
int grid[101][1001];
//100개의노드와 100개의 엣지를 담을 수 있는 공간을 만든다. 
bool visited[101];
//내가 100개의 노드중에 방문한적 있는지 확인하는 vistied배열을 boolean값으로 정한다. 

void BFS(int s)//너비우선탐색이용. 
{
	count++;
	queue<int> q;
	q.push(s);
	//s값을 queue에 담는다. 
	visited[s]=true;
	//s는 한번 방문했다고 저장해둔다. 
	while(!q.empty())
	{
		int f=q.front();
		//Queue의 맨앞에 있는 시작노드 s로부터 인접해있는 모든 노드를 구한다. 
		q.pop();
		for(int i=1; i<=nodes; i++)
		{
			if(grid[f][i]&& visited[i]==false)
			{
				visited[i]=true;
				q.push(i);
			}//grid[f][i=0,1,2...],f와 연결된 모든 노드는 방문되었다고 설정한다. 
		}
		//s와 연결되어있는 모든 노드의 연결성분을 계산한다. 
	}
}
int main()
{
	cin>>nodes>>edges;
	for(int i=1; i<=edges; i++)
	{
		int startn,endn;
		cin>>startn>>endn;
		grid[startn][endn]=1;
		//ex)3->2랑 2->3는 무방향으로 연결되어 있기 떄문에 startn,endn값에 따라 양쪽다 설정이된다. 
		grid[endn][startn]=1;
	}
	
	for(int i=1; i<=nodes; i++)
	{
		if(visited[i]==false)
		//i번째가 탐색이 안된 노드가 있다면 다시시작함.
		//따라서 강력연결로된 연결그래프에서는 if문이 실행이 안된다. 
		{
			BFS(i);
		}
	}
	cout<<count;	
}



