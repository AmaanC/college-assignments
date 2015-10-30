import java.io.*;

class LoopThread extends Thread {
    int n = 5;
    LoopThread(int n) {
        this.n = n;
    }
    public void run() {
        for (int i = 0; i < n; i++) {
            System.out.println("Thread " + i);
        }
    }
}

class Multithreading {
    public static void main(String[] args) {
        LoopThread t1 = new LoopThread(8);
        LoopThread t2 = new LoopThread(10);
        LoopThread t3 = new LoopThread(5);
        t1.start();
        t2.start();
        t3.start();
    }
}