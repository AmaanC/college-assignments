import java.io.*;

class Fib {
	public static void main(String[] args) {
		int n = 5;
		int i = 0;
		int num1, num2, temp;
		num1 = 1;
		num2 = 1;

		if (args.length >= 1) {
			n = Integer.parseInt(args[0]);
		}

		while (i < n) {
			System.out.println(num2 + ", ");
			temp = num2;
			num2 += num1;
			num1 = temp;

			i++;
		}
	}
}
