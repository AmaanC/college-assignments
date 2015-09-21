import java.io.*;

class Parent {
    void walk() {
        System.out.println("Parent walking");
    }
}

class ChildRegular extends Parent {
    void talk() {
        System.out.println("Talking");
    }
}

class ChildSpecial extends Parent {
    void walk() {
        System.out.println("Child walking");
    }
}

class Overriding {

    public static void main(String[] args) {
        ChildRegular cr = new ChildRegular();
        ChildSpecial cs = new ChildSpecial();

        cr.walk();
        cs.walk();
    }
}