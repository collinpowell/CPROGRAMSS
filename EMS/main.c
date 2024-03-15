#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

typedef unsigned short us;
// Creating an Employee Structure
typedef struct EmployeeT
{
    int id;
    char name[20];
    char department[20];
    char position[20];
    double salary;
} Employee;

int totalEmployees = 3;

// Creating an Employee Array
Employee employees[SIZE];

void testData()
{
    Employee e1 = {543, "Collins", "HR", "HR", 234};
    employees[0] = e1;
    employees[1] = e1;
    employees[2] = e1;

    employees[1].id = 234;
    employees[2].id = 456;
}

int randomNumber(int N)
{
    srand(time(NULL));
    int num;

    do
    {
        num = rand() % N;
    } while (num < 100);
    return num;
}

int main()
{
    testData();
    printf("Employee Management System\n\n");

    us option;

    do
    {
        // Display Menu
        printf("\nSelect an option:\n");
        printf("1. Add a new employee.\n");
        printf("2. Update existing employee information.\n");
        printf("3. Delete an employee.\n");
        printf("4. Display the list of all employees.\n");
        printf("5. Exit the program.\n");

        printf("Input an option: ");
        scanf("%d", &option);
        system("cls");
        switch (option)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            updateEmployeeInfo();
            break;
        case 3:
            deleteEmployee();
            break;
        case 4:
            displayEmployees();
            break;
        default:
            if (option != 5)
            {
                printf("\nInvalid Input, Select from the menu\n");
            }
        }
        // clear screen
        // system("cls");
    } while (option != 5);

    printf("\nProgram Exited Successfully!!");

    return 1;
}

void addEmployee()
{
    Employee emp;

    printf("Input Employee Name: ");
    scanf("%s", emp.name);

    printf("Input Employee Department: ");
    scanf("%s", emp.department);

    printf("Input Employee Position: ");
    scanf("%s", emp.position);

    printf("Input Employee Salary: ");
    scanf("%lf", &emp.salary);

    emp.id = randomNumber(1000);
    employees[totalEmployees] = emp;
    totalEmployees++;

    printf("Employee Added Successfully!!\n");
}

int updateEmployeeInfo()
{
    int employeeId;

    printf("Input ID of Employee to be updated: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < totalEmployees; i++)
    {
        if (employees[i].id == employeeId)
        {
            Employee emp = employees[i];
            us option;
            printf("\nEmployee ID: %d\n", employeeId);
            do
            {
                printf("\nEmployee ID: %d\n", employeeId);
                // Display Menu
                printf("\nSelect an option:\n");
                printf("1. Update Name.\n");
                printf("2. Update Department.\n");
                printf("3. Update Position.\n");
                printf("4. Update Salary.\n");
                printf("5. Cancel.\n");
                printf("Input Option: ");
                scanf("%d", &option);
                system("cls");
                switch (option)
                {
                case 1:
                    printf("Input Employee Name: ");
                    scanf("%s", emp.name);
                    // fgets(emp.name, 20, stdin);
                    printf("Name Updated Successfully");
                    break;
                case 2:
                    printf("Input Employee Department: ");
                    scanf("%s", emp.department);
                    printf("Department Updated Successfully");
                    break;
                case 3:
                    printf("Input Employee Position: ");
                    scanf("%s", emp.position);
                    printf("Position Updated Successfully");
                    break;
                case 4:
                    printf("Input Employee Salary: ");
                    scanf("%lf", &emp.salary);
                    printf("Salary Updated Successfully");
                    break;
                default:
                    if (option != 5)
                    {
                        printf("\nInvalid Input, Select from the menu\n");
                    }
                }
            } while (option != 5);
            printf("Employee ID: %d\n", employeeId);
            employees[employeeId] = emp;
            return 1;
        }
    }
    printf("Id does not Exist\n\n");
    return 0;
}

int deleteEmployee()
{
    int employeeId;

    printf("Input ID of Employee to be Deleted: ");
    scanf("%d", &employeeId);

    for (int i = 0; i < totalEmployees; i++)
    {
        if (employees[i].id == employeeId)
        {
            for (int j = i; j < (totalEmployees - 1); j++)
            {
                employees[j] = employees[j + 1];
            }
            totalEmployees--;
            printf("Employee Deleted Successfully!!");
            return 1;
        }
    }
    printf("Employee Not Found!!");
    return 0;
}

void displayEmployees()
{
    printf("All Employee List: \n\n");
    for (int i = 0; i < totalEmployees; i++)
    {
        printf("ID: %d  Name: %s  Position: %s Department: %s  Salary:%lf\n", employees[i].id, employees[i].name, employees[i].position, employees[i].department, employees[i].salary);
    }
}