import java.io.*;
import java.util.*;
import java.lang.reflect.*;

public class Reflection {
    public static void main(String[] args) {
        Method[] methodNames = LinkedList.class.getMethods();
        for (Method method : methodNames) {
            System.out.println("Method: " + method);
        }
    }
}