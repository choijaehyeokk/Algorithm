import java.util.ArrayList;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class ShortPath {
	static int bfs(int start,int end,int node,ArrayList<ArrayList<Integer>> a)
	//너비우선탐색을 통해서 시작노드와 끝노드를 알때 그래프에 접근해서 시작노드부터 관련된 노드들을 전부검사해서 확인함
	{
		int[] dist =  new int[node];
		//일단 거리를 전부 -1로 setting해놓음
		for(int i=0; i<node; i++)
		{
			dist[i] = -1;
		}		
		Queue<Integer> q = new LinkedList<Integer>();
		//queue에 원소가 들어가있던 것이 나오면서 그노드를 확인했다고 체크할 것이다.그래서 큐를 사용
		dist[start] = 0;
		//시작노드는 거리가0 이라고생각
		q.offer(start);
		//처음것 큐에넣기
		boolean[] visit = new boolean[node];
		for(int i=0; i<node;i++)
		{
			visit[i] = false;
		}
		while(q.isEmpty() == false)
		//큐가 비어있지 않다면,즉 비어있으면 전부돈것임.
		{
			int curr = q.peek();
			//q에 맨앞에 것을 선택함. 즉 그노드를 확인할것임
			q.poll();
			visit[curr] = true;
			//맨처음것은 큐에 들어갓다가 나오면서 확인한 것으로 체크
			for(int i=0; i<a.get(curr).size(); i++)
			{//curr번쨰 노드의 arraylist사이즈만큼 i증가
				if(visit[a.get(curr).get(i)] != true)
				{
					//System.out.println(a.get(curr).size());
					int next = a.get(curr).get(i);
					if(dist[next] == -1);
					//아직 지나지 않았다면
					{
						dist[next] = dist[curr] +1;
						if(next == end)
						{
							return dist[next];
						}
						q.offer(next);
					}
				}
				//System.out.println("for 문에 들어갓음");
			}
	
			//System.out.println("while문에 들어갔음");
		}
		return 0;
		
	}
	public static void main(String args[])
	{
		int node;
		int edge;
		int start_node;
		int end_node;
		Scanner scan = new Scanner(System.in);
		node = scan.nextInt();
		edge = scan.nextInt();
		while(true)
		{
			if(node <= 100 && node>=2 && edge >=1 && edge<=5500)
			{
				break;
			}
			else
			{
				System.out.println("다시입력하세요");
				node = scan.nextInt();
				edge = scan.nextInt();
			}
		}
		boolean[] visit = new boolean[node];
		ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>(node);
		for (int i = 0; i < node; i++)
		{
            graph.add(new ArrayList<Integer>());
		}
		//arraylist안에 arraylist넣어서 선언
		start_node = scan.nextInt();
		end_node = scan.nextInt();
		//시작노드와 끝노드를 입력해 준다. 여기서 가장 짧은 거리를 구하면 된다.
		for(int i =0; i<edge; i++)
		{
			int node1= scan.nextInt();
			int node2 = scan.nextInt();
			//시작노드와 그 노드와 연결된 노드를 입력받는다.
			graph.get(node1).add(node2); 
	        graph.get(node2).add(node1); 
		}
		int dist =bfs(start_node,end_node,node,graph);
		System.out.println(dist);
	}
}
