import java.util.*;

class Scan
{
	public static void main(String[] args)
	{
		String name;
		int roll;
		String department;
		String university;
		double [] marks = new double[5];

		Scanner scan = new Scanner(System.in);

		System.out.println();
		System.out.print("Student Name --> ");
		name = scan.nextLine();

		System.out.print("Roll Number --> ");
		roll = scan.nextInt();
		scan.nextLine();
		
		System.out.print("Department --> ");
		department = scan.nextLine();
		
		System.out.print("University --> ");
		university = scan.nextLine();
		System.out.println();
		
		for (int i=0; i<5; i++)
		{
			System.out.print("Marks In Subject " +i+1 + " --> ");
			marks[i] = scan.nextInt();
		}

		double 
		perc = ((marks[0] + marks[1] + marks[2] + marks[3] + marks[4])/500)*100;

		System.out.println();
		System.out.println("Student Info ---->");
		System.out.println();
		
		System.out.println("Name : " + name);
		System.out.println("Roll No : " + roll);
		System.out.println("Department : " + department);
		System.out.println("University : " + university);
		System.out.println("Marks : " +marks[0] + " " +marks[1] + " " +marks[2] + " " +marks[3] + " " +marks[4]);

		System.out.println("Percentage : " + perc + " %");

		scan.close();
	}
}