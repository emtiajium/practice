class StringCheck
{
    public static void main(String[] n)
    {
        String s1=new String("abc");
        String s2="abc";
        String s3="abc";
        if(s1==s2)
            System.out.println("s1==s2");
        if(s1==s3)
            System.out.println("s1==s3");
        if(s2==s3)
            System.out.println("s2==s3");
    }
}
