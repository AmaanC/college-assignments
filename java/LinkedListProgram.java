import java.io.*;
import java.util.*;

class LinkedListProgram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice = -1;
        int END_CHOICE = 5;
        int val;
        LinkedList<Integer> l = new LinkedList<Integer>();

        while (choice < END_CHOICE) {
            System.out.println("Enter choice:\n1) Add element\n2) Remove element at index\n3) Print all\n4) Print size\n5) End");
            choice = sc.nextInt();
            switch(choice) {
                case 1:
                    System.out.println("Enter value: ");
                    val = sc.nextInt();
                    l.add(val);
                    break;
                case 2:
                    System.out.println("Enter index: ");
                    val = sc.nextInt();
                    l.remove(val);
                    break;
                case 3:
                    System.out.println(l);
                    break;
                case 4:
                    System.out.println("Size is: " + l.size());
                    break;
                case 5:
                    System.out.println("Exiting");
                    break;
            }
        }
    }
}