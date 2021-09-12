import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int i,j,half;
		BigInteger pascal[][] = new BigInteger[205][205];
		pascal[0][0]=pascal[1][0]=pascal[1][1]= BigInteger.ONE;
		for(i=2;i<205;i++){
			pascal[i][0]= BigInteger.ONE;
			half=i>>1;
			for(j=1;j<=half;j++){
				pascal[i][j] = pascal[i-1][j-1].add(pascal[i-1][j]);
				pascal[i][i-j] = pascal[i][j];
			}
			pascal[i][i] = BigInteger.ONE;
		}
		for(i=0;i<205;i++){
			for(j=0;j<i;j++)
				System.out.printf("%d ",pascal[i][j]);
			System.out.printf("1\n");	
		}
	}
}
