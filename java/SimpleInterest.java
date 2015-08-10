import java.io.*;
import java.util.*;

class SimpleInterest {
	public static void main(String[] args) {
		float p, n, r, si;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter principle amount: ");
		p = sc.nextFloat();
		System.out.println("Enter number of years: ");
		n = sc.nextFloat();
		System.out.println("Enter rate: ");
		r = sc.nextFloat();

		si = (p * n * r) / 100;

		System.out.println("Simple interest is: " + si);
	}
}
