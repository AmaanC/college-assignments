import java.io.*;

class TooFewArgumentsException extends Exception {
    TooFewArgumentsException(String msg) {
        super("Custom: " + msg);
    }
}

class CustomException {
    public static void main(String[] args) {
        try {
            if (args.length <= 3) {
                throw new TooFewArgumentsException("Missing arguments");
            }
            System.out.println("Finished.");
        }
        catch (TooFewArgumentsException e) {
            System.out.println(e);
        }
    }
}