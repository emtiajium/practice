class ExplainStatic {
      public static String name = "Look I am a static variable";
}

public class Application {
        public static void main(String[] args) {
            System.out.println(ExplainStatic.name);
            // main is a static method. Therefore, it only access to another static member
            // remove static from ExplainStatic class and see!
        }
}
