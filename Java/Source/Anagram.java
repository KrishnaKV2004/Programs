import java.util.Arrays;
import java.util.Scanner;

class Anagram
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        String str1;
        String str2;

        System.out.print("Enter String 1 --> ");
        str1 = scan.nextLine();
        System.out.print("Enter String 2 --> ");
        str2 = scan.nextLine();

        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();

        Arrays.sort(arr1);
        Arrays.sort(arr2);

        String sortedStr1 = new String(arr1);
        String sortedStr2 = new String(arr2);

        System.out.println();

        if (sortedStr1.equals(sortedStr2))
        {
            System.out.println("Strings are Anagrams !");
        }
        else
        {
            System.out.println("Strings are Not Anagrams !");
        }

        scan.close();
    }
}