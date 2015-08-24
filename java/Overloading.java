import java.io.*;

class Overloading {
	int area(int side) {
		// It's a square
		return side*side;
	}
	int area(int length, int breadth) {
		// Rectangle
		return length*breadth;
	}

	public static void main(String[] args) {
		Overloading o = new Overloading();

		System.out.println("Area of square of side 5: " + o.area(5));
		System.out.println("Area of rectangle of l, b (5, 2): " + o.area(5, 2));
	}
}