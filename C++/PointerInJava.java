class AClass {
	public int a;
	public void output() {
		System.out.println ( a );
	}
}

public class PointerInJava {
	public static void main (String[] args)	 {
		AClass object = new AClass();
		AClass object2 = new AClass();
		object.a = 5;
		System.out.println(object + "\n" + object2); // object's "identity hashcode" /  reference ID
		// http://stackoverflow.com/questions/20735132/
		object2 = object;
		object2.a = 15;
		object.output();
		System.out.println(object + "\n" + object2); 
	}
}
