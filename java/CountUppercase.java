import java.io.*;
import java.util.regex.*;

public class CountUppercase {
    public static void main(String[] args) {
        String abc = "The answer to everything? It's 42.";
        // We can create regular expressions like this for whatever kind of character we want to count
        Pattern upper = Pattern.compile("[A-Z]");
        Matcher mUpper = upper.matcher(abc);
        int i = 0;
        while (mUpper.find()) {
            i++;
        }
        System.out.println(i + " uppercase characters found");
    }
}