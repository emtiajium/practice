import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author
 * sabbir
 */
public class Main {
    
    static private final String INPUT = "input.txt";
    static private final String OUTPUT = "output.txt";
    
    //function should throw exception/ioexception, else need try/catch block
    public static void main(String args[]) throws Exception
    {
        //redirect system.in and system.out to file, comment if not required
        System.setIn(new FileInputStream(INPUT));
        System.setOut(new PrintStream(new FileOutputStream(OUTPUT)));

        //code here
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int x = in.nextInt();
            System.out.println(x);
        }
    }
}
