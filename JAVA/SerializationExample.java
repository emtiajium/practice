import java.io.*;

public class SerializationExample implements Serializable {
	
	private int width;
	private int height;
	
	public SerializationExample (int width, int height) {
		this.width = width;
		this.height = height;
	}
	
	public int getWidth () {
		return width;
	}
	
	public int getHeight () {
		return height;
	}
	
	public static void main (String[] args) {
	
		SerializationExample myBox = new SerializationExample(12, 14);
		
		try {
			FileOutputStream fOS = new FileOutputStream("foo.ser");
			ObjectOutputStream oOS = new ObjectOutputStream(fOS);
			oOS.writeObject(myBox);
			oOS.close();
		} 
		
		catch(Exception ex) {
			ex.printStackTrace();
		}
		
		myBox = null;
		
		try {
			FileInputStream fIs = new FileInputStream("foo.ser");
			ObjectInputStream oIS = new ObjectInputStream(fIs);
			Object one = oIS.readObject();
			SerializationExample oneRestore = (SerializationExample) one;
			System.out.printf("Height %d Width %d\n", oneRestore.getHeight(), oneRestore.getWidth());
			oIS.close();
		} 
		
		catch(Exception ex) {
			ex.printStackTrace();
		}
	}
}
