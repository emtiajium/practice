import java.util.Scanner;
public class inoutput{
	public static void main(String args[]){
		Scanner input=new Scanner(System.in);
		int a,b,c;
		long p,q,r;
		double x,y,z;
		boolean bool;
		char ch;
		String str,str2;
		
		System.out.printf("Enter two integer value ");
		a=input.nextInt();
		b=input.nextInt();
		c=a+b;
		System.out.printf("Sum is %d\n",c);
		
		System.out.print("Enter two long value ");
		p=input.nextLong();
		q=input.nextLong();
		r=p+q;
		System.out.printf("Sum is %d\n",r);
		
		System.out.print("Enter two double value ");
		x=input.nextDouble();
		y=input.nextDouble();
		z=x+y;
		System.out.printf("Sum is %f\n",z);
		
		System.out.print("Enter boolean value ");
		bool=input.nextBoolean();// enter true or false
		System.out.printf("The value is %b\n",bool);
		
		ch=input.next().charAt(0);
		System.out.print("Enter character ");
		System.out.println("Char is "+ch);
		
		System.out.println("Enter string ");
		str=input.nextLine();
		System.out.println("String is "+str);
		System.out.println("Enter string ");
		str2=input.nextLine();// string with space, else input.next();
		System.out.println("String is "+str2);
	}
} 
