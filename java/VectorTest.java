import java.io.*;
import java.util.*;

class VectorTest {
    public static void main(String[] args) {
        Vector a = new Vector();
        Vector b = new Vector(1, 5);
        Enumeration ex = b.elements();

        a.add(1);
        System.out.println("A: ");
        System.out.println("Size:" + a.size());
        System.out.println("Capacity:" + a.capacity());
        
        System.out.println("B: ");
        b.addElement(new Integer(1));

        System.out.println("Size:" + b.size());
        System.out.println("Capacity:" + b.capacity());
        b.addElement(new Boolean(true));
        System.out.println("Size:" + b.size());
        System.out.println("Capacity:" + b.capacity());


        System.out.println("First elem:");
        System.out.println(b.firstElement());
        System.out.println("Last elem:");
        System.out.println(b.lastElement());

        System.out.println("Enumeration:");
        while (ex.hasMoreElements()) {
            System.out.println(ex.nextElement());
        }
    }
}