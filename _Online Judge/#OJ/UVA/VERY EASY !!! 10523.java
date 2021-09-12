import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		int N,A,i;
		BigInteger temp,prod,sum;
		while( input.hasNextInt() ){
			N=input.nextInt();
			A=input.nextInt();
			sum=new BigInteger("0");
			for(i=1;i<=N;i++){
				temp= BigInteger.valueOf(i);
				prod=temp.multiply(BigInteger.valueOf(A).pow(i));
				sum=sum.add(prod);
			}
			System.out.printf("%d\n",sum);
		}
	}
}
