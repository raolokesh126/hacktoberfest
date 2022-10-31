* Design a class named Car in package P1, having registration number, model and engine as its private members. Here engine is an object of a class called Engine in package P2 with the private members: chassis number and make. Define a suitable constructor of Car and override toString() method to print the details of a car. Assume appropriate data types for the instance members of the classes. Write a Java program to test the above class. */

import P1.*; // importing package P1
import P2.*; // importing package P2
import java.util.Scanner;  // importing Scanner class
class assign 
{
    public static void main(String args[]) // main() method
    {
        Scanner sc=new Scanner(System.in); // creating object of scanner class
        System.out.println("Please enter registration number : ");
        int reg=sc.nextInt();  // integer input for registration number
        System.out.println("Please enter Model number : ");
        String Model=sc.next();  // String  input for Model number
        System.out.println("Please enter Chasis number : ");
        int Chasis=sc.nextInt();  // integer input for Chasis number
        System.out.println("Please enter Make number : ");
        String Make=sc.next(); // String input for make
        Engine engine=new Engine();  // creating object of Engine class
        Car car1=new Car(reg,Model);   // creating object of Car class
        car1.toString(reg,Model);  // calling toString() method using car1 object
        engine.toString(Chasis,Make);  // calling toString() method using engine object
    }
}
