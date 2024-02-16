import java.util.*;

class Palindrome
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        String orgStr;
        String revStr = "";

        System.out.println();
        System.out.print("Enter String 1 --> ");
        orgStr = scan.nextLine();

        for (int i = orgStr.length() - 1; i >= 0; i--)
        {
            revStr = revStr.concat(String.valueOf(orgStr.charAt(i)));
        }

        System.out.println();

        if (orgStr.equals(revStr))
        {
            System.out.println("String is a Palindrome!");
        } else
        {
            System.out.println("String is not a Palindrome!");
        }

        scan.close();
    }
}