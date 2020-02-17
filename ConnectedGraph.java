import java.util.Scanner;
import java.util.ArrayList;

public class ConnectionGraph {
	

	public static void main(String args[])
	{
		int node;
		int edge;
		//노드의 갯수와 엣지의 갯수 노드는 기본적으로 0이 처음이라고 가정한다.
		Scanner scan = new Scanner(System.in);
	   /*3 2
	  	 0 1
  		 1 2*/
		//System.out.println("노드 엣지");

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
		//System.out.println(node + " " + edge);
		ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>(node);
		int[] count = new int[node];
		//Graph를 input으로 받은 노드의 갯수만큼 크기를 잡고 ArrayList를 담은 ArrayList를 만든다.
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
			//시작노드와 그 노드와 연결된 노드를 입력받는다.
			graph.get(start_node).add(end_node); 
	        graph.get(end_node).add(start_node); 
		}
		//ArrayList에 모든 노드에 대해서 값이 하나라도 존재한다면 이 그래프는 연결그래프 일 것이다.
        for (int i = 0; i < graph.size(); i++) 
        { 
            for (int j = 0; j < graph.get(i).size(); j++) 
            { 
                count[(graph).get(i).get(j)] = 1;
            }
        }
        //모든 그래프의 성분을 읽어들인다음 노드에 값이 있다면, 그 노드와 인덱스를 맞춰서 배열에 1이라고 flag해 놓는다.
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
        //flag한 값들이 전부 1이라면 즉 total==node라면 연결된 그래프일 것이다. 하지만 그렇지 않다면 연결이 안되어 있을 것이다.
	}
}
