import java.math.BigInteger;
public class fibo{
	
	public static BigInteger fib(BigInteger n){
		if(n.compareTo(BigInteger.ZERO)==0 || n.compareTo(BigInteger.ONE)==0) return n;
		return fib(n.subtract(BigInteger.ONE)).add(fib(n.subtract(TWO)));
	}
	private static BigInteger TWO = BigInteger.valueOf(2);
	public static void main(String args[]){
		for(int i=0;i<21;i++){
			System.out.printf("Fib[%d] = %d\n",i,fib(BigInteger.valueOf(i)));
		}
	}
}