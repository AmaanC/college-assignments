import java.io.*;

class BreakAndContinue {
    public static void main(String[] args) {
        for (int i = 0; i < 20; i++) {
            if (i % 3 == 0) {
                continue;
            }
            if (i > 10) {
                break;
            }
            System.out.println(i);
        }
    }
}