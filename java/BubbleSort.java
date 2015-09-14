import java.io.*;
import java.util.*;

class BubbleSort {
    int[] sort(int[] arr) {
        int temp;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = 0;
        System.out.println("Enter length of array: ");
        l = sc.nextInt();
        int a[] = new int[l];
        System.out.println("Enter elements: ");
        for (int i = 0; i < l; i++) {
            a[i] = sc.nextInt();
        }

        BubbleSort b = new BubbleSort();
        b.sort(a);
        System.out.println("Sorted array is:");
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
}