import java.io.*;
import java.util.*;

class Student {
    int rollNo;
    String name;
    Scanner sc = new Scanner(System.in);
    void inputStudentDetails() {
        System.out.println("Enter roll no.");
        this.rollNo = sc.nextInt();
        System.out.println("Enter name:");
        this.name = sc.next();
    }
}

class TestGiver extends Student {
    int term1;
    int term2;
    void inputTestDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter term 1 marks:");
        this.term1 = sc.nextInt();
        System.out.println("Enter term 2 marks:");
        this.term2 = sc.nextInt();
    }
}

interface Sports {
    void playSports();
}

class GoodStudent extends TestGiver implements Sports {
    public void playSports() {
        System.out.println(this.name + " is playing sports");
    }

    void getData() {
        inputStudentDetails();
        inputTestDetails();
    }
}

class Interface {
    public static void main(String[] args) {
        GoodStudent g = new GoodStudent();
        g.getData();
        g.playSports();
    }
}