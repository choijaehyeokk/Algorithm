import java.util.Scanner;
import java.util.ArrayList;

public class ConnectionGraph {
	

	public static void main(String args[])
	{
		int node;
		int edge;
		//����� ������ ������ ���� ���� �⺻������ 0�� ó���̶�� �����Ѵ�.
		Scanner scan = new Scanner(System.in);
	   /*3 2
	  	 0 1
  		 1 2*/
		//System.out.println("��� ����");

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
		//System.out.println(node + " " + edge);
		ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>(node);
		int[] count = new int[node];
		//Graph�� input���� ���� ����� ������ŭ ũ�⸦ ��� ArrayList�� ���� ArrayList�� �����.
		//System.out.println(node);
		//System.out.println(edge);
		for (int i = 0; i < node; i++)
		{
            graph.add(new ArrayList<Integer>());
		}
        for(int i =0; i<edge; i++)
		{
			int start_node= scan.nextInt();
			int end_node = scan.nextInt();
			//���۳��� �� ���� ����� ��带 �Է¹޴´�.
			graph.get(start_node).add(end_node); 
	        graph.get(end_node).add(start_node); 
		}
		//ArrayList�� ��� ��忡 ���ؼ� ���� �ϳ��� �����Ѵٸ� �� �׷����� ����׷��� �� ���̴�.
        for (int i = 0; i < graph.size(); i++) 
        { 
            for (int j = 0; j < graph.get(i).size(); j++) 
            { 
                count[(graph).get(i).get(j)] = 1;
            }
        }
        //��� �׷����� ������ �о���δ��� ��忡 ���� �ִٸ�, �� ���� �ε����� ���缭 �迭�� 1�̶�� flag�� ���´�.
        int total=0;
        for (int index=0; index<count.length;index++)
        {
        	total = total+count[index];
        }
        if(total == node)
        {
        	System.out.println(1);
        }
        else
        {
        	System.out.println(0);
        }
        //flag�� ������ ���� 1�̶�� �� total==node��� ����� �׷����� ���̴�. ������ �׷��� �ʴٸ� ������ �ȵǾ� ���� ���̴�.
	}
}
