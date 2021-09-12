import java.util.Scanner;
import java.math.BigInteger;

public class Factorial{
	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		int num,i;
		BigInteger fact;
		num=input.nextInt();
		fact=new BigInteger("1");
		for(i=1;i<=num;i++){
			fact=fact.multiply(BigInteger.valueOf(i));
			System.out.printf("%d! = %d\n",i,fact);
		}
	}
}
