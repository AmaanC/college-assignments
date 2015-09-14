/*
WAP to create vector objects with student names. Program should perform the following operations based on choice:
1) Add student name
2) Remove a student name if it exists; if not, display the apt message
3) Display all contents
*/
import java.io.*;
import java.util.*;

class VectorStudents {
    public static void main(String[] args) {
        int choice = 0;
        Scanner sc = new Scanner(System.in);
        Vector<String> students = new Vector<String>();
        String name;
        while (true) {
            System.out.println("");
            System.out.println("Enter choice:");
            System.out.println("1) Add student");
            System.out.println("2) Remove student");
            System.out.println("3) Display all students");
            System.out.println("4) Exit");
            choice = sc.nextInt();
            switch(choice) {
                case 1:
                    System.out.println("Enter name: ");
                    name = sc.next();
                    students.add(name);
                    break;
                case 2:
                    System.out.println("Enter name: ");
                    name = sc.next();
                    if (students.contains(name)) {
                        students.remove(name);
                        System.out.println("Student removed.");
                    }
                    else {
                        System.out.println("Student wasn't found.");
                    }
                    break;
                case 3:
                    System.out.println("List of all students:");
                    for(int i = 0; i < students.size(); i++) {
                        System.out.println(students.get(i));
                    }
                    System.out.println("");
                    break;
                default:
                    return;
            }
        }
    }
}