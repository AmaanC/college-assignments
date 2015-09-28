import java.io.*;
import tools.*;

class Use {
    public static void main(String[] args) {
        Factorial abc = new Factorial(5);
        System.out.println("Factorial of 5 is: " + abc.calc());
        System.out.println("Testing if 7 is prime: " + Prime.isPrime(7));
    }
}