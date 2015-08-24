import java.io.*;
import java.util.*;

class Palindrome {
    public static void main(String[] args) {
        String inp;
        Scanner sc = new Scanner(System.in);
        inp = sc.next();
        String rev = "";

        for (int i = inp.length() - 1; i >= 0; i--) {
            rev += inp.charAt(i);
        }

        System.out.println("Reverse is: " + rev);
        System.out.println("Palindrome: " + rev.equals(inp));
    }
}