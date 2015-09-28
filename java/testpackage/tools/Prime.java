package tools;
public class Prime {
    public static boolean isPrime(int n) {
        int i = 2;
        for (i = 2; i < Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};