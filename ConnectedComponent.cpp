#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int nodes,edges;
int count=0;
int grid[101][1001];
//100���ǳ��� 100���� ������ ���� �� �ִ� ������ �����. 
bool visited[101];
//���� 100���� ����߿� �湮���� �ִ��� Ȯ���ϴ� vistied�迭�� boolean������ ���Ѵ�. 

void BFS(int s)//�ʺ�켱Ž���̿�. 
{
	count++;
	queue<int> q;
	q.push(s);
	//s���� queue�� ��´�. 
	visited[s]=true;
	//s�� �ѹ� �湮�ߴٰ� �����صд�. 
	while(!q.empty())
	{
		int f=q.front();
		//Queue�� �Ǿտ� �ִ� ���۳�� s�κ��� �������ִ� ��� ��带 ���Ѵ�. 
		q.pop();
		for(int i=1; i<=nodes; i++)
		{
			if(grid[f][i]&& visited[i]==false)
			{
				visited[i]=true;
				q.push(i);
			}//grid[f][i=0,1,2...],f�� ����� ��� ���� �湮�Ǿ��ٰ� �����Ѵ�. 
		}
		//s�� ����Ǿ��ִ� ��� ����� ���Ἲ���� ����Ѵ�. 
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
		//ex)3->2�� 2->3�� ���������� ����Ǿ� �ֱ� ������ startn,endn���� ���� ���ʴ� �����̵ȴ�. 
		grid[endn][startn]=1;
	}
	
	for(int i=1; i<=nodes; i++)
	{
		if(visited[i]==false)
		//i��°�� Ž���� �ȵ� ��尡 �ִٸ� �ٽý�����.
		//���� ���¿���ε� ����׷��������� if���� ������ �ȵȴ�. 
		{
			BFS(i);
		}
	}
	cout<<count;	
}



