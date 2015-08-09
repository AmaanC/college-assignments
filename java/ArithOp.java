import java.io.*;
import java.util.*;

class ArithOp {
    public static void main(String[] args) {
        float i, j, result = 0;
        String op;
        Scanner s = new Scanner(System.in);

        System.out.println("Enter first number: ");
        i = Float.parseFloat(s.nextLine());
        System.out.println("Enter operation: ");
        op = s.nextLine();
        System.out.println("Enter second number: ");
        j = Float.parseFloat(s.nextLine());

        switch(op) {
            case "+":
                result = i + j;
                break;
            case "-":
                result = i - j;
                break;
            case "*":
                result = i * j;
                break;
            case "/":
                result = i / j;
                break;
            default:
                System.out.println("Operator must be one of: + - * /");
                return;
        }
        System.out.println("Result: " + result);
    }
}