import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		int cases=0,item,friend,i;
		BigInteger bill,sum,avg;
		while(true){
			item=input.nextInt();
			friend=input.nextInt();
			if(item==0 && friend==0) break;
			sum= BigInteger.ZERO;
			for(i=0;i<item;i++){
				bill = input.nextBigInteger();
				sum=sum.add(bill);
			}
			avg=sum.divide(BigInteger.valueOf(friend));
			System.out.printf("Bill #%d costs %d: each friend should pay %d\n\n",++cases,sum,avg);
		}
	}
}