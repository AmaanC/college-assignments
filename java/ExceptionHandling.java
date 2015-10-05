import java.io.*;
import java.util.*;

class IncorrectTypeException extends Exception {

}

class ExceptionHandling {
    public static void main(String[] args) {
        int num;
        Scanner sc = new Scanner(System.in);
        try {
            num = sc.nextInt();
            if (num == 0) {
                throw new ArithmeticException();
            }
            System.out.println("Inverse is: " + 1.0 / num);
        }
        catch (InputMismatchException e) {
            System.out.println("Enter an integer!");
        }
        catch (ArithmeticException e) {
            System.out.println("Arithmetic exception!");
        }
    }
}