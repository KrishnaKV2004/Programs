package Java;

class CLA_Sum
{
	public static void main(String args[])
	{
		int sum = 0;

		for (int i=0; i<args.length; i++)
		{
			sum = sum + Integer.parseInt(args[i]);
		}

		System.out.println("Hello Java");
		System.out.println("Sum of CLA is " + sum);
	}
}
