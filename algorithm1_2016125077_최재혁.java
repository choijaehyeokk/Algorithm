import java.lang.reflect.Array;
import java.util.Scanner;

public class sorting {
	//sort�ؼ� ���ϴ� index�� ���� ã�Ƴ���
	static int sort_select(int[] array,int wantindex)
	{
		int result=0;
		int[] array_s = array;
		int index = wantindex-1;
		int a=0;
		for(int i=0; i<array_s.length-1; i++)
		{
			for(int j=0; j<array_s.length-i-1; j++)
			{
				if (array_s[j] > array_s[j+1])
					{
						a= array_s[j];
						array_s[j] = array_s[j+1];
						array_s[j+1] = a;
					}
			}
		}
		/*for(int i= 0; i< array_s.length; i++)
		{
			System.out.println(array_s[i]);
		}*/
		
		result = array_s[index];
		return result;		
	}
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int[] array;
		int size;
		int index;
		int numbers;
		int findnumber;
		//�迭�� ���� ����
		while(true)
		{
			size = scan.nextInt();
			if(size >=2 && size <1000)
			{
				array = new int[size];
				break;
			}
		}
		//index�Է�
		index = scan.nextInt();
		//System.out.println(size + " " + index);
		
		//System.out.println("���ڵ��� �Է��ϼ���: ");
		for(int i= 0; i< array.length; i++)
		{
			numbers = scan.nextInt();
			array[i] = numbers;
		}
		/*for(int i= 0; i< array.length; i++)
		{
			System.out.print(array[i]);
		}*/
		findnumber = sort_select(array,index);
		System.out.println(findnumber);
	}
}
