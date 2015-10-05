import java.io.*;

abstract class Tools {
    abstract float area(int r);
}

class Circle extends Tools {
    float area(int r) {
        return 3.14 * r * r;
    }
}

class Rect extends Tools {
    float area(int a, int b) {
        return a * b * 1.0;
    }
}

class OverridingNew {
    public static void main(String[] args) {
        Circle c = new Circle();
        Rect r = new Rect();
        System.out.println("Circle's area is: " + c.area(5));
        System.out.println("Rectangle's area is: " + r.area(5, 3));
    }
}