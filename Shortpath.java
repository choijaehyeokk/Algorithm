import java.util.ArrayList;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class ShortPath {
	static int bfs(int start,int end,int node,ArrayList<ArrayList<Integer>> a)
	//�ʺ�켱Ž���� ���ؼ� ���۳��� ����带 �˶� �׷����� �����ؼ� ���۳����� ���õ� ������ ���ΰ˻��ؼ� Ȯ����
	{
		int[] dist =  new int[node];
		//�ϴ� �Ÿ��� ���� -1�� setting�س���
		for(int i=0; i<node; i++)
		{
			dist[i] = -1;
		}		
		Queue<Integer> q = new LinkedList<Integer>();
		//queue�� ���Ұ� ���ִ� ���� �����鼭 �׳�带 Ȯ���ߴٰ� üũ�� ���̴�.�׷��� ť�� ���
		dist[start] = 0;
		//���۳��� �Ÿ���0 �̶�����
		q.offer(start);
		//ó���� ť���ֱ�
		boolean[] visit = new boolean[node];
		for(int i=0; i<node;i++)
		{
			visit[i] = false;
		}
		while(q.isEmpty() == false)
		//ť�� ������� �ʴٸ�,�� ��������� ���ε�����.
		{
			int curr = q.peek();
			//q�� �Ǿտ� ���� ������. �� �׳�带 Ȯ���Ұ���
			q.poll();
			visit[curr] = true;
			//��ó������ ť�� ���ٰ� �����鼭 Ȯ���� ������ üũ
			for(int i=0; i<a.get(curr).size(); i++)
			{//curr���� ����� arraylist�����ŭ i����
				if(visit[a.get(curr).get(i)] != true)
				{
					//System.out.println(a.get(curr).size());
					int next = a.get(curr).get(i);
					if(dist[next] == -1);
					//���� ������ �ʾҴٸ�
					{
						dist[next] = dist[curr] +1;
						if(next == end)
						{
							return dist[next];
						}
						q.offer(next);
					}
				}
				//System.out.println("for ���� ����");
			}
	
			//System.out.println("while���� ����");
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
				System.out.println("�ٽ��Է��ϼ���");
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
		//arraylist�ȿ� arraylist�־ ����
		start_node = scan.nextInt();
		end_node = scan.nextInt();
		//���۳��� ����带 �Է��� �ش�. ���⼭ ���� ª�� �Ÿ��� ���ϸ� �ȴ�.
		for(int i =0; i<edge; i++)
		{
			int node1= scan.nextInt();
			int node2 = scan.nextInt();
			//���۳��� �� ���� ����� ��带 �Է¹޴´�.
			graph.get(node1).add(node2); 
	        graph.get(node2).add(node1); 
		}
		int dist =bfs(start_node,end_node,node,graph);
		System.out.println(dist);
	}
}
