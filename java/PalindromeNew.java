import java.io.*;
import java.util.*;

class PalindromeNew {
    public static void main(String[] args) {
        String inp;
        Scanner sc = new Scanner(System.in);
        inp = sc.next();
        Boolean isPalindrome = true;
        int i = 0;
        int len = inp.length();

        while (i < len / 2) {
            if (inp.charAt(i) != inp.charAt(len - i - 1)) {
                isPalindrome = false;
                break;
            }
            i++;
        }

        System.out.println("Palindrome: " + isPalindrome);
    }
}