import java.util.Scanner;

public class failurefunction {
	public static void main(String[] args)
	{
		
		String a;
		int p;
		Scanner scan = new Scanner(System.in);
		
		p =scan.nextInt();
		//���ڿ��� ���������ֱ�
		
		a= scan.next();
		//a���� ���ڿ� �������ֱ�
		//for(int i=0; i<a.length(); i++)
			//System.out.println(a.charAt(i));
		int[] fail = new int[p];
		//System.out.println(fail.length);
		//�����Լ� ũ�� �����ֱ�;
	
		int i,j;
		//p=a.length();
		//System.out.println(p);
		fail[0] = -1;
		for(i=1; i<p; i++)
		{
			j = fail[i-1]+1;
			while(a.charAt(i) != a.charAt(j) && j>0)
			{
				j= fail[j-1] +1;
			}
			if(a.charAt(i) == a.charAt(j))
			{
				fail[i] = j;
			}
			else
			{
				fail[i] = -1;
			}
		}//�����Լ� ���ϱ�
		for(int k =0; k<a.length() ; k++)
		{
			System.out.printf("%d", fail[k]+1);
		}
	}
}
