import java.lang.reflect.Array;
import java.util.Scanner;

public class sorting {
	//sort�ؼ� ���ϴ� index�� ���� ã�Ƴ���
	static int selecting_sort(int[] array,int wantindex)
	{
		int result=0;
		int[] array_s = array;
		int min = 0;
		int index = wantindex-1;
		int a=0;
		for(int i=0; i<array_s.length-1; i++)
		{
			min = i;
			for(int j=i+1; j<array_s.length; j++)
			{
				if (array_s[min] > array_s[j])
					{
						a= array_s[min];
						array_s[min] = array_s[j];
						array_s[j] = a;
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
		findnumber = selecting_sort(array,index);
		System.out.println(findnumber);
	}
}
