import java.util.*;

class String_Concat
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        String str1;
        String str2;

        System.out.print("String 1 --> ");
        str1 = scan.nextLine();

        System.out.print("String 2 --> ");
        str2 = scan.nextLine();

        String result = str1 + " " +str2;

        System.out.println();
        System.out.println("Concatinated String --> " + result);

        scan.close();
    }
}