import java.io.*;
import java.util.*;

class Armstrong {
	public static void main(String[] args) {
		int num, remNum, dig, result = 0;
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter number: ");
		num = sc.nextInt();
		remNum = num;

		while (remNum > 0) {
			dig = remNum % 10;
			result += dig * dig * dig;
			remNum /= 10;
		}
		System.out.println("Armstrong number: " + (result == num));
	}
}
