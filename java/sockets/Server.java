// Shamelessly taken from https://www.cs.uic.edu/~troy/spring05/cs450/sockets/socket.html
import java.net.*; 
import java.io.*; 

public class Server 
{ 
 public static void main(String[] args) throws IOException 
   { 
    ServerSocket serverSocket = null; 
    int port = 10007;
    try { 
         serverSocket = new ServerSocket(port); 
        } 
    catch (IOException e) 
        { 
         System.err.println("Could not listen on port: 10007."); 
         System.exit(1); 
        } 

    Socket clientSocket = null; 
    System.out.println ("Waiting for connection on port " + port + ".....");

    try { 
         clientSocket = serverSocket.accept(); 
        } 
    catch (IOException e) 
        { 
         System.err.println("Accept failed."); 
         System.exit(1); 
        } 

    System.out.println ("Connection successful");
    System.out.println ("Waiting for input.....");

    PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), 
                                      true); 
    BufferedReader in = new BufferedReader( 
            new InputStreamReader( clientSocket.getInputStream())); 

    String inputLine; 

    while ((inputLine = in.readLine()) != null) 
        { 
         System.out.println ("Server: " + inputLine); 
         out.println("Response: " + inputLine); 

         if (inputLine.equals("Bye.")) 
             break; 
        } 

    out.close(); 
    in.close(); 
    clientSocket.close(); 
    serverSocket.close(); 
   } 
} 
