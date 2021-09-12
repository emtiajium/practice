import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		int n,i;
		BigInteger prod,prod2,cata;
		while(input.hasNextInt()){
			n=input.nextInt();
			prod=new BigInteger("1");
			prod2=new BigInteger("1");
			for(i=2;i<=n;i++){
				prod=prod.multiply(BigInteger.valueOf(n).add(BigInteger.valueOf(i)));
				prod2=prod2.multiply(BigInteger.valueOf(i));
			}
			cata=prod.divide(prod2);
			System.out.printf("%d\n",cata);
		}
	}
}
