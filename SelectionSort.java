import java.lang.reflect.Array;
import java.util.Scanner;

public class sorting {
	//sort해서 원하는 index의 값을 찾아내기
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
		//배열의 길이 설정
		while(true)
		{
			size = scan.nextInt();
			if(size >=2 && size <1000)
			{
				array = new int[size];
				break;
			}
		}
		//index입력
		index = scan.nextInt();
		//System.out.println(size + " " + index);
		
		//System.out.println("숫자들을 입력하세요: ");
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
