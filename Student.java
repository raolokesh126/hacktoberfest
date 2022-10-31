import java.util.Scanner; 
class Studentdetails
{
String name; int rollno , age; 
void input()
{
Scanner kb= new Scanner(System.in); 
System.out.println("Enter the name of student:");
name=kb.nextLine();
System.out.println("Enter the roll no of student:");
rollno=kb.nextInt();
System.out.println("Enter the age of the student:"); 
age=kb.nextInt();
}
}
class Student extends Studentdetails
{
void display()
{
System.out.println("Name : " +name);
System.out.println("Roll no: "+rollno); 
System.out.println("Age : " +age);
}
public static void main(String args[])
{
Student s=new Student();
s.input();
s.display();
}
}
