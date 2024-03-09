import java.util.Scanner;

class Employee
{
    private String name;
    private int empId;
    private String dept;

    public Employee(String name, int empId, String dept)
    {
        this.name = name;
        this.empId = empId;
        this.dept = dept;
    }

    public void printData()
    {
        System.out.println("Employee Name: " + name);
        System.out.println("Employee ID: " + empId);
        System.out.println("Department: " + dept);
    }
}

public class Employ
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of employees: ");
        int n = scanner.nextInt();

        if (n < 5)
        {
            System.out.println("Please enter a value greater than or equal to 5.");

            scanner.close();
            return;
        }

        Employee[] employees = new Employee[n];

        for (int i = 0; i < n; i++)
        {
            System.out.println("Enter details for employee " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.next();
            System.out.print("Employee ID: ");
            int empId = scanner.nextInt();
            System.out.print("Department: ");
            String dept = scanner.next();

            employees[i] = new Employee(name, empId, dept);
        }

        System.out.println("Employee details:");

        for (Employee employee : employees)
        {
            employee.printData();
        }

        scanner.close();
    }
}