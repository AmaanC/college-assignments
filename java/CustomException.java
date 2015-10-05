import java.io.*;

class TooFewArgumentsException extends Exception {
    TooFewArgumentsException(String msg) {
        super("Custom: " + msg);
    }
}

class CustomException {
    public static void main(String[] args) {
        try {
            throw new TooFewArgumentsException("Missing arguments");
        }
        catch (TooFewArgumentsException e) {
            System.out.println(e);
        }
    }
}