import java.util.*;

class Reverse
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        String orgStr;
        String revStr = "";

        System.out.print("Enter String To Reverse --> ");
        orgStr = scan.nextLine();

        for (int i = orgStr.length() - 1; i >= 0; i--)
        {
            revStr = revStr.concat(String.valueOf(orgStr.charAt(i)));
        }

        System.out.println();
        System.out.println("Reversed String --> " + revStr);

        scan.close();
    }
}