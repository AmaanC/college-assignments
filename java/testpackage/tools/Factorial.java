package tools;
public class Factorial {
    int val = 1;
    public Factorial(int num) {
        this.val = num;
    }
    public int calc() {
        int ret = 1;
        int i = 1;
        while (i <= this.val) {
            ret *= i;
            i++;
        }
        return ret;
    }
};