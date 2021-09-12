import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		int t;
		BigInteger p,q,GCD;
		t=input.nextInt();
		while(t-->0){
			p = input.nextBigInteger();
            input.next();
            q = input.nextBigInteger();
			GCD=p.gcd(q);
			p=p.divide(GCD);
			q=q.divide(GCD);
			System.out.printf("%d / %d\n",p,q);
		}
	}
}