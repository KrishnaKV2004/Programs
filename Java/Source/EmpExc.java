import java.util.*;

class EmpDetails
{
    private int empId;
    private String empName;
    private int deptId;

    public EmpDetails(int empId, String empName, int deptId)
    {
        this.empId = empId;
        this.empName = empName;
        this.deptId = deptId;
    }

    public void display()
    {
        System.out.println("Employee ID --> " + empId);
        System.out.println("Employee Name --> " + empName);
        System.out.println("Department ID --> " + deptId);
    }
}

public class EmpExc
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        try
        {
            System.out.print("Enter Employee ID --> ");
            int empId = sc.nextInt();

            if (empId > 5001 || empId < 2001)
            {
                throw new RangeExp("ID Out Of Range !");
            }

            sc.nextLine();

            System.out.print("Enter Employee Name --> ");
            String empName = sc.nextLine();

            if (empName.charAt(0) < 'A' || empName.charAt(0) > 'Z')
            {
                throw new RangeExp("First Letter Should Be Capital !");
            }

            System.out.print("Enter Department ID --> ");
            int deptId = sc.nextInt();

            if (deptId < 1 || deptId > 5)
            {
                throw new RangeExp("Department Id Should Be Between 1 And 5 !");
            }

            EmpDetails em = new EmpDetails(empId, empName, deptId);
            System.out.println("\nDetails -->\n");
            em.display();
        }
        catch (RangeExp e)
        {
            System.out.println("Error --> " + e.getMessage());
        }
    }
}

class RangeExp extends Exception
{
    public RangeExp(String s)
    {
        super(s);
    }
}